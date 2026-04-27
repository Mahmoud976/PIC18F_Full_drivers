/* 
 * File:   interrupt_cfg.h
 * Author: mahmo
 *
 * Created on December 23, 2023, 8:53 PM
 */

#ifndef INTERRUPT_CFG_H
#define	INTERRUPT_CFG_H

/* Section : Includes */
#include"../DIO_Driver/dio.h"
/* Section : Macro Declarations */

#define ENABLE_PRIORITY   0
#define DISABLE_PRIORITY   0

#define INT_ENA_PRIORITY     ENABLE_PRIORITY 
#define INT_DIS_PRIORITY     DISABLE_PRIORITY 

#define ENABLE_INTERRUPT       0x01  
#define DISABLE_INTERRUPT      0x01
/*  Section : Macro Functions Declarations */

/* Section : Data Type Declarations */
typedef enum{
    INTERRUPT_LOW_PROORITY=0,
    INTERRUPT_HIGH_PROORITY        
}interrupt_priority;

/* Section : Function Declarations */

#endif	/* INTERRUPT_CFG_H */

