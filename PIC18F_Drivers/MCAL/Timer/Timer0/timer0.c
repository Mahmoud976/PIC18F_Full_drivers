/* 
 * File:   timer0.c
 * Author: mahmoud saleh
 *
 * Created on May 29, 2023, 5:21 PM
 */
#include"timer0.h"
static inline void Timer0_Select_Size(uint8_t size);
static inline void Timer0_Select_Mode(uint8_t Timer0_mode,uint16_t Preload);
static inline void Timer0_Select_Edge(uint8_t TMR0_Counter_edge);
static inline void Timer0_Select_Prescaler(uint8_t Pre_Enable,timer0_prescaler_select_t prescaler);


#if DISABLE_INTERRUPT == 1
Std_ReturnType Timer0_Init(uint8_t size ,uint8_t Timer0_mode,uint16_t Preload,uint8_t TMR0_Counter_edge,uint8_t Pre_Enable,timer0_prescaler_select_t prescaler){
    TIMER0_MODULE_DISABLE();
    extern uint16_t Timer0_Preload;
    Timer0_Preload=Preload;
    Timer0_Select_Size(size);
    Timer0_Select_Mode(Timer0_mode,Preload);
    Timer0_Select_Edge(TMR0_Counter_edge);
    Timer0_Select_Prescaler(Pre_Enable,prescaler);
    TIMER0_MODULE_ENABLE();
    return E_OK;
}
Std_ReturnType Timer0_delay(){
    while(1){
       if(READ_BIT(INTCON,2)){TIMER0_INTERRUPT_CLEAR_FLAG();break;}
    }
    return E_OK;
}
Std_ReturnType Timer0_DeInit(){
    TIMER0_MODULE_DISABLE();
    return E_OK;
}
#endif
Std_ReturnType Timer0_Write_Value(uint16_t value){
    TMR0H=(value)>>8;
    TMR0L=(uint8_t)(value);
    return E_OK;
}


Std_ReturnType Timer0_Read_Value(uint16_t * value){
    uint8_t tmr0l=0,tmr0h=0;
    tmr0l=TMR0L;
    tmr0h=TMR0H;
    * value=(uint16_t)((tmr0h<<8)+tmr0l);
    return E_OK;
}


#if ENABLE_INTERRUPT == 1
Std_ReturnType Timer0_Init(void (*TIMER0)(void),interrupt_priority priority,uint8_t size ,uint8_t Timer0_mode,uint16_t Preload,uint8_t TMR0_Counter_edge,uint8_t Pre_Enable,timer0_prescaler_select_t prescaler){
    if(NULL==TIMER0)return E_NOT_OK;
    TIMER0_MODULE_DISABLE();
    extern uint16_t Timer0_Preload;
    Timer0_Preload=Preload;
    Timer0_Select_Size(size);
    Timer0_Select_Mode(Timer0_mode,Preload);
    Timer0_Select_Edge(TMR0_Counter_edge);
    Timer0_Select_Prescaler(Pre_Enable,prescaler);
    //configure the interrupt
    Enable_General_INT();
    TIMER0_INTERRUPT_ENABLE();
   #if ENABLE_PRIORITY
    ENABLE_ALL_PRIORITY();
    if(priority==INTERRUPT_HIGH_PRIORITY)
        TIMER0_SET_HIGH_PRIORITY();  //enable priority HIGH
    else if(priority==INTERRUPT_LOW_PRIORITY)
        TIMER0_SET_LOW_PRIORITY();  //enable priority LOW
    else{/*Nothing*/}
    #endif
    TIMER0_INTERRUPT_CLEAR_FLAG();
    Timer0_SetInterruptHandler(TIMER0);  
    
    TIMER0_MODULE_ENABLE();

return E_OK;
}
Std_ReturnType Timer0_DeInit(){
TIMER0_MODULE_DISABLE();
TIMER0_INTERRUPT_DISABLE();
return E_OK;
}
#endif



static inline void Timer0_Select_Size(uint8_t size){
    if(8==size){TIMER0_8BIT_REGISTER_MODE_ENABLE();}
    else if(16==size){TIMER0_16BIT_REGISTER_MODE_ENABLE();}
    else {/*Nothing*/}
}

static inline void Timer0_Select_Mode(uint8_t Timer0_mode,uint16_t Preload){
    if(timer_mode==Timer0_mode){
        TIMER0_TIMER_MODE_ENABLE();
        TMR0H=(Preload)>>8;
        TMR0L=(uint8_t)Preload;

    }
    else if(counter_mode==Timer0_mode){TIMER0_COUNTER_MODE_ENABLE();}
    else{/*Nothing*/}    
}
static inline void Timer0_Select_Edge(uint8_t TMR0_Counter_edge){
    if(timer0_Falling==TMR0_Counter_edge){TIMER0_FALLING_EDGE_ENABLE();}
    else if(timer0_Raising,TMR0_Counter_edge){TIMER0_RISING_EDGE_ENABLE();}
    else{/*Nothing*/} 
}

static inline void Timer0_Select_Prescaler(uint8_t Pre_Enable,timer0_prescaler_select_t prescaler){
    if(PRESCALER_ENABLE==Pre_Enable){
        TIMER0_PRESCALER_ENABLE();
        T0CONBIT.T0PS=prescaler;
        
    }
    else if(PRESCALER_DISABLE==Pre_Enable){TIMER0_PRESCALER_DISABLE();}    
    else {/*Nothing*/}
}

