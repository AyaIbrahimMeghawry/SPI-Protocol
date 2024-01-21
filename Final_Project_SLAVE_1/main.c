/*
 * main.c
 *
 *  Created on: Jan 3, 2024
 *      Author: Aya Ibrahim Meghawry
 */
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "DIO_interface.h"
#include "KPD_Interface.h"
#include "SPI_Interface.h"
#include <util/delay.h>

/************SLAVE 1****************************/
int main()
{
	u8 ret;

	DIO_voidSetPinDirection(PORTB_ID, PIN5, PIN_INPUT);  //MOSI
	DIO_voidSetPinDirection(PORTB_ID, PIN6, PIN_OUTPUT); //MISO
	DIO_voidSetPinDirection(PORTB_ID, PIN7, PIN_INPUT);  //SCK
	DIO_voidSetPinDirection(PORTB_ID, PIN4, PIN_INPUT);  //SS

	SPI_voidSlaveInit();
	KPD_vInit();

	while (1)
	{
		do
		{
			ret = KPD_u8GetPressed();
			SPI_u8Tranceive(ret);
			_delay_ms(10);
		}
		while (ret = 0xFF);

	}
	return 0;
}
