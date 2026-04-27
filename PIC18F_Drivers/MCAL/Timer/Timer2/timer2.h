/* 
 * File:   timer2.h
 * Author: mahmo
 *
 * Created on June 16, 2023, 12:28 AM
 */

#ifndef TIMER2_H
#define	TIMER2_H

/*********************Section : Includes ******************************************/


#include"../../../Utilities/Registers/registers.h"
#include"../../Interrupt/Internal_Interrupt.h"

/*********************Section : Macro Declarations ********************************/
#define PRESCALER_ENABLE      1
#define PRESCALER_DISABLE     0

typedef enum{
    TIMER2_PRESCALER_DIV_BY_1=0,
    TIMER2_PRESCALER_DIV_BY_4,
    TIMER2_PRESCALER_DIV_BY_16,      
}timer2_prescaler_select_t;

typedef enum{
    TIMER2_POSTSCALER_DIV_BY_1=0,
    TIMER2_POSTSCALER_DIV_BY_2,
    TIMER2_POSTSCALER_DIV_BY_3,
    TIMER2_POSTSCALER_DIV_BY_4,
    TIMER2_POSTSCALER_DIV_BY_5,
    TIMER2_POSTSCALER_DIV_BY_6,
    TIMER2_POSTSCALER_DIV_BY_7,
    TIMER2_POSTSCALER_DIV_BY_8,
    TIMER2_POSTSCALER_DIV_BY_9,
    TIMER2_POSTSCALER_DIV_BY_10,
    TIMER2_POSTSCALER_DIV_BY_11,
    TIMER2_POSTSCALER_DIV_BY_12,
    TIMER2_POSTSCALER_DIV_BY_13,
    TIMER2_POSTSCALER_DIV_BY_14,
    TIMER2_POSTSCALER_DIV_BY_15,
    TIMER2_POSTSCALER_DIV_BY_16,
            
}timer2_postscaler_select_t;
typedef union{
    struct{
     unsigned T2CKPS    :2;
     unsigned TMR2ON    :1;
     unsigned T2OUTPS   :4;
     unsigned           :1; 
    };
    
}T2CONBIT_t;
 
extern volatile T2CONBIT_t T2CONBIT  __at(0xFCA);


#define TIMER2_MODULE_ENABLE()         (T2CONBIT.TMR2ON=1)
#define TIMER2_MODULE_DISABLE()        (T2CONBIT.TMR2ON=0)  




/*********************Section : Data Type Declarations ****************************/


/*********************Section : Function Declarations *****************************/
#if DISABLE_INTERRUPT 

Std_ReturnType Timer2_Init(uint8_t Preload,timer2_prescaler_select_t prescaler,timer2_postscaler_select_t postscaler);
Std_ReturnType Timer2_DeInit();
Std_ReturnType Timer2_delay();

#endif

Std_ReturnType Timer2_Write_Value(uint8_t value);
Std_ReturnType Timer2_Read_Value(uint8_t * value);
#if ENABLE_INTERRUPT
Std_ReturnType Timer2_Init(void (*TIMER2)(void),interrupt_priority priority,uint8_t Preload,timer2_prescaler_select_t prescaler,timer2_postscaler_select_t postscaler);
Std_ReturnType Timer2_DeInit();
#endif


#endif	/* TIMER2_H */

