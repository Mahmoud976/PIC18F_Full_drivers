/* 
 * File:   timer2.c
 * Author: Mahmoud Saleh
 *
 * Created on June 16, 2023, 12:28 AM
 */

#include"timer2.h"




#if DISABLE_INTERRUPT 

Std_ReturnType Timer2_Init(uint8_t Preload,timer2_prescaler_select_t prescaler,timer2_postscaler_select_t postscaler){
    
     TIMER2_MODULE_DISABLE();
    T2CONBIT.T2CKPS=prescaler;
    T2CONBIT.T2OUTPS=postscaler;
    TMR2=Preload; 
     TIMER2_MODULE_ENABLE();
     while(1){
       if(READ_BIT(PIR1,1)){TIMER2_INTERRUPT_CLEAR_FLAG();break;}
    }
}
Std_ReturnType Timer2_DeInit(){
    
     TIMER2_MODULE_DISABLE();
}

#endif

Std_ReturnType Timer2_Write_Value(uint8_t value){
    
    
}

Std_ReturnType Timer2_Read_Value(uint8_t * value){
    
    
}

#if ENABLE_INTERRUPT
Std_ReturnType Timer2_Init(void (*TIMER2)(void),interrupt_priority priority,uint8_t Preload,timer2_prescaler_select_t prescaler,timer2_postscaler_select_t postscaler){
  if(NULL==TIMER2)return E_NOT_OK;
    else{
    TIMER2_MODULE_DISABLE();
    T2CONBIT.T2CKPS=prescaler;
    T2CONBIT.T2OUTPS=postscaler;
    TMR2=Preload; 
    extern uint8_t Timer2_Preload;
    Timer2_Preload=Preload;
     //interrupt
    Enable_General_INT();
    TIMER2_INTERRUPT_ENABLE();
   #if ENABLE_PRIORITY
    ENABLE_ALL_PRIORITY();
    if(priority==INTERRUPT_HIGH_PRIORITY)
        TIMER2_SET_HIGH_PRIORITY();  //enable priority HIGH
    else if(priority==INTERRUPT_LOW_PRIORITY)
        TIMER2_SET_LOW_PRIORITY();  //enable priority LOW
    else{/*Nothing*/}
    #endif
    TIMER2_INTERRUPT_CLEAR_FLAG();
    Timer2_SetInterruptHandler(TIMER2);
    TIMER2_MODULE_ENABLE();
    
    }    
}
Std_ReturnType Timer2_DeInit(){
    TIMER2_MODULE_DISABLE();
    TIMER2_INTERRUPT_DISABLE();
}
#endif

