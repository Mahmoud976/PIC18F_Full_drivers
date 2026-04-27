/* 
 * File:   adc_cfg.h
 * Author: mahmo
 *
 * Created on April 30, 2023, 5:01 PM
 */

#ifndef ADC_CFG_H
#define	ADC_CFG_H

/******************** Section : Includes *************************************** */
#include"../Interrupt/Internal_Interrupt.h"
/* *******************Section : Macro Declarations *******************************/

/********************Section : Macro Functions Declarations ******************** */
#define NEGATIVE_POWER_OUT()         SET_BIT(ADCON1,5)  
#define POSITIVE_POWER_OUT()         SET_BIT(ADCON1,4) 

#define NEGATIVE_POWER_IN()         CLEAR_BIT(ADCON1,5)  
#define POSITIVE_POWER_IN()         CLEAR_BIT(ADCON1,4)

#define RIGHT_JUSTIFIED()           SET_BIT(ADCON2,7)
#define LEFT_JUSTIFIED()            CLEAR_BIT(ADCON2,7)


/******************* Section : Data Type Declarations ****************************/
/******************** Section : Function Declarations ****************************/


#endif	/* ADC_CFG_H */

