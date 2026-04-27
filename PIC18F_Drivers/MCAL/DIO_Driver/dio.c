#include"dio.h"

#if DIO_PIN_CFG == CFG_ENABLE
Std_ReturnType dio_pin_direction_initialize(uint8_t pinNum,uint8_t port,uint8_t direction){
    uint8_t ret=E_OK;
    if(pinNum > pin_max)ret=E_NOT_OK;
    else{
        switch(port){
            case 'A':
               if(direction == DIO_OUTPUT)        CLEAR_BIT(TRISA,pinNum);  //input direction
               else if(direction == DIO_INPUT)    SET_BIT(TRISA,pinNum);    //output direction
               else  ret=E_NOT_OK;    //error handling
               break;
            case 'B':
               if(direction == DIO_OUTPUT)        CLEAR_BIT(TRISB,pinNum);  //input direction
               else if(direction == DIO_INPUT)    SET_BIT(TRISB,pinNum);    //output direction
               else  ret=E_NOT_OK;    //error handling
               break;
            case 'C':
               if(direction == DIO_OUTPUT)        CLEAR_BIT(TRISC,pinNum);   //input direction
               else if(direction == DIO_INPUT)    SET_BIT(TRISC,pinNum);     //output direction
               else  ret=E_NOT_OK;     //error handling
               break;
            case 'D':
               if(direction == DIO_OUTPUT)        CLEAR_BIT(TRISD,pinNum);   //input direction
               else if(direction == DIO_INPUT)    SET_BIT(TRISD,pinNum);     //output direction
               else  ret=E_NOT_OK;     //error handling
               break; 
            case 'E':
               if(direction == DIO_OUTPUT)        CLEAR_BIT(TRISE,pinNum);    //input direction
               else if(direction == DIO_INPUT)    SET_BIT(TRISE,pinNum);      //output direction
               else  ret=E_NOT_OK;     //error handling
            default :
               ret=E_NOT_OK;  
        } 
    }
   return ret;
}
#endif


#if DIO_PIN_CFG == CFG_ENABLE
Std_ReturnType dio_pin_write_logic( uint8_t pinNum ,uint8_t port ,logic_t logic){
    uint8_t ret=E_OK;
    if(pinNum > pin_max)ret=E_NOT_OK;
    else{
        switch(port){
            case 'A':
               if(logic == DIO_LOW)              CLEAR_BIT(LATA,pinNum);  //set bit low
               else if(logic == DIO_HIGH)        SET_BIT(LATA,pinNum);    //set bit high
               else  ret=E_NOT_OK;    //error handling
               break;
            case 'B':
               if(logic == DIO_LOW)              CLEAR_BIT(LATB,pinNum);  //set bit low
               else if(logic == DIO_HIGH)        SET_BIT(LATB,pinNum);    //set bit high
               else  ret=E_NOT_OK;    //error handling
               break;
            case 'C':
               if(logic == DIO_LOW)              CLEAR_BIT(LATC,pinNum);  //set bit low
               else if(logic == DIO_HIGH)        SET_BIT(LATC,pinNum);    //set bit high
               else  ret=E_NOT_OK;     //error handling
               break;
            case 'D':
               if(logic == DIO_LOW)              CLEAR_BIT(LATD,pinNum);  //set bit low
               else if(logic == DIO_HIGH)        SET_BIT(LATD,pinNum);    //set bit high
               else  ret=E_NOT_OK;     //error handling
               break; 
            case 'E':
               if(logic == DIO_LOW)              CLEAR_BIT(LATE,pinNum);  //set bit low
               else if(logic == DIO_HIGH)        SET_BIT(LATE,pinNum);    //set bit high
               else  ret=E_NOT_OK;     //error handling
               break;
            default :
               ret=E_NOT_OK;  
        } 
    }
   return ret;
}
#endif


#if DIO_PIN_CFG == CFG_ENABLE
Std_ReturnType dio_pin_read_logic(uint8_t pinNum,uint8_t port,logic_t * logic_status){
    uint8_t ret=E_OK;
    if(pin_max < pinNum || NULL==logic_status)ret=E_NOT_OK;
    else{
        switch(port){
            case 'A':
               * logic_status = READ_BIT(PORTA,pinNum);  //read bit 
               break;
            case 'B':
               * logic_status = READ_BIT(PORTB,pinNum);  //read bit 
               break;
            case 'C':
               * logic_status = READ_BIT(PORTC,pinNum);   //read bit      
               break;
            case 'D':
               * logic_status = READ_BIT(PORTD,pinNum);   //read bit       
               break; 
            case 'E':
               * logic_status = READ_BIT(PORTE,pinNum);    //read bit
               break;
            default :
               ret=E_NOT_OK;  
        } 
    }
   return ret;
}
#endif


#if DIO_PIN_CFG == CFG_ENABLE
Std_ReturnType dio_pin_toggle_logic(uint8_t pinNum,uint8_t port){
   uint8_t ret=E_OK;
    if(pinNum > pin_max)ret=E_NOT_OK;
    else{
        switch(port){
            case 'A':
               TOGGLE_BIT(LATA,pinNum);  //write 0 if =1 or  write 1 if =0 
               break;
            case 'B':
               TOGGLE_BIT(LATB,pinNum);  //write 0 if =1 or  write 1 if =0 
               break;
            case 'C':
               TOGGLE_BIT(LATC,pinNum);  //write 0 if =1 or  write 1 if =0
               break;
            case 'D':
               TOGGLE_BIT(LATD,pinNum); //write 0 if =1 or  write 1 if =0
               break; 
            case 'E':
               TOGGLE_BIT(LATE,pinNum);  //write 0 if =1 or  write 1 if =0
               break;
            default :
               ret=E_NOT_OK;  
        } 
    }
   return ret;
}
#endif

