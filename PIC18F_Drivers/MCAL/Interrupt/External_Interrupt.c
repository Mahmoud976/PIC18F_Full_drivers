/* 
 * File:   External_Interrupt.h
 * Author: mahmoud saleh
 *
 *
 * Created on April 11, 2023, 12:01 AM
 */

#include"External_Interrupt.h"
static void (*RB4_InterruptHandlerHigh)(void)=NULL;
static void (*RB4_InterruptHandlerLow)(void)=NULL;
static void (*RB5_InterruptHandlerHigh)(void)=NULL;
static void (*RB5_InterruptHandlerLow)(void)=NULL;
static void (*RB6_InterruptHandlerHigh)(void)=NULL;
static void (*RB6_InterruptHandlerLow)(void)=NULL;
static void (*RB7_InterruptHandlerHigh)(void)=NULL;
static void (*RB7_InterruptHandlerLow)(void)=NULL;
static Std_ReturnType RB4_SetInterruptHandlerHigh(void(*InterruptHandler)(void));
static Std_ReturnType RB4_SetInterruptHandlerLow(void(*InterruptHandler)(void));
static Std_ReturnType RB5_SetInterruptHandlerHigh(void(*InterruptHandler)(void));
static Std_ReturnType RB5_SetInterruptHandlerLow(void(*InterruptHandler)(void));
static Std_ReturnType RB6_SetInterruptHandlerHigh(void(*InterruptHandler)(void));
static Std_ReturnType RB6_SetInterruptHandlerLow(void(*InterruptHandler)(void));
static Std_ReturnType RB7_SetInterruptHandlerHigh(void(*InterruptHandler)(void));
static Std_ReturnType RB7_SetInterruptHandlerLow(void(*InterruptHandler)(void));

static void (*INT0_InterruptHandler)(void)=NULL;
static void (*INT1_InterruptHandler)(void)=NULL;
static void (*INT2_InterruptHandler)(void)=NULL;

static Std_ReturnType INT0_SetInterruptHandler(void(*InterruptHandler)(void));
static Std_ReturnType INT1_SetInterruptHandler(void(*InterruptHandler)(void));
static Std_ReturnType INT2_SetInterruptHandler(void(*InterruptHandler)(void));

static Std_ReturnType Interrupt_INTx_SetInterruptHandler(INTx_NUM num,void(*add)(void));
static Std_ReturnType Init_Priority_INTx(INTx_NUM num,interrupt_priority priority);

