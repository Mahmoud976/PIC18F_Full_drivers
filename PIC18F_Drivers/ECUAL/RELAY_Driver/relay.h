/* 
 * File:   relay.h
 * Author: mahmo
 *
 * Created on March 27, 2023, 3:24 PM
 */

#ifndef RELAY_H
#define	RELAY_H
/* Section : Includes */
#include"relay_cfg.h"
#include"../../MCAL/DIO_Driver/dio.h"
/* Section : Macro Declarations */
#define RELAY_ENABLE    relay_enable
#define RELAY_DISABLE   relay_disable

/*  Section : Macro Functions Declarations */

/* Section : Data Type Declarations */

/* Section : Function Declarations */
Std_ReturnType relay_init(uint8_t pinNum ,uint8_t port);
Std_ReturnType relay_on(uint8_t pinNum ,uint8_t port);
Std_ReturnType relay_off(uint8_t pinNum ,uint8_t port);


#endif	/* RELAY_H */

