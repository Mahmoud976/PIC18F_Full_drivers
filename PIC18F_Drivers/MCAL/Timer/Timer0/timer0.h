/* 
 * File:   timer0.h
 * Author: mahmoud saleh
 *
 * Created on May 29, 2023, 5:21 PM
 */

#ifndef TIMER0_H
#define	TIMER0_H


/*********************Section : Includes ******************************************/


#include"../../../Utilities/Registers/registers.h"
#include"../../Interrupt/Internal_Interrupt.h"

/*********************Section : Macro Declarations ********************************/
#define timer_mode       0x00  
#define counter_mode     0x01

#define timer0_Raising       0x00
#define timer0_Falling       0x01  

#define PRESCALER_ENABLE      1
#define PRESCALER_DISABLE     0

typedef enum{
    TIMER0_PRESCALER_DIV_BY_2=0,
    TIMER0_PRESCALER_DIV_BY_4,
    TIMER0_PRESCALER_DIV_BY_8,
    TIMER0_PRESCALER_DIV_BY_16,
    TIMER0_PRESCALER_DIV_BY_32,
    TIMER0_PRESCALER_DIV_BY_64,
    TIMER0_PRESCALER_DIV_BY_128,        
    TIMER0_PRESCALER_DIV_BY_256        
}timer0_prescaler_select_t;

typedef union {
    struct {
     unsigned T0PS     :3;
     unsigned PSA      :1;
     unsigned T0SE     :1;
     unsigned T0CS     :1;
     unsigned T08BIT   :1;
     unsigned TMR0ON   :1;
    };
}T0CONBIT_t;
 
extern volatile T0CONBIT_t T0CONBIT  __at(0xFD5);
/*********************Section : Macro Functions Declarations **********************/
#define TIMER0_MODULE_ENABLE()    (T0CONBIT.TMR0ON=1)
#define TIMER0_MODULE_DISABLE()   (T0CONBIT.TMR0ON=0)

#define TIMER0_PRESCALER_ENABLE()    (T0CONBIT.PSA=0)
#define TIMER0_PRESCALER_DISABLE()   (T0CONBIT.PSA=1)

#define TIMER0_RISING_EDGE_ENABLE()   (T0CONBIT.T0SE=0)
#define TIMER0_FALLING_EDGE_ENABLE()   (T0CONBIT.T0SE=1)

#define TIMER0_TIMER_MODE_ENABLE()     (T0CONBIT.T0CS=0)
#define TIMER0_COUNTER_MODE_ENABLE()   (T0CONBIT.T0CS=1)

#define TIMER0_8BIT_REGISTER_MODE_ENABLE()    (T0CONBIT.T08BIT=1)
#define TIMER0_16BIT_REGISTER_MODE_ENABLE()   (T0CONBIT.T08BIT=0)

/*********************Section : Data Type Declarations ****************************/


/*********************Section : Function Declarations *****************************/
#if DISABLE_INTERRUPT == 1
Std_ReturnType Timer0_Init(uint8_t size ,uint8_t Timer0_mode,uint16_t Preload,uint8_t TMR0_Counter_edge,uint8_t Pre_Enable,timer0_prescaler_select_t prescaler);
Std_ReturnType Timer0_DeInit();
Std_ReturnType Timer0_delay();
#endif

Std_ReturnType Timer0_Write_Value(uint16_t value);
Std_ReturnType Timer0_Read_Value(uint16_t * value);

#if ENABLE_INTERRUPT == 1
Std_ReturnType Timer0_Init(void (*TIMER)(void),interrupt_priority priority,uint8_t size ,uint8_t Timer0_mode,uint16_t Preload,uint8_t TMR0_Counter_edge,uint8_t Pre_Enable,timer0_prescaler_select_t prescaler);
Std_ReturnType Timer0_DeInit();
#endif

#endif	/* TIMER0_H */

