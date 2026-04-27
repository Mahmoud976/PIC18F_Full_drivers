#include"button.h"

#if BUTTON_ENABLE

Std_ReturnType button_init(uint8_t pinNum,uint8_t port){
   if(dio_pin_direction_initialize(pinNum,port,DIO_INPUT))return E_OK;
   return E_NOT_OK;
}

Std_ReturnType button_read(uint8_t pinNum,uint8_t port,button_active_t connection, button_state_t* status){
    Std_ReturnType ret=E_NOT_OK;
    if(NULL==status)return ret;
    else {    
        logic_t state=DIO_LOW;
       dio_pin_read_logic(pinNum,port,&state);
       if(BUTTON_ACTIVE_HIGH == connection){
            if(DIO_HIGH==state)
                *status=BUTTON_PRESSED;
        
            else if(DIO_LOW==state)
                *status=BUTTON_RELEASED;
            
            else ret=E_NOT_OK;
        }
        else if(BUTTON_ACTIVE_LOW == connection){
            if(DIO_LOW==state)
                *status=BUTTON_PRESSED;
        
            else if(DIO_HIGH==state)
                *status=BUTTON_RELEASED;
            
            else ret=E_NOT_OK;
        }
        else ret=E_NOT_OK;
    }
   
   return ret;
}
#endif

