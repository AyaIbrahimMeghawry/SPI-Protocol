/*****************************************************************************************/
/*                 AUTHOR :  Aya Ibrahim Meghawry                                       */
/*                 DATA   :  Jan 5, 2024                                                    */
/*                 TITLE  :  KeyPad Implementation                                   */
/*****************************************************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "DIO_interface.h"
#include <util/delay.h>
#include "KPD_Interface.h"
#include "KPD_Private.h"
#include "KPD_Config.h"

void KPD_vInit(void)
{
	/* connect pull up for the pins of the rows*/
	DIO_voidSetPinDirection(KPD_ROWS_PORT ,KPD_R1,PIN_INPUT);
	DIO_voidSetPinDirection(KPD_ROWS_PORT ,KPD_R2,PIN_INPUT);
	DIO_voidSetPinDirection(KPD_ROWS_PORT ,KPD_R3,PIN_INPUT);
	DIO_voidSetPinDirection(KPD_ROWS_PORT ,KPD_R4,PIN_INPUT);

	DIO_voidSetPinValue(KPD_ROWS_PORT ,KPD_R1,PIN_HIGH);
	DIO_voidSetPinValue(KPD_ROWS_PORT ,KPD_R2,PIN_HIGH);
	DIO_voidSetPinValue(KPD_ROWS_PORT ,KPD_R3,PIN_HIGH);
	DIO_voidSetPinValue(KPD_ROWS_PORT ,KPD_R4,PIN_HIGH);

	/* connect the pins of the columns as output pins (HIGH)*/
	DIO_voidSetPinDirection(KPD_COLS_PORT ,KPD_C1 ,PIN_OUTPUT);
	DIO_voidSetPinDirection(KPD_COLS_PORT ,KPD_C2 ,PIN_OUTPUT);
	DIO_voidSetPinDirection(KPD_COLS_PORT ,KPD_C3 ,PIN_OUTPUT);
	DIO_voidSetPinDirection(KPD_COLS_PORT ,KPD_C4 ,PIN_OUTPUT);

	DIO_voidSetPinValue(KPD_COLS_PORT ,KPD_C1 ,PIN_HIGH);
	DIO_voidSetPinValue(KPD_COLS_PORT ,KPD_C2 ,PIN_HIGH);
	DIO_voidSetPinValue(KPD_COLS_PORT ,KPD_C3 ,PIN_HIGH);
	DIO_voidSetPinValue(KPD_COLS_PORT ,KPD_C4 ,PIN_HIGH);

}

u8 KPD_u8GetPressed(void)
{
	u8 Local_u8PressedKey =NOTPRESSED ;
	static u8 Local_u8KPDArr[ROW_NUM][COLUMN_NUM]=KPD_u8Buttons ;
	u8 Local_u8COl ;
	u8 Local_u8Row ;
	static u8 Local_u8KPD_ColsArr[COLUMN_NUM]={KPD_C1,KPD_C2,KPD_C3,KPD_C4};
	static u8 Local_u8KPD_RowsArr[ROW_NUM]={KPD_R1,KPD_R2,KPD_R3,KPD_R4};
	u8 Local_u8PinState;

	for(Local_u8COl =0;Local_u8COl <COLUMN_NUM ;Local_u8COl ++)
	{
		/*Activate current column*/
		DIO_voidSetPinValue(KPD_COLS_PORT ,Local_u8KPD_ColsArr[Local_u8COl],PIN_LOW);
		for(Local_u8Row =0;Local_u8Row<ROW_NUM ;Local_u8Row++)
		{
			/*Read the current Row*/
			Local_u8PinState =DIO_u8GetPinValue(KPD_ROWS_PORT,Local_u8KPD_RowsArr[Local_u8Row]);

			/*check if switch is pressed*/
			if (PIN_LOW == Local_u8PinState)
			{
				Local_u8PressedKey =Local_u8KPDArr[Local_u8Row][Local_u8COl];
				/*Polling (busy waiting )until the key is released*/
				while(PIN_LOW == Local_u8PinState)
				{
					Local_u8PinState =DIO_u8GetPinValue(KPD_ROWS_PORT,Local_u8KPD_RowsArr[Local_u8Row]);
				}
				return Local_u8PressedKey;
			}
		}
		/*Deactivate current column*/
	   DIO_voidSetPinValue(KPD_COLS_PORT ,Local_u8KPD_ColsArr[Local_u8COl],PIN_HIGH);
	}

	return Local_u8PressedKey;
}
