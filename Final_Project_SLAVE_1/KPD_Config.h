/*****************************************************************************************/
/*                 AUTHOR :  Aya Ibrahim Meghawry                                       */
/*                 DATA   :  Jan 5, 2024                                                    */
/*                 TITLE  :  KeyPad Configuration                                   */
/*****************************************************************************************/
#ifndef KPD_CONFIG_H
#define KPD_CONFIG_H


#define NOTPRESSED 			0xFF

/*
                          C0   C1  C2  C3
u8 KPD_u8Buttons[4][4] = { {'7','8','9','/'},  Row0
						   {'4','5','6','*'},  Row1
						   {'1','2','3','-'},  Row2
						   {'?','0','=','+'}   Row3 };*/

#define KPD_u8Buttons               {{1,2,3,4},{5,6,7,8},{9,10,11,12},{13,14,15,16}}

#define   KPD_ROWS_PORT     PORTD_ID
#define   KPD_COLS_PORT     PORTD_ID


#define   KPD_R1            PIN0
#define   KPD_R2            PIN1
#define   KPD_R3            PIN2
#define   KPD_R4            PIN3


#define   KPD_C1            PIN4
#define   KPD_C2            PIN5
#define   KPD_C3            PIN6
#define   KPD_C4            PIN7

#endif
