/* 
 * File:   adc.h
 * Author: mahmoud saleh
 *
 * Created on April 30, 2023, 5:00 PM
 */

#ifndef ADC_H
#define	ADC_H

/*********************Section : Includes ******************************************/
#include"adc_cfg.h"


/* *******************Section : Macro Declarations ********************************/
#define AN0    0X0E
#define AN1    0X0D
#define AN2    0X0C
#define AN3    0X0B
#define AN4    0X0A
#define AN5    0X09
#define AN6    0X08
#define AN7    0X07
#define AN8    0X06
#define AN9    0X05
#define AN10   0X04
#define AN1    0X03
#define AN12   0X02
#define ALL_ANALOG    0X01
#define ALL_DIGITAL   0X0F
typedef enum{
    ANA0=0,
    ANA1,
    ANA2,
    ANA3,
    ANA4,
    ANA5,
    ANA6,
    ANA7,
    ANA8,
    ANA9,
    ANA10,
    ANA11,
    ANA12
}Channels_Selected;

typedef enum{
    ADC_0_TAD=0,
    ADC_2_TAD,
    ADC_4_TAD,
    ADC_6_TAD,
    ADC_8_TAD,
    ADC_12_TAD,
    ADC_16_TAD,
    ADC_20_TAD
}Acquisition_Time;
typedef enum{
    ADC_CLOCK_FOSE_DIV_2=0,
    ADC_CLOCK_FOSE_DIV_8,
    ADC_CLOCK_FOSE_DIV_32,
    ADC_CLOCK_FOSE_DIV_FRC,
    ADC_CLOCK_FOSE_DIV_4,
    ADC_CLOCK_FOSE_DIV_16,
    ADC_CLOCK_FOSE_DIV_64,
}Conversion_Clock;
typedef union {
    struct {
     unsigned ADON   :1;
     unsigned GO     :1;
     unsigned CHS    :4;
    };
    
    
}ADCON0BIT_t;

extern volatile ADCON0BIT_t ADCON0BIT  __at(0xFC2);

typedef union {
    struct {
     unsigned ADCS   :3;
     unsigned ACQT   :3;
     unsigned        :1;
     unsigned ADFM   :1;
    };
    struct {
     unsigned ADCS0   :1;
     unsigned ADCS1   :1;
     unsigned ADCS2   :1;
     unsigned ACQT0   :1;
     unsigned ACQT1   :1;
     unsigned ACQT2   :1;
    };
    
}ADCON2BIT_t;

extern volatile ADCON2BIT_t ADCON2BIT  __at(0xFC0);
/*********************Section : Macro Functions Declarations **********************/
#define BIT_MASK                   (uint8_t)0x01
#define SET_BIT(REG,BIT_POSN)               (REG |= (BIT_MASK << BIT_POSN))
#define CLEAR_BIT(REG,BIT_POSN)             (REG &= ~(BIT_MASK << BIT_POSN))
#define READ_BIT(REG,BIT_POSN)              ((REG >> BIT_POSN)& BIT_MASK)

#define ENABLE_ADC()              SET_BIT(ADCON0,0) 
#define DISABLE_ADC()             CLEAR_BIT(ADCON0,0)

#define START_CONVERSION()        SET_BIT(ADCON0,1)
#define READ_ADC()                READ_BIT(ADCON0,1) //if i ADC still work else it finished


 
/*********************Section : Data Type Declarations ****************************/

/*********************Section : Function Declarations *****************************/
#if DISABLE_INTERRUPT 
Std_ReturnType ADC_Init(Acquisition_Time time,Conversion_Clock cycle,Channels_Selected channel,uint8_t format,uint8_t voltage);
Std_ReturnType ADC_Deinit();
Std_ReturnType ADC_Get_Conversion_Blocking(uint8_t channel,uint8_t format,uint16_t *result);
#endif
Std_ReturnType ADC_Select_channel(uint8_t channel);
Std_ReturnType ADC_Start_Conversion();
Std_ReturnType ADC_Conversion_done(uint8_t * status);
Std_ReturnType ADC_Get_Result(uint8_t format, uint16_t *result);


#if ENABLE_INTERRUPT
Std_ReturnType ADC_Init(void (*ADC)(void),interrupt_priority priority,Acquisition_Time time,Conversion_Clock cycle,Channels_Selected channel,uint8_t format,uint8_t voltage);
Std_ReturnType ADC_Deinit();
Std_ReturnType ADC_Start_Conversion_Iterrupt(uint8_t channel);
#endif

#endif	/* ADC_H */