Std_ReturnType Interrupt_INTx_Init(INTx_NUM num,INTx_edge edge,interrupt_priority priority){
    Std_ReturnType ret=E_OK; 
    if( Enable_General_INT() && Enable_Peripheral_INT()){ 
        switch(num){
            case INTERRUPT_EXTERNAL_INT0:
                dio_pin_direction_initialize(INTERRUPT_EXTERNAL_INT0,'B',1);
                if(edge==INTERRUPT_FALLING_EDGE)   
                  CLEAR_BIT(INTCON2,BIT6);//enable Falling edge  
                
                else if(edge==INTERRUPT_RAISING_EDGE)
                    SET_BIT(INTCON2,BIT6);//enable Raising edge
                
                else ret=E_NOT_OK;
                 SET_BIT(INTCON,BIT4);//enable INT0
                break;
            
            case INTERRUPT_EXTERNAL_INT1:
              
                SET_BIT(INTCON3,BIT3);//enable INT1 
                dio_pin_direction_initialize(INTERRUPT_EXTERNAL_INT1,'B',1);
                if(edge==INTERRUPT_FALLING_EDGE){
                    CLEAR_BIT(INTCON2,BIT5);//enable Falling edge
                    #if INT_ENA_PROIRTY
                    if(priority==INTERRUPT_LOW_LEVEL)
                    Init_Priority_INTx(INTERRUPT_EXTERNAL_INT1,priority);
                    
                    else if(priority==INTERRUPT_HIGH_LEVEL)
                    Init_Priority_INTx(INTERRUPT_EXTERNAL_INT1,priority);
                    #endif
                }
                else if(edge==INTERRUPT_RAISING_EDGE){
                    SET_BIT(INTCON2,BIT5);//enable Raising edge
                    #if INT_ENA_PROIRTY
                    if(priority==INTERRUPT_LOW_LEVEL)
                    Init_Priority_INTx(INTERRUPT_EXTERNAL_INT1,priority);
                    
                    else if(priority==INTERRUPT_HIGH_LEVEL)
                    Init_Priority_INTx(INTERRUPT_EXTERNAL_INT1,priority);
                    #endif
                }

                else ret=E_NOT_OK;
                break;
            case INTERRUPT_EXTERNAL_INT2:
            
                SET_BIT(INTCON3,BIT4); //enable INT2
                dio_pin_direction_initialize(INTERRUPT_EXTERNAL_INT2,'B',1);
                if(edge==INTERRUPT_FALLING_EDGE){
                    CLEAR_BIT(INTCON2,BIT4);//enable Falling edge
                    #if INT_ENA_PROIRTY
                    if(priority==INTERRUPT_LOW_LEVEL)
                    Init_Priority_INTx(INTERRUPT_EXTERNAL_INT2,priority);
                    
                    else if(priority==INTERRUPT_HIGH_LEVEL)
                    Init_Priority_INTx(INTERRUPT_EXTERNAL_INT2,priority);
                    #endif
                }
                else if(edge==INTERRUPT_RAISING_EDGE){
                    SET_BIT(INTCON2,BIT4);//enable Raising edge
                    #if INT_ENA_PROIRTY
                    if(priority==INTERRUPT_LOW_LEVEL)
                    Init_Priority_INTx(INTERRUPT_EXTERNAL_INT2,priority);
                    
                    else if(priority==INTERRUPT_HIGH_LEVEL)
                    Init_Priority_INTx(INTERRUPT_EXTERNAL_INT2,priority);
                    #endif
                }

                else ret=E_NOT_OK;
            break;
            default:
                ret=E_NOT_OK;
        }
    }
    else ret =E_NOT_OK;
    
    return ret;
}
Std_ReturnType Interrupt_INTx_Deinit(INTx_NUM num){
    Std_ReturnType ret =E_OK;
    switch(num){
        case INTERRUPT_EXTERNAL_INT0:
            CLEAR_BIT(INTCON,BIT4);//disable INT0
            break;
        case INTERRUPT_EXTERNAL_INT1:
            CLEAR_BIT(INTCON3,BIT3);//disable INT1 
            break;
        case INTERRUPT_EXTERNAL_INT2:
            CLEAR_BIT(INTCON3,BIT4); //disable INT
        break;
        default:ret=E_NOT_OK;       
    }
    return ret;
}

static Std_ReturnType Init_Priority_INTx(INTx_NUM num,interrupt_priority priority){
    
    Std_ReturnType ret=ENABLE_ALL_PRIORITY();
    switch(num){
        case INTERRUPT_EXTERNAL_INT1:
            if(priority==INTERRUPT_HIGH_LEVEL)
            SET_BIT(INTCON3,BIT6);  //enable priority HIGH
            else if(priority==INTERRUPT_LOW_LEVEL)
            CLEAR_BIT(INTCON3,BIT6);  //enable priority LOW
            break;
        case INTERRUPT_EXTERNAL_INT2:
                if(priority==INTERRUPT_HIGH_LEVEL)
                SET_BIT(INTCON3,BIT7);  //enable priority HIGH
                else if(priority==INTERRUPT_LOW_LEVEL)
                CLEAR_BIT(INTCON3,BIT7);  //enable priority LOW
                break;   
    }
    return ret;
}
static Std_ReturnType INT0_SetInterruptHandler(void(*InterruptHandler)(void)){
    Std_ReturnType ret=E_OK;
    if(NULL==InterruptHandler)ret=E_NOT_OK;
    else{
    INT0_InterruptHandler=InterruptHandler;
    }

}
static Std_ReturnType INT1_SetInterruptHandler(void(*InterruptHandler)(void)){

 Std_ReturnType ret=E_OK;
    if(NULL==InterruptHandler)ret=E_NOT_OK;
    else{
    INT1_InterruptHandler=InterruptHandler;
    }
}
static Std_ReturnType INT2_SetInterruptHandler(void(*InterruptHandler)(void)){
 Std_ReturnType ret=E_OK;
    if(NULL==InterruptHandler)ret=E_NOT_OK;
    else{
    INT2_InterruptHandler=InterruptHandler;
    }

}

