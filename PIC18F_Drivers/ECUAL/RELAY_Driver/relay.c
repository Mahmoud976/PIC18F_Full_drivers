#include"relay.h"

#if RELAY_ENABLE
Std_ReturnType relay_init(uint8_t pinNum ,uint8_t port){
    Std_ReturnType ret=E_NOT_OK;
    if(dio_pin_direction_initialize(pinNum,port,DIO_OUTPUT)){ret=E_OK ; return ret;} 
    return ret;
}
Std_ReturnType relay_on(uint8_t pinNum ,uint8_t port){
    Std_ReturnType ret=E_NOT_OK;
    if(dio_pin_write_logic(pinNum,port,DIO_HIGH)){ret=E_OK ; return ret;} 
    return ret;
}
Std_ReturnType relay_off(uint8_t pinNum ,uint8_t port){
    Std_ReturnType ret=E_NOT_OK;
    if(dio_pin_write_logic(pinNum,port,DIO_LOW)){ret=E_OK ; return ret;} 
    return ret;
}
#endif 
