/* 
 * File:   External_Interrupt.h
 * Author: mahmoud saleh
 *
 *
 * Created on April 11, 2023, 12:01 AM
 */

#ifndef EXTERNAL_INTERRUPT_H
#define	EXTERNAL_INTERRUPT_H
/* Section : Includes */
#include"Interrupt_cfg.h"


/* Section : Macro Declarations */

/*  Section : Macro Functions Declarations */
#define SET_BIT(REG,BIT_POSN)                 (REG |= (BIT_MASK << BIT_POSN))
#define CLEAR_BIT(REG,BIT_POSN)               (REG &= ~(BIT_MASK << BIT_POSN))
#define READ_BIT(REG,BIT_POSN)                ((REG >> BIT_POSN)& BIT_MASK)

#define Enable_General_INT()                  (SET_BIT(INTCON,BIT7))
#define Disable_General_INT()                 (CLEAR_BIT(INTCON,BIT7))

#define Enable_Peripheral_INT()               (SET_BIT(INTCON,BIT6))
#define Disable_Peripheral_INT()              (CLEAR_BIT(INTCON,BIT6))

#define ENABLE_ALL_PRIORITY()                 (SET_BIT(RCON,BIT7))
#define Disable_ALL_Priority()                (CLEAR_BIT(RCON,BIT7))


#define Interrupt_RBx_Init()                  (SET_BIT(INTCON,BIT3))
#define Interrupt_RBx_Deinit()                (CLEAR_BIT(INTCON,BIT3))

#define Init_Priority_RBx_High()              (SET_BIT(INTCON2,BIT0))
#define init_Priority_RBx_Low()               (CLEAR_BIT(INTCON2,BIT0))


/* Section : Data Type Declarations */

typedef enum{
    BIT0 =0,
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
    INTERRUPT_HIGH_LEVEL,
}INTx_Proirity;

typedef enum{
    INTERRUPT_FALLING_EDGE=0,
    INTERRUPT_RAISING_EDGE,
}INTx_edge;
typedef enum{
    INTERRUPT_EXTERNAL_INT0=0,
    INTERRUPT_EXTERNAL_INT1,
    INTERRUPT_EXTERNAL_INT2,
}INTx_NUM;
typedef enum{
    INTERRUPT_EXTERNAL_PIN4=4,
    INTERRUPT_EXTERNAL_PIN5,
    INTERRUPT_EXTERNAL_PIN6,
    INTERRUPT_EXTERNAL_PIN7,
}RBx_NUM;
/* Section : Function Declarations */
Std_ReturnType Interrupt_INTx_Init(INTx_NUM num,INTx_edge edge,interrupt_priority priority);
Std_ReturnType Interrupt_INTx_Deinit(INTx_NUM num);

Std_ReturnType Interrupt_INTx(INTx_NUM num,INTx_edge edge,interrupt_priority priority,void(*ptr)(void));
void INT0_ISR();
void INT1_ISR();
void INT2_ISR();

Std_ReturnType Interrupt_RBx(RBx_NUM num,interrupt_priority priority,void(*ptr0)(void),void(*ptr1)(void));
void RB4_ISR_High();
void RB4_ISR_Low();

void RB5_ISR_High();
void RB5_ISR_Low();

void RB6_ISR_High();
void RB6_ISR_Low();

void RB7_ISR_High();
void RB7_ISR_Low();

#endif	/* EXTERNAL_INTERRUPT_H */

