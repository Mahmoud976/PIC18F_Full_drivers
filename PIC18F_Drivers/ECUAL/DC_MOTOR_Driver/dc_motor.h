/* 
 * File:   dc_motor.h
 * Author: mahmo
 *
 * Created on March 27, 2023, 7:07 PM
 */

#ifndef DC_MOTOR_H
#define	DC_MOTOR_H

/* Section : Includes */
#include"dc_motor_cfg.h"
#include"../../MCAL/DIO_Driver/dio.h"

/* Section : Macro Declarations */
#define DC_MOTOR_ENABLE    dc_motor_enable
#define DC_MOTOR_DISABLE   dc_motor_disable

/*  Section : Macro Functions Declarations */

/* Section : Data Type Declarations */

/* Section : Function Declarations */
Std_ReturnType dc_motor_init(uint8_t pin1,uint8_t port1,uint8_t pin2,uint8_t port2);
Std_ReturnType dc_motor_forward(uint8_t pin1,uint8_t port1,uint8_t pin2,uint8_t port2);
Std_ReturnType dc_motor_backward(uint8_t pin1,uint8_t port1,uint8_t pin2,uint8_t port2);
Std_ReturnType dc_motor_stop(uint8_t pin1,uint8_t port1,uint8_t pin2,uint8_t port2);


Std_ReturnType dc_motor_init_(uint8_t pin1,uint8_t pin2,uint8_t port);
Std_ReturnType dc_motor_forward_(uint8_t pin1,uint8_t pin2,uint8_t port);
Std_ReturnType dc_motor_backward_(uint8_t pin1,uint8_t pin2,uint8_t port);
Std_ReturnType dc_motor_stop_(uint8_t pin1,uint8_t pin2,uint8_t port);

#endif	/* DC_MOTOR_H */

