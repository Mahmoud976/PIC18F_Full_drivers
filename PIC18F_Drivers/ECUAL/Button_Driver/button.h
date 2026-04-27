/* 
 * File:   button.h
 * Author: mahmo
 *
 * Created on March 27, 2023, 1:09 AM
 */

#ifndef BUTTON_H
#define	BUTTON_H

/* Section : Includes */
#include"btn_cfg.h"
#include"../../MCAL/DIO_Driver/dio.h"

/* Section : Macro Declarations */

#define BUTTON_ENABLE   btn_Enable
#define BUTTON_DISABLE  btn_Disable

/*  Section : Macro Functions Declarations */

/* Section : Data Type Declarations */

typedef enum{
    BUTTON_RELEASED=0,
    BUTTON_PRESSED,
}button_state_t;

typedef enum{
    BUTTON_ACTIVE_HIGH=0,
    BUTTON_ACTIVE_LOW
}button_active_t;


/* Section : Function Declarations */

Std_ReturnType button_init(uint8_t pinNum,uint8_t port);

Std_ReturnType button_read(uint8_t pinNum,uint8_t port,button_active_t connection,button_state_t * status);


#endif	/* BUTTON_H */

