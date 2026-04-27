#include"Internal_Interrupt.h"

 void (*ADC_InterruptHandler)(void)=NULL;
 void (*Timer0_InterruptHandler)(void)=NULL;
 void (*Timer1_InterruptHandler)(void)=NULL;
 void (*Timer2_InterruptHandler)(void)=NULL;
 void (*Timer3_InterruptHandler)(void)=NULL;
 
 #if EUSART_TX_ENABLE
     static void (*EUSART_TxInterruptHandler)(void) = NULL;
#endif
#if EUSART_RX_ENABLE
    static void (*EUSART_RxInterruptHandler)(void) = NULL;
    static void (*EUSART_FramingErrorHandler)(void) = NULL;
    static void (*EUSART_OverrunErrorHandler)(void) = NULL;
#endif  
    
 uint16_t Timer0_Preload=0;
 uint16_t Timer1_Preload=0;
 uint8_t  Timer2_Preload=0;
  uint8_t Timer3_Preload=0;  
  
 Std_ReturnType ADC_SetInterruptHandler(void(*InterruptHandler)(void)){
     ADC_InterruptHandler=InterruptHandler;
 }
 Std_ReturnType Timer0_SetInterruptHandler(void(*InterruptHandler)(void)){
     Timer0_InterruptHandler=InterruptHandler;
 }
 Std_ReturnType Timer1_SetInterruptHandler(void(*InterruptHandler)(void)){
     Timer1_InterruptHandler=InterruptHandler;
 }
 Std_ReturnType Timer2_SetInterruptHandler(void(*InterruptHandler)(void)){
     Timer2_InterruptHandler=InterruptHandler;
 }
 
 Std_ReturnType Timer3_SetInterruptHandler(void(*InterruptHandler)(void)){
     Timer3_InterruptHandler=InterruptHandler;
 }
 
  Std_ReturnType EUSART_TX_SetInterruptHandler(void(*InterruptHandler)(void)){
     EUSART_TxInterruptHandler=InterruptHandler;
 }
 
   Std_ReturnType EUSART_RX_SetInterruptHandler(void(*InterruptHandler)(void)){
     EUSART_RxInterruptHandler=InterruptHandler;
 }
   
    Std_ReturnType EUSART_FramingSetInterruptHandler(void(*InterruptHandler)(void)){
     EUSART_FramingErrorHandler=InterruptHandler;
 }
    
     Std_ReturnType EUSART_Overrun_SetInterruptHandler(void(*InterruptHandler)(void)){
     EUSART_OverrunErrorHandler=InterruptHandler;
 }

void ADC_ISR(void){
    ADC_INTERRUPT_CLEAR_FLAG();//clear by software
    //code
  /*call back*/
    if(ADC_InterruptHandler){ADC_InterruptHandler();}
    
}
void Timer0_ISR(void){
   TIMER0_INTERRUPT_CLEAR_FLAG(); //clear by software
   
    //code
   TMR0H=(Timer0_Preload)>>8;
   TMR0L=(uint8_t)(Timer0_Preload);      
  /*call back*/
    if(Timer0_InterruptHandler){Timer0_InterruptHandler();}
    
}
void Timer1_ISR(void){
   TIMER1_INTERRUPT_CLEAR_FLAG(); //clear by software
    //code
   TMR1H=(Timer1_Preload)>>8;
   TMR1L=(uint8_t)(Timer1_Preload);
  /*call back*/
    if(Timer1_InterruptHandler){Timer1_InterruptHandler();}
    
}
void Timer2_ISR(void){
   TIMER2_INTERRUPT_CLEAR_FLAG(); //clear by software
   //code
   TMR2=Timer2_Preload;
  /*call back*/
    if(Timer2_InterruptHandler){Timer2_InterruptHandler();}
    
}
void Timer3_ISR(void){
   TIMER3_INTERRUPT_CLEAR_FLAG(); //clear by software
   //code
   TMR3=Timer3_Preload;
  /*call back*/
    if(Timer3_InterruptHandler){Timer3_InterruptHandler();}
    
}

void EUSART_TX_ISR(void){
    EUSART_TX_INTERRUPT_ENABLE();
    if(EUSART_TxInterruptHandler){
        EUSART_TxInterruptHandler();
    }else { /* Nothing */}
}

void EUSART_RX_ISR(void){
    if(EUSART_RxInterruptHandler){
        EUSART_RxInterruptHandler();
    }else { /* Nothing */}
    if(EUSART_FramingErrorHandler){
        EUSART_FramingErrorHandler();
    }else { /* Nothing */}
    if(EUSART_OverrunErrorHandler){
        EUSART_OverrunErrorHandler();
    }else { /* Nothing */}
}