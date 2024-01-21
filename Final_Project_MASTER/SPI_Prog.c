/*****************************************************************************************/
/*                 AUTHOR :  Aya Ibrahim Meghawry                                       */
/*                 DATA   :  Dec 30, 2023                                                    */
/*                 TITLE  :  SPI Implementation                                   */
/*****************************************************************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "SPI_Interface.h"
#include "SPI_Private.h"
#include "SPI_Config.h"




void SPI_voidMasterInit(void)
{
	/*Set To Be Master bti4*/
		SET_BIT(SPCR, SPCR_MSTR);

	/*Set The MSB to be sent first Bit5*/
		CLR_BIT(SPCR, SPCR_DORD);

	/*Clock Prescaler, divide by 16 bit 0 , 1 and bit 0 */
		SET_BIT(SPCR, SPCR_SPR0);
		CLR_BIT(SPCR, SPCR_SPR1);
		CLR_BIT(SPSR, SPSR_SPI2X);

	/*Set The Leading Edge To be The Rising Edge bit 3*/
		CLR_BIT(SPCR, SPCR_CPOL);

	/*Setup At Leading Edge Bit2*/
		SET_BIT(SPCR, SPCR_CPHA);

	/*Enable The SPI set bit 6*/
		SET_BIT(SPCR, SPCR_SPE);

}
void SPI_voidSlaveInit(void)
{
	/*Set To Be Salve clear bti4 */
		CLR_BIT(SPCR, SPCR_MSTR);

	/*Set The MSB to be sent first Bit5*/
		CLR_BIT(SPCR, SPCR_DORD);

	/*Set The Leading Edge To be The Rising Edge bit 3*/
		CLR_BIT(SPCR, SPCR_CPOL);

	/*Setup At Leading Edge bit 2*/
		SET_BIT(SPCR, SPCR_CPHA);

	/*Enable The SPI bit 6*/
		SET_BIT(SPCR, SPCR_SPE);
}

u8 SPI_u8Tranceive(u8 Copy_u8Data)
{
	/*Set The Data in SPDR Register To Send*/
		SPDR = Copy_u8Data;

		/*Polling (Busy Waiting) until the transfer complete*/
		while(GET_BIT(SPSR, SPSR_SPIF) == 0);

		/*Clear The Flag*/
		//SET_BIT(SPSR, SPSR_SPIF);

		/*Get The Exchanged Data*/
		return SPDR;
}