static Std_ReturnType Interrupt_INTx_SetInterruptHandler(INTx_NUM num,void(*add)(void)){
       Std_ReturnType ret =E_OK;
    if(NULL==add){ret=E_NOT_OK;}
    else{
        switch(num){
            case INTERRUPT_EXTERNAL_INT0:
                INT0_SetInterruptHandler(add);
                break;
            case INTERRUPT_EXTERNAL_INT1:
                INT1_SetInterruptHandler(add);
                break;
            case INTERRUPT_EXTERNAL_INT2:
                INT2_SetInterruptHandler(add);
                break;    
            default:
                ret=E_NOT_OK;
        }
   }
    return ret;
}
 

Std_ReturnType Interrupt_INTx(INTx_NUM num,INTx_edge edge,interrupt_priority priority,void(*ptr)(void)){
    Std_ReturnType ret ;
   Interrupt_INTx_Deinit(num);
   
        CLEAR_BIT(INTCON,BIT1) ;
        CLEAR_BIT(INTCON3,BIT0);
        CLEAR_BIT(INTCON3,BIT1);
    
    ret= Interrupt_INTx_Init(num,edge,priority);
    ret&= Interrupt_INTx_SetInterruptHandler(num,ptr);
    
    return ret;
}

void INT0_ISR(){
    CLEAR_BIT(INTCON,BIT1);//clear by software
    //code
    
  /*call back*/
    if(INT0_InterruptHandler){INT0_InterruptHandler();}
    
}
void INT1_ISR(){
    CLEAR_BIT(INTCON3,BIT0);//clear by software
    //code
  /*call back*/
    if(INT1_InterruptHandler){INT1_InterruptHandler();}
    
}
void INT2_ISR(){
    CLEAR_BIT(INTCON3,BIT1);//clear by software
    //code
    
  /*call back*/
    if(INT2_InterruptHandler){INT2_InterruptHandler();}
    
}





static Std_ReturnType RB4_SetInterruptHandlerHigh(void(*InterruptHandler)(void)){
    Std_ReturnType ret=E_OK;         
    if(NULL==InterruptHandler)ret=E_NOT_OK;
    RB4_InterruptHandlerHigh=InterruptHandler;
    return ret;
}
static Std_ReturnType RB4_SetInterruptHandlerLow(void(*InterruptHandler)(void)){
      Std_ReturnType ret=E_OK;         
    if(NULL==InterruptHandler)ret=E_NOT_OK;
    RB4_InterruptHandlerLow=InterruptHandler;
    return ret; 
}
static Std_ReturnType RB5_SetInterruptHandlerHigh(void(*InterruptHandler)(void)){
       Std_ReturnType ret=E_OK;         
    if(NULL==InterruptHandler)ret=E_NOT_OK;
    RB5_InterruptHandlerHigh=InterruptHandler;
    return ret;
}
static Std_ReturnType RB5_SetInterruptHandlerLow(void(*InterruptHandler)(void)){
       Std_ReturnType ret=E_OK;         
    if(NULL==InterruptHandler)ret=E_NOT_OK;
    RB5_InterruptHandlerLow=InterruptHandler;
    return ret;
}
static Std_ReturnType RB6_SetInterruptHandlerHigh(void(*InterruptHandler)(void)){
       Std_ReturnType ret=E_OK;         
    if(NULL==InterruptHandler)ret=E_NOT_OK;
    RB6_InterruptHandlerHigh=InterruptHandler;
    return ret;
}
static Std_ReturnType RB6_SetInterruptHandlerLow(void(*InterruptHandler)(void)){
       Std_ReturnType ret=E_OK;         
    if(NULL==InterruptHandler)ret=E_NOT_OK;
    RB6_InterruptHandlerLow=InterruptHandler;
    return ret;
}
static Std_ReturnType RB7_SetInterruptHandlerHigh(void(*InterruptHandler)(void)){
       Std_ReturnType ret=E_OK;         
    if(NULL==InterruptHandler)ret=E_NOT_OK;
    RB7_InterruptHandlerHigh=InterruptHandler;
    return ret;
}
static Std_ReturnType RB7_SetInterruptHandlerLow(void(*InterruptHandler)(void)){
       Std_ReturnType ret=E_OK;         
    if(NULL==InterruptHandler)ret=E_NOT_OK;
    RB7_InterruptHandlerLow=InterruptHandler;
    return ret;
}

