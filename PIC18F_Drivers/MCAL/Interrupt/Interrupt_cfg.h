/* 
 * File:   Interrupt_cfg.h
 * Author: mahmo
 *
 * Created on April 10, 2023, 11:59 PM
 */

#ifndef INTERRUPT_CFG_H
#define	INTERRUPT_CFG_H

/* Section : Includes */
#include"../../Utilities/Registers/registers.h"
#include"../DIO_Driver/dio.h"


/* Section : Macro Declarations */
#define BIT_MASK           (uint8_t)0x01

#define ENABLE_PRIORITY  1
#define DISABLE_PRIORITY  0


#define INT_ENA_PROIRTY    ENABLE_PRIORITY
#define INT_DIS_PROIRTY    DISABLE_PRIORITY

#define ENABLE_INTERRUPT            0x01
#define DISABLE_INTERRUPT           0x00

#define ADC_ENABLE      1
#define ADC_DISABLE     0

#define TIMER0_ENABLE      1
#define TIMER0_DISABLE     0

#define TIMER1_ENABLE      1
#define TIMER1_DISABLE     0

#define TIMER2_ENABLE      1
#define TIMER2_DISABLE     0

#define TIMER3_ENABLE      1
#define TIMER3_DISABLE     0

#define EUSART_TX_ENABLE      1
#define EUSART_TX_DISABLE     0

#define EUSART_RX_ENABLE      1
#define EUSART_RX_DISABLE     0
/*  Section : Macro Functions Declarations */

/* Section : Data Type Declarations */
typedef enum{
    INTERRUPT_LOW_PRIORITY=0,
    INTERRUPT_HIGH_PRIORITY        
}interrupt_priority;



/* Section : Function Declarations */

#endif	/* INTERRUPT_CFG_H */

