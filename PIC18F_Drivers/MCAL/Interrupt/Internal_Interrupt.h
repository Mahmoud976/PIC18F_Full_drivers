/* 
 * File:   Internal_Interrupt.h
 * Author: mahmo
 *
 * Created on April 11, 2023, 12:00 AM
 */

#ifndef INTERNAL_INTERRUPT_H
#define	INTERNAL_INTERRUPT_H

/******************** Section : Includes *****************************************/
#include"Interrupt_cfg.h"


/*********************Section : Macro Declarations *******************************/


/********************Section : Macro Functions Declarations **********************/
#define SET_BIT(REG,BIT_POSN)                 (REG |= (BIT_MASK << BIT_POSN))
#define CLEAR_BIT(REG,BIT_POSN)               (REG &= ~(BIT_MASK << BIT_POSN))
#define READ_BIT(REG,BIT_POSN)                ((REG >> BIT_POSN)& BIT_MASK)

#define Enable_General_INT()                  (SET_BIT(INTCON,7))
#define Disable_General_INT()                 (CLEAR_BIT(INTCON,7))

#define ENABLE_ALL_PRIORITY()                 (SET_BIT(RCON,7))
#define Disable_ALL_Priority()                (CLEAR_BIT(RCON,7))

#if ADC_ENABLE
#define ADC_INTERRUPT_DISABLE()          (CLEAR_BIT(PIE1,6))
#define ADC_INTERRUPT_ENABLE()           (SET_BIT(PIE1,6))
#define ADC_INTERRUPT_CLEAR_FLAG()       (CLEAR_BIT(PIR1,6))

#if ENABLE_PRIORITY
#define ADC_SET_HIGH_PRIORITY()           (SET_BIT(IPR1,6))
#define ADC_SET_LOW_PRIORITY()            (CLEAR_BIT(IPR1,6))
#endif

#endif

#if TIMER0_ENABLE ==1

#define TIMER0_INTERRUPT_DISABLE()          (CLEAR_BIT(INTCON,5))
#define TIMER0_INTERRUPT_ENABLE()           (SET_BIT(INTCON,5))
#define TIMER0_INTERRUPT_CLEAR_FLAG()       (CLEAR_BIT(INTCON,2))

#if ENABLE_PRIORITY
#define TIMER0_SET_HIGH_PRIORITY()           (SET_BIT(INTCON2,2))
#define TIMER0_SET_LOW_PRIORITY()            (CLEAR_BIT(INTCON2,2))
#endif

#endif

#if TIMER1_ENABLE ==1

#define TIMER1_INTERRUPT_DISABLE()          (CLEAR_BIT(PIE1,0))
#define TIMER1_INTERRUPT_ENABLE()           (SET_BIT(PIE1,0))
#define TIMER1_INTERRUPT_CLEAR_FLAG()       (CLEAR_BIT(PIR1,0))

#if ENABLE_PRIORITY
#define TIMER1_SET_HIGH_PRIORITY()           (SET_BIT(IPR1,0))
#define TIMER1_SET_LOW_PRIORITY()            (CLEAR_BIT(IPR1,0))
#endif

#endif

#if TIMER2_ENABLE
#define TIMER2_INTERRUPT_DISABLE()          (CLEAR_BIT(PIE1,1))
#define TIMER2_INTERRUPT_ENABLE()           (SET_BIT(PIE1,1))
#define TIMER2_INTERRUPT_CLEAR_FLAG()       (CLEAR_BIT(PIR1,1))

#if ENABLE_PRIORITY
#define TIMER2_SET_HIGH_PRIORITY()           (SET_BIT(IPR1,1))
#define TIMER2_SET_LOW_PRIORITY()            (CLEAR_BIT(IPR1,1))
#endif

#endif

#if TIMER3_ENABLE
#define TIMER3_INTERRUPT_DISABLE()          (CLEAR_BIT(PIE2,1))
#define TIMER3_INTERRUPT_ENABLE()           (SET_BIT(PIE2,1))
#define TIMER3_INTERRUPT_CLEAR_FLAG()       (CLEAR_BIT(PIR2,1))

#if ENABLE_PRIORITY
#define TIMER3_SET_HIGH_PRIORITY()           (SET_BIT(IPR2,1))
#define TIMER3_SET_LOW_PRIORITY()            (CLEAR_BIT(IPR2,1))
#endif

#endif

#if EUSART_TX_ENABLE

#define EUSART_TX_INTERRUPT_DISABLE()          (CLEAR_BIT(PIE1,4))
#define EUSART_TX_INTERRUPT_ENABLE()           (SET_BIT(PIE1,4 ))
// #define EUSART_TX_INTERRUPT_CLEAR_FLAG()       (CLEAR_BIT(PIR1,4)) but it clear when write new data by default not manual

#if ENABLE_PRIORITY
#define EUSART_TX_SET_HIGH_PRIORITY()           (SET_BIT(IPR1,4))
#define EUSART_TX_SET_LOW_PRIORITY()            (CLEAR_BIT(IPR1,4))
#endif
#endif
#if EUSART_RX_ENABLE 
#define EUSART_RX_INTERRUPT_DISABLE()          (CLEAR_BIT(PIE1,5))
#define EUSART_RX_INTERRUPT_ENABLE()           (SET_BIT(PIE1,5 ))
// #define EUSART_RX_INTERRUPT_CLEAR_FLAG()       (CLEAR_BIT(PIR1,5)) but it clear when read new data by default not manual

#if ENABLE_PRIORITY
#define EUSART_RX_SET_HIGH_PRIORITY()           (SET_BIT(IPR1,5))
#define EUSART_RX_SET_LOW_PRIORITY()            (CLEAR_BIT(IPR1,5))
#endif
#endif
/******************* Section : Data Type Declarations ****************************/
typedef enum{
    LOW=0,
    HIGH
            
}interrupt_priority_cfg;

/******************** Section : Function Declarations ****************************/
 Std_ReturnType ADC_SetInterruptHandler(void(*InterruptHandler)(void));
 Std_ReturnType Timer0_SetInterruptHandler(void(*InterruptHandler)(void));
 Std_ReturnType Timer1_SetInterruptHandler(void(*InterruptHandler)(void));
 Std_ReturnType Timer2_SetInterruptHandler(void(*InterruptHandler)(void));
 Std_ReturnType Timer3_SetInterruptHandler(void(*InterruptHandler)(void));
 Std_ReturnType EUSART_TX_SetInterruptHandler(void(*InterruptHandler)(void));
 Std_ReturnType EUSART_RX_SetInterruptHandler(void(*InterruptHandler)(void));
 Std_ReturnType EUSART_FramingSetInterruptHandler(void(*InterruptHandler)(void));
 Std_ReturnType EUSART_Overrun_SetInterruptHandler(void(*InterruptHandler)(void));
 
 
 void ADC_ISR(void);
 void Timer0_ISR(void);
 void Timer1_ISR(void);
 void Timer2_ISR(void);
 void Timer3_ISR(void);
 
 void EUSART_TX_ISR(void);
 void EUSART_RX_ISR(void);

#endif	/* INTERNAL_INTERRUPT_H */

