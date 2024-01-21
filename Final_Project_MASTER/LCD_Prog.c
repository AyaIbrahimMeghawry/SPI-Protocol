/*****************************************************************************************/
/*                 AUTHOR :  Aya Ibrahim Meghawry                                       */
/*                 DATA   :  Dec 28, 2023                                                    */
/*                 TITLE  :  LCD Driver Implementation                                   */
/*****************************************************************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "DIO_interface.h"
#include <util/delay.h>
#include "LCD_Interface.h"
#include "LCD_Private.h"
#include "LCD_Config.h"

static void CLCD_WriteData_InBus(u8 Copy_u8Data)
{
	DIO_voidSetPinValue(CLCD_Data_Port,D4, GET_BIT(Copy_u8Data, 4));
	DIO_voidSetPinValue(CLCD_Data_Port,D5, GET_BIT(Copy_u8Data, 5));
	DIO_voidSetPinValue(CLCD_Data_Port,D6, GET_BIT(Copy_u8Data, 6));
	DIO_voidSetPinValue(CLCD_Data_Port,D7, GET_BIT(Copy_u8Data, 7));
}
void CLCD_vClearScreen(void)
{
	CLCD_vSendCommand(CLEAR_LCD);
	_delay_ms(15);
}

void CLCD_voidInit(void)
{
#if CLCD_Mode == 8

	_delay_ms(50);

	DIO_voidSetPortDirection(CLCD_Data_Port,ALL_PORT_OUTPUT);
	DIO_voidSetPinDirection(CLCD_Control_port,RS,PIN_OUTPUT);
	DIO_voidSetPinDirection(CLCD_Control_port,RW,PIN_OUTPUT);
	DIO_voidSetPinDirection(CLCD_Control_port,EN,PIN_OUTPUT);

	CLCD_vSendCommand(RETURN_HOME_LCD);
	_delay_ms(1);

	CLCD_vSendCommand(EIGHT_BITS);
	_delay_ms(1);

	CLCD_vSendCommand(DISPLAY_ON_LCD_CursorOFF);
	_delay_ms(1);

	CLCD_vClearScreen();

	CLCD_vSendCommand(ENTRY_MODE_LCD);
	_delay_ms(1);

#elif CLCD_Mode == 4

	_delay_ms(50);
	DIO_voidSetPinDirection(CLCD_Data_Port,D4,PIN_OUTPUT);
	DIO_voidSetPinDirection(CLCD_Data_Port,D5,PIN_OUTPUT);
	DIO_voidSetPinDirection(CLCD_Data_Port,D6,PIN_OUTPUT);
	DIO_voidSetPinDirection(CLCD_Data_Port,D7,PIN_OUTPUT);

	DIO_voidSetPinDirection(CLCD_Control_port, RS, PIN_OUTPUT);
	//DIO_voidSetPinDirection(CLCD_Control_port, RW, PIN_OUTPUT);
	DIO_voidSetPinDirection(CLCD_Control_port, EN, PIN_OUTPUT);

	CLCD_vSendCommand(RETURN_HOME_LCD);
	_delay_ms(15);

	CLCD_vSendCommand(FOUR_BITS);
	_delay_ms(2);

	CLCD_vSendCommand(DISPLAY_ON_LCD_CursorOFF);
	_delay_ms(2);

	CLCD_vClearScreen();

	CLCD_vSendCommand(ENTRY_MODE_LCD);
	_delay_ms(2);

#endif
}

void CLCD_vSendCommand(u8 Copy_u8Cmd)
{
	u8 Local_u8Command =Copy_u8Cmd ;
/************** 8 bit mode ********************************/
#if CLCD_Mode == 8
	DIO_voidSetPortValue(CLCD_Data_Port, Copy_u8Cmd);
	/*Set RS pin to low for command*/
	DIO_voidSetPinValue(CLCD_Control_port,RS,PIN_LOW);
	/*set RW pin to low to Write*/
	DIO_voidSetPinValue(CLCD_Control_port,RW ,PIN_LOW);

	CLCD_voidSendFallingEdge();

/************** 4 bit mode ********************************/
#elif CLCD_Mode == 4

	CLCD_WriteData_InBus(Local_u8Command);
	/*Set RS pin to low for command*/
	DIO_voidSetPinValue(CLCD_Control_port, RS, PIN_LOW);
	/*set RW pin to low to Write*/
	//DIO_voidSetPinValue(CLCD_Control_port, RW, PIN_LOW);

	CLCD_voidSendFallingEdge();
	Local_u8Command = Copy_u8Cmd<<4 ;

	CLCD_WriteData_InBus(Local_u8Command);

	CLCD_voidSendFallingEdge();
#endif
	_delay_ms(1);
}

void CLCD_vSendData(u8 Copy_u8Data)
{
	u8 Local_u8Data =Copy_u8Data;
/************** 8 bit mode ********************************/
#if CLCD_Mode == 8
	DIO_voidSetPortValue(CLCD_Data_Port, Copy_u8Data);
	/*Set RS pin to low for Data*/
	DIO_voidSetPinValue(CLCD_Control_port, RS, PIN_HIGH);
	/*set RW pin to low to Write*/
	DIO_voidSetPinValue(CLCD_Control_port, RW, PIN_LOW);
	CLCD_voidSendFallingEdge();

/************** 4 bit mode ********************************/
#elif CLCD_Mode == 4
	CLCD_WriteData_InBus(Local_u8Data);

	/*Set RS pin to low for Data*/
	DIO_voidSetPinValue(CLCD_Control_port,RS, PIN_HIGH);
	/*set RW pin to low to Write*/
	//DIO_voidSetPinValue(CLCD_Control_port,RW, PIN_LOW);

	CLCD_voidSendFallingEdge();

	Local_u8Data = Copy_u8Data <<4;
	CLCD_WriteData_InBus(Local_u8Data);

	CLCD_voidSendFallingEdge();
#endif
	_delay_ms(1);
}

void CLCD_vSendString(const u8 *Copy_u8ptrSting)
{
	u8 Local_u8Counter =0;
	while(Copy_u8ptrSting[Local_u8Counter] != '\0')
	{
		CLCD_vSendData(Copy_u8ptrSting[Local_u8Counter]);
		Local_u8Counter ++;
	}
}

void CLCD_vSetPostion (u8 Copy_u8Row , u8 Copy_u8Col)
{
	u8 Local_u8Data;
	if(Copy_u8Row >2||Copy_u8Row<1||Copy_u8Col>16||Copy_u8Col<1)
	{
		Local_u8Data =FIRST_ROW;
	}
	else if (Copy_u8Row == CLCD_ROW1)
	{
		Local_u8Data =(FIRST_ROW +(Copy_u8Col-1));
	}
	else if (Copy_u8Row ==CLCD_ROW2)
	{
		Local_u8Data =(SECOND_ROW +(Copy_u8Col -1));
	}
	CLCD_vSendCommand(Local_u8Data);
	_delay_ms(1);
}

static void CLCD_voidSendFallingEdge(void)
{
	DIO_voidSetPinValue(CLCD_Control_port,EN, PIN_HIGH);
	_delay_ms(2);
	DIO_voidSetPinValue(CLCD_Control_port,EN, PIN_LOW);
	_delay_ms(2);
}