Std_ReturnType Interrupt_RBx(RBx_NUM num,interrupt_priority priority,void(*ptr0)(void),void(*ptr1)(void)){
    
    Std_ReturnType ret=E_OK;
    Interrupt_RBx_Deinit();
    CLEAR_BIT(INTCON,BIT0);
    Enable_General_INT() ; Enable_Peripheral_INT();
    if(NULL!=ptr0){
        switch(num){
            case INTERRUPT_EXTERNAL_PIN4:
                dio_pin_direction_initialize(INTERRUPT_EXTERNAL_PIN4,'B',1);
                RB4_SetInterruptHandlerHigh(ptr0);
                if(NULL==ptr1)RB4_SetInterruptHandlerLow(ptr0);
                else RB4_SetInterruptHandlerLow(ptr1);
                break;
            case INTERRUPT_EXTERNAL_PIN5:
                dio_pin_direction_initialize(INTERRUPT_EXTERNAL_PIN5,'B',1);
                RB5_SetInterruptHandlerHigh(ptr0);
                if(NULL==ptr1)RB5_SetInterruptHandlerLow(ptr0);
                else RB5_SetInterruptHandlerLow(ptr1);
                break;
            case INTERRUPT_EXTERNAL_PIN6:
                dio_pin_direction_initialize(INTERRUPT_EXTERNAL_PIN6,'B',1);
                RB6_SetInterruptHandlerHigh(ptr0);
                if(NULL==ptr1)RB6_SetInterruptHandlerLow(ptr0);
                else RB6_SetInterruptHandlerLow(ptr1);
                break;
            case INTERRUPT_EXTERNAL_PIN7:
                dio_pin_direction_initialize(INTERRUPT_EXTERNAL_PIN7,'B',1);
                RB7_SetInterruptHandlerHigh(ptr0);
                if(NULL==ptr1)RB7_SetInterruptHandlerLow(ptr0);
                else RB7_SetInterruptHandlerLow(ptr1);
                break;
   
        }
        
        Interrupt_RBx_Init();
        #if INT_ENA_PROIRTY
        if(priority==INTERRUPT_HIGH_LEVEL)
            init_Priority_RBx_Low();   //enable priority HIGH
        else if(priority==INTERRUPT_LOW_LEVEL)
            Init_Priority_RBx_High(); //enable priority LOW
        #endif
    }
    else ret=E_NOT_OK;
        
    return ret;
}


void RB4_ISR_High(){
    CLEAR_BIT(INTCON,BIT0); //clear by software
    //code
  /*call back*/
    if(RB4_InterruptHandlerHigh){RB4_InterruptHandlerHigh();}   
}
void RB4_ISR_Low(){
    CLEAR_BIT(INTCON,BIT0); //clear by software
    //code
  /*call back*/
    if(RB4_InterruptHandlerLow){RB4_InterruptHandlerLow();}   
}

void RB5_ISR_High(){
    CLEAR_BIT(INTCON,BIT0); //clear by software
    //code
  /*call back*/
    if(RB5_InterruptHandlerHigh){RB5_InterruptHandlerHigh();}   
}
void RB5_ISR_Low(){
    CLEAR_BIT(INTCON,BIT0); //clear by software
    //code
  /*call back*/
    if(RB5_InterruptHandlerLow){RB5_InterruptHandlerLow();}   
}

void RB6_ISR_High(){
    CLEAR_BIT(INTCON,BIT0); //clear by software
    //code
  /*call back*/
    if(RB6_InterruptHandlerHigh){RB6_InterruptHandlerHigh();}   
}
void RB6_ISR_Low(){
    CLEAR_BIT(INTCON,BIT0); //clear by software
    //code
  /*call back*/
    if(RB6_InterruptHandlerLow){RB6_InterruptHandlerLow();}   
}
void RB7_ISR_High(){
    CLEAR_BIT(INTCON,BIT0); //clear by software
    //code
  /*call back*/
    if(RB7_InterruptHandlerHigh){RB7_InterruptHandlerHigh();}   
}
void RB7_ISR_Low(){
    CLEAR_BIT(INTCON,BIT0); //clear by software
    //code
  /*call back*/
    if(RB7_InterruptHandlerLow){RB7_InterruptHandlerLow();}   
}


