/* 
 * File:   timer1.h
 * Author: mahmo
 *
 * Created on June 6, 2023, 8:49 PM
 */

#ifndef TIMER1_H
#define	TIMER1_H

/*********************Section : Includes ******************************************/


#include"../../../Utilities/Registers/registers.h"
#include"../../Interrupt/Internal_Interrupt.h"

/*********************Section : Macro Declarations ********************************/
#define timer_mode       0x00  
#define counter_mode     0x01
  
typedef enum{
    TIMER1_PRESCALER_DIV_BY_1=0,
    TIMER1_PRESCALER_DIV_BY_2,
    TIMER1_PRESCALER_DIV_BY_4,
    TIMER1_PRESCALER_DIV_BY_8,      
}timer1_prescaler_select_t;

typedef union{
    struct{
     unsigned TMR1ON     :1;
     unsigned TMR1CS     :1;
     unsigned T1SYNC     :1;
     unsigned T1OSCEN    :1; 
     unsigned T1CKPS     :2;
     unsigned T1RUN      :1;
     unsigned RD16       :1;
    };
    
}T1CONBIT_t;
 
extern volatile T1CONBIT_t T1CONBIT  __at(0xFCD);


#define TIMER1_MODULE_ENABLE()         (T1CONBIT.TMR1ON=1)
#define TIMER1_MODULE_DISABLE()        (T1CONBIT.TMR1ON=0)

#define TIMER1_TIMER_MODE_ENABLE()     (T1CONBIT.TMR1CS=0)
#define TIMER1_COUNTER_MODE_ENABLE()   (T1CONBIT.TMR1CS=1)

#define TIMER1_Synchronize_ENABLE()    (T1CONBIT.T1SYNC=0)//active low 
#define TIMER1_Synchronize_DISABLE()   (T1CONBIT.T1SYNC=1)//active low

#define TIMER1_Oscillator_ENABLE()    (T1CONBIT.T1OSCEN=1)
#define TIMER1_Oscillator_DISABLE()   (T1CONBIT.T1OSCEN=0)

 
#define check_TIMER1_System_Clock_Status()    (READ_BIT(T1CON,6))  

#define TIMER1_RAED_WRITE_MODE_16()     (T1CONBIT.RD16=1)
#define TIMER1_RAED_WRITE_MODE_8()      (T1CONBIT.RD16=0)


/*********************Section : Data Type Declarations ****************************/


/*********************Section : Function Declarations *****************************/
#if DISABLE_INTERRUPT 

Std_ReturnType Timer1_Init(uint8_t Oscillator,uint8_t Timer1_mode,uint8_t ASY,uint16_t Preload,timer1_prescaler_select_t prescaler);
Std_ReturnType Timer1_DeInit();
Std_ReturnType Timer1_delay();

#endif

Std_ReturnType Timer1_Write_Value(uint16_t value);
Std_ReturnType Timer1_Read_Value(uint16_t * value);
//Std_ReturnType delay(uint16_t value);
#if ENABLE_INTERRUPT
Std_ReturnType Timer1_Init(void (*TIMER1)(void),interrupt_priority priority,uint8_t Oscillator,uint8_t Timer1_mode,uint8_t ASY,uint16_t Preload,timer1_prescaler_select_t prescaler);
Std_ReturnType Timer1_DeInit();
#endif


#endif	/* TIMER1_H */

