/* 
 * File:   led.h
 * Author: mahmo
 *
 * Created on December 18, 2023, 9:22 PM
 */

#ifndef LED_H
#define	LED_H

/* Section : Includes */
#include"../../MCAL/DIO_Driver/dio.h"
/* Section : Macro Declarations */
/*  Section : Macro Functions Declarations */
/* Section : Data Type Declarations */
/* Section : Function Declarations */
Std_ReturnType led_init(uint8_t pinNum,uint8_t port);
Std_ReturnType led_on(uint8_t pinNum,uint8_t port);
Std_ReturnType led_off(uint8_t pinNum,uint8_t port);
Std_ReturnType led_toggel(uint8_t pinNum,uint8_t port);

#endif	/* LED_H */

