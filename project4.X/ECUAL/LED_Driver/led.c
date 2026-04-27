#include"led.h"

Std_ReturnType led_init(uint8_t pinNum,uint8_t port){
     dio_pin_direction_initialize(pinNum,port,DIO_OUTPUT);
    
}
Std_ReturnType led_on(uint8_t pinNum,uint8_t port){
    led_init(pinNum,port);
    dio_pin_write_logic(pinNum,port,DIO_HIGH);
}
Std_ReturnType led_off(uint8_t pinNum,uint8_t port){
     led_init(pinNum,port);
    dio_pin_write_logic(pinNum,port,DIO_LOW);
}
Std_ReturnType led_toggel(uint8_t pinNum,uint8_t port){
   led_init(pinNum,port); 
    dio_pin_toggle_logic(pinNum,port);
}
