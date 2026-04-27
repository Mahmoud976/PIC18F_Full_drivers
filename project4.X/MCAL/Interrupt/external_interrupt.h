/* 
 * File:   external_interrupt.h
 * Author: mahmoud saleh
 *
 * Created on December 24, 2023, 8:52 PM
 */

#ifndef EXTERNAL_INTERRUPT_H
#define	EXTERNAL_INTERRUPT_H
/* Section : Includes */
#include"Interrupt_cfg.h"
/* Section : Macro Declarations */
/*  Section : Macro Functions Declarations */
#if INT_ENA_PRIORITY
#define Enable_All_High_Priority_INT()           (SET_BIT(INTCON,BIT7))
#define Disable_General_INT()                    (CLEAR_BIT(INTCON,BIT7))
#else
#define Enable_General_INT()                     (SET_BIT(INTCON,BIT7))
#define Disable_General_INT()                    (CLEAR_BIT(INTCON,BIT7))
#endif
#if INT_ENA_PRIORITY
#define Enable_All_Low_Priority_INT()            (SET_BIT(INTCON,BIT6))
#define Disable_All_Low_Priority_INT()           (CLEAR_BIT(INTCON,BIT6))
#else
#define Enable_Peripheral_INT()                  (SET_BIT(INTCON,BIT6))
#define Disable_Peripheral_INT()                 (CLEAR_BIT(INTCON,BIT6))
#endif

#define Enable_All_PRIORITY()                    (SET_BIT(RCON,BIT7))
#define Disable_All_PRIORITY()                    (CLEAR_BIT(RCON,BIT7))
/* Section : Data Type Declarations */
typedef enum{
    BIT0=0,
    BIT1,
    BIT2,
    BIT3,
    BIT4,
    BIT5,
    BIT6,
    BIT7
}Bits;

typedef enum{
    INTERRUPT_LOW_LEVEL=0,
    INTERRUPT_HIGH_LEVEL
}INTx_Priority;        
typedef enum{
    INTERRUPT_FALLING_EDGE=0,
    INTERRUPT_RAISING_EDGE
}INTx_Edge;
typedef enum{
    INTERRUPT_EXTERNAL_INT0=0,
    INTERRUPT_EXTERNAL_INT1,
    INTERRUPT_EXTERNAL_INT2
}INTx_Num;

typedef union{
    struct{
        uint8_t RBIF    :1;
        uint8_t INT0IF  :1;
        uint8_t TMR0IF  :1;
        uint8_t RBIE    :1;
        uint8_t INT0IE  :1;
        uint8_t TMR0IE  :1;
        #if INT_ENA_PRIORITY
        uint8_t GIEL  :1;
        #else
        uint8_t PEIE  :1;
        #endif
        #if INT_ENA_PRIORITY
        uint8_t GIEH  :1;
        #else
        uint8_t GIE  :1;
        #endif
    };
}INTCONBits;
/* Section : Function Declarations */
Std_ReturnType Interrupt_INTx_Init(INTx_Num num,INTx_Edge edge ,INTx_Priority priority);
Std_ReturnType Interrupt_INTx_DeInit(INTx_Num num);
Std_ReturnType Interrupt_INTx(INTx_Num num,INTx_Edge edge ,INTx_Priority priority,void(*ptr)(void));
void INT0_ISR();
void INT1_ISR();      
void INT2_ISR();
#endif	/* EXTERNAL_INTERRUPT_H */

