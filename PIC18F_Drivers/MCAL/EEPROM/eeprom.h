/* 
 * File:   eeprom.h
 * Author: mahmoud saleh
 *
 * Created on April 14, 2023, 8:48 PM
 */

#ifndef EEPROM_H
#define	EEPROM_H
/************** Section : Includes*************************** */
#include"../../Utilities/Registers/registers.h"


/* *******************Section : Macro Declarations *******************************/
#define NOP()     __nop()
#define BIT_MASK                    (uint8_t)0x01
#define SET_BIT(REG,BIT_POSN)       (REG |= (BIT_MASK << BIT_POSN))
#define CLEAR_BIT(REG,BIT_POSN)     (REG &= ~(BIT_MASK << BIT_POSN))
#define READ_BIT(REG,BIT_POSN)      ((REG >> BIT_POSN)& BIT_MASK)

/********************Section : Macro Functions Declarations ******************** */


/******************* Section : Data Type Declarations ****************************/


/******************** Section : Function Declarations ****************************/

Std_ReturnType Data_EEPROM_WriteByte(uint16_t bAdd,uint8_t bData);
Std_ReturnType Data_EEPROM_Read_Byte(uint16_t bAdd,uint8_t *bData);


#endif	/* EEPROM_H */