#if DIO_PORT_CFG == CFG_ENABLE
Std_ReturnType dio_port_direction_initialize(uint8_t port,uint8_t direction){
    uint8_t ret=E_OK;
    switch(port){
        case 'A':
            if(direction == DIO_OUTPUT)       (TRISA&=(PORT_MASK_IN));  //output direction >>0
            else if(direction == DIO_INPUT)   (TRISA|=PORT_MASK_OUT);    //input direction  >>1
            else  ret=E_NOT_OK;    //error handling
            break;
        case 'B':
            if(direction == DIO_OUTPUT)       (TRISB&=(PORT_MASK_IN));  //output direction >>0
            else if(direction == DIO_INPUT)   (TRISB|=PORT_MASK_OUT);    //input direction  >>1
            else  ret=E_NOT_OK;    //error handling
            break;
        case 'C':
            if(direction == DIO_OUTPUT)       (TRISC&=(PORT_MASK_IN));  //output direction >>0
            else if(direction == DIO_INPUT)   (TRISC|=PORT_MASK_OUT);    //input direction  >>1
            else  ret=E_NOT_OK;     //error handling
            break;
        case 'D':
            if(direction == DIO_OUTPUT)       (TRISD&=(PORT_MASK_IN));  //output direction >>0
            else if(direction == DIO_INPUT)   (TRISD|=PORT_MASK_OUT);    //input direction  >>1
            else  ret=E_NOT_OK;     //error handling
            break; 
        case 'E':
            if(direction == DIO_OUTPUT)       (TRISE&=(PORT_MASK_IN));  //output direction >>0
            else if(direction == DIO_INPUT)   (TRISE|=PORT_MASK_OUT);    //input direction  >>1
            else  ret=E_NOT_OK;     //error handling
            break;
        default :
            ret=E_NOT_OK;  
        }
    return ret;
}
#endif

#if DIO_PORT_CFG == CFG_ENABLE
Std_ReturnType dio_port_write_logic(uint8_t port,logic_t logic){
    uint8_t ret=E_OK;
    switch(port){
        case 'A':
           if(logic == DIO_LOW)              (LATA&=PORT_MASK_LOW);     //set all bits low
           else if(logic == DIO_HIGH)        (LATA|=PORT_MASK_HIGH);    //set all bits high
           else  ret=E_NOT_OK;    //error handling
           break;
        case 'B':
           if(logic == DIO_LOW)              (LATB&=PORT_MASK_LOW);     //set all bits low
           else if(logic == DIO_HIGH)        (LATB|=PORT_MASK_HIGH);    //set all bits high
           else  ret=E_NOT_OK;    //error handling
           break;
        case 'C':
           if(logic == DIO_LOW)              (LATC&=PORT_MASK_LOW);     //set all bits low
           else if(logic == DIO_HIGH)        (LATC|=PORT_MASK_HIGH);    //set all bits high
           else  ret=E_NOT_OK;     //error handling
           break;
        case 'D':
           if(logic == DIO_LOW)              (LATD&=PORT_MASK_LOW);     //set all bits low
           else if(logic == DIO_HIGH)        (LATD|=PORT_MASK_HIGH);    //set all bits high
           else  ret=E_NOT_OK;     //error handling
           break; 
        case 'E':
           if(logic == DIO_LOW)              (LATE&=PORT_MASK_LOW);     //set all bits low
           else if(logic == DIO_HIGH)        (LATE|=PORT_MASK_HIGH);    //set all bits high
           else  ret=E_NOT_OK;     //error handling
           break;
        default :
           ret=E_NOT_OK;  
    } 
    return ret;
}
#endif

#if DIO_PORT_CFG == CFG_ENABLE
Std_ReturnType dio_port_read_logic(uint8_t port,logic_t* logic_status){
    uint8_t ret=E_OK;
    if(NULL==logic_status)ret=E_NOT_OK;
    else{
        switch(port){
            case 'A':
               * logic_status =(PORTA &= PORT_MASK_READ);  //read byte 
               break;
            case 'B':
               * logic_status = (PORTB &= PORT_MASK_READ);  //read byte 
               break;
            case 'C':
               * logic_status = (PORTC &= PORT_MASK_READ);   //read byte      
               break;
            case 'D':
               * logic_status = (PORTD &= PORT_MASK_READ);   //read byte       
               break; 
            case 'E':
               * logic_status = (PORTE &= PORT_MASK_READ);    //read byte
               break;
            default :
               ret=E_NOT_OK;  
        } 
    }
   return ret;
}
#endif

#if DIO_PORT_CFG == CFG_ENABLE
Std_ReturnType dio_port_toggle_logic(uint8_t port){
    uint8_t ret;
    switch(port){
        case 'A':
           (LATA ^=PORT_MASK_TOGGLE);  //write 0 if =1 or  write 1 if =0 
           break;
        case 'B':
           (LATB ^= PORT_MASK_TOGGLE);  //write 0 if =1 or  write 1 if =0 
           break;
        case 'C':
           (LATC ^= PORT_MASK_TOGGLE);  //write 0 if =1 or  write 1 if =0
           break;
        case 'D':
           (LATD ^= PORT_MASK_TOGGLE); //write 0 if =1 or  write 1 if =0
           break; 
        case 'E':
           (LATE ^= PORT_MASK_TOGGLE);  //write 0 if =1 or  write 1 if =0
           break;
        default :
           ret=E_NOT_OK;  
    } 
   return ret;
}
#endif


