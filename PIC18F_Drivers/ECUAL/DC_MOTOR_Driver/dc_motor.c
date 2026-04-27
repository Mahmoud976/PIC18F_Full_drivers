#include"dc_motor.h"

#if DC_MOTOR_ENABLE

Std_ReturnType dc_motor_init(uint8_t pin1,uint8_t port1,uint8_t pin2,uint8_t port2){
    if(dio_pin_direction_initialize(pin1,port1,DIO_OUTPUT)&&
        dio_pin_direction_initialize(pin2,port2,DIO_OUTPUT))return E_OK;
    return E_NOT_OK;
}

Std_ReturnType dc_motor_forward(uint8_t pin1,uint8_t port1,uint8_t pin2,uint8_t port2){
    if(dio_pin_write_logic(pin1,port1,DIO_HIGH)&&
        dio_pin_write_logic(pin2,port2,DIO_LOW)
            )return E_OK;
    return E_NOT_OK;
}

Std_ReturnType dc_motor_backward(uint8_t pin1,uint8_t port1,uint8_t pin2,uint8_t port2){
    if(dio_pin_write_logic(pin1,port1,DIO_LOW)&&
       dio_pin_write_logic(pin2,port2,DIO_HIGH)     
            )return E_OK;
    return E_NOT_OK;
}

Std_ReturnType dc_motor_stop(uint8_t pin1,uint8_t port1,uint8_t pin2,uint8_t port2){
    if(dio_pin_write_logic(pin1,port1,DIO_LOW)&&
       dio_pin_write_logic(pin2,port2,DIO_LOW)     
            )return E_OK;
    return E_NOT_OK;
}


/*************************************************************************/

Std_ReturnType dc_motor_init_(uint8_t pin1,uint8_t pin2,uint8_t port){
       if(dio_pin_direction_initialize(pin1,port,DIO_OUTPUT)&&
        dio_pin_direction_initialize(pin2,port,DIO_OUTPUT))return E_OK;
    return E_NOT_OK;
}
Std_ReturnType dc_motor_forward_(uint8_t pin1,uint8_t pin2,uint8_t port){
    if(dio_pin_write_logic(pin1,port,DIO_HIGH)&&
        dio_pin_write_logic(pin2,port,DIO_LOW)
            )return E_OK;
    return E_NOT_OK;
}
Std_ReturnType dc_motor_backward_(uint8_t pin1,uint8_t pin2,uint8_t port){
    if(dio_pin_write_logic(pin1,port,DIO_LOW)&&
       dio_pin_write_logic(pin2,port,DIO_HIGH)     
            )return E_OK;
    return E_NOT_OK;
}
Std_ReturnType dc_motor_stop_(uint8_t pin1,uint8_t pin2,uint8_t port){
    if(dio_pin_write_logic(pin1,port,DIO_LOW)&&
       dio_pin_write_logic(pin2,port,DIO_LOW)     
            )return E_OK;
    return E_NOT_OK;
}

#endif
