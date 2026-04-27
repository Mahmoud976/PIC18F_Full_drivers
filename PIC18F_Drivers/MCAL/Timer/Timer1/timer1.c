/* 
 * File:   timer1.h
 * Author: mahmoud saleh
 * Created on June 6, 2023, 8:49 PM
 */

#include"timer1.h"
static inline void Timer1_Select_Mode(uint8_t Timer1_mode,uint8_t ASY);
static inline void Timer1_Select_Prescaler(timer1_prescaler_select_t prescaler);
static inline void Timer1_Select_Oscillator(uint8_t Oscillator);

#if DISABLE_INTERRUPT 
Std_ReturnType Timer1_Init(uint8_t Oscillator,uint8_t Timer1_mode,uint8_t ASY,uint16_t Preload,timer1_prescaler_select_t prescaler){
    TIMER1_MODULE_DISABLE();
    Timer1_Select_Oscillator(Oscillator);
    TIMER1_RAED_WRITE_MODE_8();
    Timer1_Select_Mode(Timer1_mode,ASY);
    TMR1H=((Preload)>>8);
    TMR1L=(uint8_t)(Preload);
    T1CONBIT.T1CKPS=prescaler; //set prescaler
    TIMER1_MODULE_ENABLE();
    return E_OK;
}

Std_ReturnType Timer1_delay(){
    while(1){
       if(READ_BIT(PIR1,0)){TIMER1_INTERRUPT_CLEAR_FLAG();break;}
    }
    return E_OK;
}


Std_ReturnType Timer1_DeInit(){
    TIMER1_MODULE_DISABLE();
    return E_OK;
}
#endif


Std_ReturnType Timer1_Write_Value(uint16_t value){
    TMR1H=(value)>>8;
    TMR1L=(uint8_t)(value);
    return E_OK;
}


Std_ReturnType Timer1_Read_Value(uint16_t * value){
    uint8_t tmr1l=0,tmr1h=0;
    tmr1l=TMR1L;
    tmr1h=TMR1H;
    * value=(uint16_t)((tmr1h<<8)+tmr1l);
    return E_OK;
}


#if ENABLE_INTERRUPT 
Std_ReturnType Timer1_Init(void (*TIMER1)(void),interrupt_priority priority,uint8_t Oscillator,uint8_t Timer1_mode,uint8_t ASY,uint16_t Preload,timer1_prescaler_select_t prescaler){
    if(NULL==TIMER1)return E_NOT_OK;
    else{
        
    TIMER1_MODULE_DISABLE();
    Timer1_Select_Oscillator(Oscillator);
    TIMER1_RAED_WRITE_MODE_8();
    Timer1_Select_Mode(Timer1_mode,ASY);
    TMR1H=((Preload)>>8);
    TMR1L=(uint8_t)(Preload);
    
    extern uint16_t Timer1_Preload;
    Timer1_Preload=Preload;
    
    T1CONBIT.T1CKPS=prescaler; //set prescaler
    
    //interrupt
    Enable_General_INT();
    TIMER1_INTERRUPT_ENABLE();
   #if ENABLE_PRIORITY
    ENABLE_ALL_PRIORITY();
    if(priority==INTERRUPT_HIGH_PRIORITY)
        TIMER1_SET_HIGH_PRIORITY();  //enable priority HIGH
    else if(priority==INTERRUPT_LOW_PRIORITY)
        TIMER1_SET_LOW_PRIORITY();  //enable priority LOW
    else{/*Nothing*/}
    #endif
    TIMER1_INTERRUPT_CLEAR_FLAG();
    Timer1_SetInterruptHandler(TIMER1);
    TIMER1_MODULE_ENABLE();
    
    }

return E_OK;
}
Std_ReturnType Timer1_DeInit(){
//TIMER1_MODULE_DISABLE();
TIMER1_INTERRUPT_DISABLE();
return E_OK;
}
#endif

static inline void Timer1_Select_Mode(uint8_t Timer1_mode,uint8_t ASY){
    if(timer_mode==Timer1_mode){
        TIMER1_TIMER_MODE_ENABLE();
    }
    
    else if(counter_mode==Timer1_mode){
        TIMER1_COUNTER_MODE_ENABLE();
        if(1==ASY){ TIMER1_Synchronize_ENABLE();}
        else if(0==ASY){TIMER1_Synchronize_DISABLE();}
        else{/*Nothing*/} 
    }
    else{/*Nothing*/} 
}
static inline void Timer1_Select_Oscillator(uint8_t Oscillator){
    if(timer_mode==Oscillator)TIMER1_Oscillator_DISABLE();
    
    
    else if(counter_mode==Oscillator)
       TIMER1_Oscillator_ENABLE();
    
    else{/*Nothing*/} 
}


