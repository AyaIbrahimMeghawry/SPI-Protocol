/*
 * main.c
 *
 *  Created on: Dec 28, 2023
 *      Author: Aya Ibrahim Meghawry
 */
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "DIO_interface.h"
#include "LCD_Interface.h"
#include "SPI_Interface.h"
#include <util/delay.h>

/************MASTER****************************/
int main()
{
	u8 ret ;
	DIO_voidSetPinDirection(PORTB_ID, PIN5, PIN_OUTPUT); //MOSI
	DIO_voidSetPinDirection(PORTB_ID, PIN6, PIN_INPUT);  //MISO
	DIO_voidSetPinDirection(PORTB_ID, PIN7, PIN_OUTPUT); //SCK
	DIO_voidSetPinDirection(PORTB_ID, PIN4, PIN_INPUT);  //SS "use it as GPIO pin"

	DIO_voidSetPinDirection(PORTB_ID, PIN4, PIN_HIGH); //Slave Select

	DIO_voidSetPinDirection(PORTB_ID,PIN0,PIN_OUTPUT); //Right Motor
	DIO_voidSetPinDirection(PORTB_ID,PIN1,PIN_OUTPUT); //Left Motor
	SPI_voidMasterInit();
	CLCD_voidInit();

	CLCD_vSendString("WELCOME");
	while(1)
	{
		ret =SPI_u8Tranceive(6);
		switch (ret)
		{
		case 1 :
			DIO_voidSetPinValue(PORTB_ID,PIN0,PIN_HIGH); // Turn on Right Motor
			DIO_voidSetPinValue(PORTB_ID,PIN1,PIN_HIGH); // Turn on Left Motor
			CLCD_vClearScreen();
			CLCD_vSendString("Both Motors ON");
			break;
		case 2 :
			DIO_voidSetPinValue(PORTB_ID,PIN0,PIN_HIGH); // Turn on Right Motor
			DIO_voidSetPinValue(PORTB_ID,PIN1,PIN_LOW); // Turn OFF Left Motor
			CLCD_vClearScreen();
			CLCD_vSendString("Right Motor ON");
			break ;
		case 3 :
			DIO_voidSetPinValue(PORTB_ID,PIN1,PIN_HIGH); // Turn on Left Motor
			DIO_voidSetPinValue(PORTB_ID,PIN0,PIN_LOW); // Turn OFF Right Motor
			CLCD_vClearScreen();
			CLCD_vSendString("Left Motor ON");
			break;
		case 5 :
			DIO_voidSetPinValue(PORTB_ID, PIN0, PIN_LOW); // Turn on Right Motor
			DIO_voidSetPinValue(PORTB_ID, PIN1, PIN_LOW); // Turn on Left Motor
			CLCD_vClearScreen();
			CLCD_vSendString("Both Motors OFF");
			break ;
		default :
			/*nothing*/
			break;
		}
		_delay_ms(10);
	}
	return 0;
}
