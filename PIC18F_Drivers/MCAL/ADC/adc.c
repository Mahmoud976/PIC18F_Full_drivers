/* 
 * File:   adc.c
 * Author: mahmoud saleh
 *
 * Created on April 30, 2023, 5:00 PM
 */
#include"adc.h"




static inline void select_result_format(uint8_t format);
static inline void adc_input(Channels_Selected channel);
static inline void select_voltage(uint8_t voltage);

#if DISABLE_INTERRUPT
Std_ReturnType ADC_Init(Acquisition_Time time,Conversion_Clock cycle ,Channels_Selected channel,uint8_t format,uint8_t voltage){
    //Disable ADC
    DISABLE_ADC();
    //configure the acquisition time
    ADCON2BIT.ACQT = time;
    //configure the conversion clock
    ADCON2BIT.ADCS =cycle;
    //configure the default channel
    ADCON0BIT.CHS=channel;
    adc_input(channel);
    //configure the result format
    select_result_format(format);
    //configure the voltage reference
     select_voltage(voltage);
    //Enable ADC
    ENABLE_ADC();
    return E_OK;
}
Std_ReturnType ADC_Deinit(){
    //Disable ADC
    DISABLE_ADC();
    
    return E_OK;
}

Std_ReturnType ADC_Get_Conversion_Blocking(uint8_t channel,uint8_t format,uint16_t *result){
    Std_ReturnType ret =ADC_Select_channel(channel);
    ret =ADC_Start_Conversion();
    while(ADCON0BIT.GO)
    ret=ADC_Get_Result(format,result);
   
    return ret;
}
#endif
#if ENABLE_INTERRUPT 

Std_ReturnType ADC_Init(void (*ADC)(void),interrupt_priority priority,Acquisition_Time time,Conversion_Clock cycle ,Channels_Selected channel,uint8_t format,uint8_t voltage){
   Std_ReturnType ret=E_OK;
    if(NULL == ADC)ret = E_NOT_OK;
    //Disable ADC
    DISABLE_ADC();
    //configure the acquisition time
    ADCON2BIT.ACQT = time;
    //configure the conversion clock
    ADCON2BIT.ADCS =cycle;
    //configure the default channel
    ADCON0BIT.CHS=channel;
    adc_input(channel);
    //configure the interrupt
    Enable_General_INT();
    ADC_INTERRUPT_ENABLE();
   #if ENABLE_PRIORITY
    ENABLE_ALL_PRIORITY();
    ADC_INTERRUPT_ENABLE();
    if(priority==INTERRUPT_HIGH_PRIORITY)
        ADC_SET_HIGH_PRIORITY(); //enable priority HIGH
    else if(priority==INTERRUPT_LOW_PRIORITY)
        ADC_SET_LOW_PRIORITY(); //enable priority LOW
    #endif
    ADC_INTERRUPT_CLEAR_FLAG();
    ADC_SetInterruptHandler(ADC);  
    //configure the result format
    select_result_format(format);
    //configure the voltage reference
     select_voltage(voltage);
    //Enable ADC
    ENABLE_ADC();
    return ret;
}
Std_ReturnType ADC_Deinit(){
    //Disable ADC
    DISABLE_ADC();
    //configure the interrupt
    ADC_INTERRUPT_DISABLE();
    return E_OK;
}

Std_ReturnType ADC_Start_Conversion_Iterrupt(uint8_t channel){
    Std_ReturnType ret=ADC_Select_channel(channel);
    ret&=ADC_Start_Conversion();
    return ret;
    
}
#endif

Std_ReturnType ADC_Select_channel(uint8_t channel){
    ADCON0BIT.CHS = channel;
    adc_input(channel);
    return E_OK;
}

Std_ReturnType ADC_Start_Conversion(){
    START_CONVERSION();
    return E_OK;
}

Std_ReturnType ADC_Conversion_done(uint8_t * status){
   Std_ReturnType ret=E_OK;
   if(NULL==status)ret= E_NOT_OK;
   else{
   * status=(uint8_t)(!(ADCON0BIT.GO));
   
   }
   
   return ret;
}

Std_ReturnType ADC_Get_Result(uint8_t format, uint16_t *result){
 Std_ReturnType ret =E_OK;
  if(NULL== result) ret = E_NOT_OK; 
  else {
      if(1==format){
          * result=(uint16_t)((ADRESH<<8)+(ADRESL));
      }
      else{* result=(uint16_t)(((ADRESH<<8)+(ADRESL))>>6);}
  
  } 
  return ret;
}



static inline void adc_input(Channels_Selected channel){
    switch(channel){
        case ANA0  :dio_pin_direction_initialize(0,'A',DIO_INPUT);       break;
        case ANA1  :dio_pin_direction_initialize(1,'A',DIO_INPUT);       break;
        case ANA2  :dio_pin_direction_initialize(2,'A',DIO_INPUT);       break;
        case ANA3  :dio_pin_direction_initialize(3,'A',DIO_INPUT);       break;
        case ANA4  :dio_pin_direction_initialize(5,'A',DIO_INPUT);       break;
        case ANA5  :dio_pin_direction_initialize(0,'E',DIO_INPUT);       break;
        case ANA6  :dio_pin_direction_initialize(1,'E',DIO_INPUT);       break;
        case ANA7  :dio_pin_direction_initialize(2,'E',DIO_INPUT);       break;
        case ANA8  :dio_pin_direction_initialize(2,'B',DIO_INPUT);       break;
        case ANA9  :dio_pin_direction_initialize(3,'B',DIO_INPUT);       break;
        case ANA10 :dio_pin_direction_initialize(1,'B',DIO_INPUT);       break;
        case ANA11 :dio_pin_direction_initialize(4,'B',DIO_INPUT);       break;
        case ANA12 :dio_pin_direction_initialize(0,'B',DIO_INPUT);       break;
           
    }
}

static inline void select_result_format(uint8_t format){
    if(format)RIGHT_JUSTIFIED();
    else  LEFT_JUSTIFIED();   
    
}

static inline void select_voltage(uint8_t voltage){
    if(voltage){NEGATIVE_POWER_OUT();POSITIVE_POWER_OUT();}
    else  {NEGATIVE_POWER_IN();POSITIVE_POWER_IN();}

}