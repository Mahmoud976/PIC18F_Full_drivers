#include"led.h"

#if LED_ENABLE
Std_ReturnType led_init(uint8_t pinNum ,uint8_t port){
    if(dio_pin_direction_initialize(pinNum,port,DIO_OUTPUT)
    && dio_pin_write_logic(pinNum,port,DIO_LOW/*for safty*/))return E_OK;
    return E_NOT_OK;
}
#endif


#if LED_ENABLE
Std_ReturnType led_on(uint8_t pinNum ,uint8_t port){
   if(dio_pin_write_logic(pinNum,port,DIO_HIGH))return E_OK;
   return E_NOT_OK;
}
#endif

#if LED_ENABLE
Std_ReturnType led_off(uint8_t pinNum ,uint8_t port){
   if(dio_pin_write_logic(pinNum,port,DIO_LOW))return E_OK;
   return E_NOT_OK;
}
#endif

#if LED_ENABLE
Std_ReturnType led_toggle(uint8_t pinNum ,uint8_t port){
    if(dio_pin_toggle_logic(pinNum,port))return E_OK;
    return E_NOT_OK;
}
#endif
