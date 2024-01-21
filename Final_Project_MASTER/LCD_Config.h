/*****************************************************************************************/
/*                 AUTHOR :  Aya Ibrahim Meghawry                                       */
/*                 DATA   :  Dec 28, 2023                                                    */
/*                 TITLE  :  LCD configuration                                  */
/*****************************************************************************************/
#ifndef LCD_CONFIG_H
#define LCD_CONFIG_H

#define  RS    PIN1
#define  EN    PIN2
#define  D4    PIN3
#define  D5    PIN4
#define  D6    PIN5
#define  D7    PIN6
/*
#define  RS    PIN2
#define  RW    PIN1
#define  EN    PIN0


#define  D0    PIN7
#define  D1    PIN6
#define  D2    PIN5
#define  D3    PIN4

#define  D4    PIN3
#define  D5    PIN2
#define  D6    PIN1
#define  D7    PIN0
*/




/*
 * option :
 * 1- 8 bit mode
 * 2- 4 bit mode
 * */
#define CLCD_Mode                 4

#define CLCD_Data_Port          PORTA_ID
#define CLCD_Control_port       PORTA_ID


#endif
