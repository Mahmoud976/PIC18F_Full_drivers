/* 
 * File:   external_interrupt.h
 * Author: mahmoud saleh
 *
 * Created on December 24, 2023, 8:52 PM
 */

#include"External_Interrupt.h"


static void (*INT0_InterruptHandler)(void)=NULL;
static void (*INT1_InterruptHandler)(void)=NULL;
static void (*INT2_InterruptHandler)(void)=NULL;

static Std_ReturnType INT0_SetInterruptHandler(void(*ptr)(void)){
    Std_ReturnType ret=E_OK;
    if(NULL==ptr)ret=E_NOT_OK;
    else{
       INT0_InterruptHandler=ptr;
    }
}
static Std_ReturnType INT1_SetInterruptHandler(void(*ptr)(void)){
    Std_ReturnType ret=E_OK;
    if(NULL==ptr)ret=E_NOT_OK;
    else{
       INT1_InterruptHandler=ptr;
    }
}
static Std_ReturnType INT2_SetInterruptHandler(void(*ptr)(void)){
    Std_ReturnType ret=E_OK;
    if(NULL==ptr)ret=E_NOT_OK;
    else{
       INT2_InterruptHandler=ptr;
    }
}

static Std_ReturnType Init_Priority_INTx(INTx_Num num,INTx_Priority priority){
    Enable_All_PRIORITY();
    switch(num){
        case INTERRUPT_EXTERNAL_INT1:
            if(INTERRUPT_LOW_LEVEL==priority)CLEAR_BIT(INTCON3,BIT6);
            else if (INTERRUPT_HIGH_LEVEL==priority)SET_BIT(INTCON3,BIT6);
            else return E_NOT_OK;
            break;
        case INTERRUPT_EXTERNAL_INT2:
            if(INTERRUPT_LOW_LEVEL==priority)CLEAR_BIT(INTCON3,BIT7);
            else if (INTERRUPT_HIGH_LEVEL==priority)SET_BIT(INTCON3,BIT7);
            else return E_NOT_OK;
            break;
        default :return E_NOT_OK;
    }
    return E_OK;
}

static Std_ReturnType Interrupt_INTx_SetInterruptHandler(INTx_Num num,void(*ptr)(void)){
    Std_ReturnType ret=E_NOT_OK ;
    if(NULL==ptr)return ret;
    else{
        
        switch(num){
            case INTERRUPT_EXTERNAL_INT0:
                ret=INT0_SetInterruptHandler(ptr);
            break;
            case INTERRUPT_EXTERNAL_INT1:
                ret=INT1_SetInterruptHandler(ptr);
                break;
            case INTERRUPT_EXTERNAL_INT2:
                ret=INT2_SetInterruptHandler(ptr);
                break;
            default: return ret;
        }
    }
    return ret;
}
Std_ReturnType Interrupt_INTx_Init(INTx_Num num,INTx_Edge edge ,INTx_Priority priority){
    if(Enable_General_INT()&&Enable_Peripheral_INT()){
        switch(num){
            case INTERRUPT_EXTERNAL_INT0:
                dio_pin_direction_initialize(INTERRUPT_EXTERNAL_INT0,'B',DIO_INPUT);
                if(INTERRUPT_FALLING_EDGE==edge)CLEAR_BIT(INTCON2,BIT6);
                else if(INTERRUPT_RAISING_EDGE==edge)SET_BIT(INTCON2,BIT6);
                else return E_NOT_OK;
                SET_BIT(INTCON,BIT4);  //enable INT0
                break;
            case INTERRUPT_EXTERNAL_INT1:
                dio_pin_direction_initialize(INTERRUPT_EXTERNAL_INT1,'B',DIO_INPUT);
                if(INTERRUPT_FALLING_EDGE==edge)CLEAR_BIT(INTCON2,BIT5);
                else if(INTERRUPT_RAISING_EDGE==edge)SET_BIT(INTCON2,BIT5);
                else return E_NOT_OK;
                #if INT_ENA_PRIORITY
                Init_Priority_INTx(INTERRUPT_EXTERNAL_INT1,priority);
                #endif
                SET_BIT(INTCON3,BIT3);  //enable INT1
                break;
            case INTERRUPT_EXTERNAL_INT2:
                dio_pin_direction_initialize(INTERRUPT_EXTERNAL_INT1,'B',DIO_INPUT);
                if(INTERRUPT_FALLING_EDGE==edge)CLEAR_BIT(INTCON2,BIT4);
                else if(INTERRUPT_RAISING_EDGE==edge)SET_BIT(INTCON2,BIT4);
                else return E_NOT_OK;
                #if INT_ENA_PRIORITY
                Init_Priority_INTx(INTERRUPT_EXTERNAL_INT2,priority);
                #endif
                SET_BIT(INTCON3,BIT4);  //enable INT2
                break;
            default:return E_NOT_OK; 
        }
         return E_OK;
    }
    else return E_NOT_OK;
}
Std_ReturnType Interrupt_INTx_DeInit(INTx_Num num){
    switch(num){
        case INTERRUPT_EXTERNAL_INT0:
            CLEAR_BIT(INTCON,BIT4); //Disable INT0
            break;
        case INTERRUPT_EXTERNAL_INT1:
            CLEAR_BIT(INTCON3,BIT3); //Disable INT1
            break;
        case INTERRUPT_EXTERNAL_INT2:
            CLEAR_BIT(INTCON3,BIT4); //Disable INT2
            break;
        default: return E_NOT_OK;
    }
    return E_OK;
}

Std_ReturnType Interrupt_INTx(INTx_Num num,INTx_Edge edge ,INTx_Priority priority,void(*ptr)(void)){
   Std_ReturnType ret=E_OK;
    Interrupt_INTx_DeInit(num);
    CLEAR_BIT(INTCON,BIT1);
    CLEAR_BIT(INTCON3,BIT0);
    CLEAR_BIT(INTCON3,BIT1);
    ret=Interrupt_INTx_Init(num,edge,priority);
    ret&=Interrupt_INTx_SetInterruptHandler(num,ptr);
    return ret;
}
 
void INT0_ISR(){
    CLEAR_BIT(INTCON,BIT1); //clear by software
    //code 
    //call back
    if(INT0_InterruptHandler)INT0_InterruptHandler();
}
void INT1_ISR(){
    CLEAR_BIT(INTCON3,BIT0); //clear by software
    //code 
    //call back
    if(INT1_InterruptHandler)INT1_InterruptHandler();
}
void INT2_ISR(){
    CLEAR_BIT(INTCON3,BIT1); //clear by software
    //code 
    //call back
    if(INT2_InterruptHandler)INT2_InterruptHandler();
}
