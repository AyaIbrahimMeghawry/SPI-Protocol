/*****************************************************************************************/
/*                 AUTHOR :  Aya Ibrahim Meghawry                                       */
/*                 DATA   :  Dec 28, 2023                                                    */
/*                 TITLE  :  LCD Interface                                   */
/*****************************************************************************************/
#ifndef LCD_INTERFCAE_H
#define LCD_INTERFCAE_H

/**************************************************************/
#define   CLEAR_LCD                      0X01
#define   RETURN_HOME_LCD                0X02
#define   DISPLAY_OFF_LCD                0X08
#define   DISPLAY_ON_LCD_CursorOFF       0X0c
#define   DISPLAY_ON_LCD_CursorON        0X0e
#define   FOUR_BITS                      0X28
#define   EIGHT_BITS                     0x38
#define   ENTRY_MODE_LCD                 0X06
#define   FIRST_ROW                      0X80
#define   SECOND_ROW                     0XC0
#define   THIRD_ROW                      0X94
#define   FOURTH_ROW                     0XD4
#define   CGRAM_ADD                      0X40
/**************************************************************/
#define  CLCD_ROW1            1
#define  CLCD_ROW2            2

#define  CLCD_COL_1           1
#define  CLCD_COL_2           2
#define  CLCD_COL_3           3
#define  CLCD_COL_4           4
#define  CLCD_COL_5           5
#define  CLCD_COL_6           6
#define  CLCD_COL_7           7
#define  CLCD_COL_8           8
#define  CLCD_COL_9           9
#define  CLCD_COL_10          10
#define  CLCD_COL_11          11
#define  CLCD_COL_12          12
#define  CLCD_COL_13          13
#define  CLCD_COL_14          14
#define  CLCD_COL_15          15
#define  CLCD_COL_16          16

/**************************************************************/
void CLCD_voidInit(void);
void CLCD_vSendCommand(u8 Copy_u8Cmd);
void CLCD_vSendData(u8 Copy_u8Data);
void CLCD_vClearScreen(void);
void CLCD_vSendString(const u8 *Copy_u8ptrSting);
void CLCD_vSetPostion (u8 Copy_u8Row , u8 Copy_u8Col);


#endif
