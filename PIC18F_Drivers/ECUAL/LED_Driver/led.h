/* 
 * File:   led.h
 * Author: mahmo
 *
 * Created on March 25, 2023, 11:36 PM
 */

#ifndef LED_H
#define	LED_H
/* Section : Includes */
#include"../../MCAL/DIO_Driver/dio.h"
#include"led_cfg.h"    
/* Section : Macro Declarations */
#define LED_ENABLE    led_enable
#define LED_DISABLE   led_disable
/*  Section : Macro Functions Declarations */

/* Section : Data Type Declarations */

/* Section : Function Declarations */
Std_ReturnType led_init(uint8_t pinNum ,uint8_t port);
Std_ReturnType led_on(uint8_t pinNum ,uint8_t port);
Std_ReturnType led_off(uint8_t pinNum ,uint8_t port);
Std_ReturnType led_toggle(uint8_t pinNum ,uint8_t port);
#endif	/* LED_H */

