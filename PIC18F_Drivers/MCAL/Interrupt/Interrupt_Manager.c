
/* 
 * File:   Interrupt_Manager.h
 * Author: mahmoud saleh
 *
 * Created on April 11, 2023, 12:07 AM
 */

#include"Interrupt_Manager.h"


#if ENABLE_PRIORITY
void __interrupt() InterruptHigh(void){
    
    if(READ_BIT(PIR1,BIT1))
        Timer2_ISR();
    
    
    if(READ_BIT(PIR1,BIT0))
        Timer1_ISR();
    
    if(READ_BIT(INTCON,BIT2))
        Timer0_ISR();
    
    if(READ_BIT(INTCON,BIT1))
        INT0_ISR();
    /*if(READ_BIT(INTCON3,BIT0))
        INT1_ISR();*/
    if(READ_BIT(INTCON3,BIT1))
        INT2_ISR();
    
    if(READ_BIT(PIR1,BIT6))
        ADC_ISR();
    /* *******************on change  ************************ */
    /*if(READ_BIT(INTCON,BIT0)&&(READ_BIT(PORTB,4))==1)
        RB4_ISR_High();

    else if(READ_BIT(INTCON,BIT0)&&(READ_BIT(PORTB,4))==0)
        RB4_ISR_Low();*/
    
    if(READ_BIT(INTCON,BIT0)&&(READ_BIT(PORTB,5))==1)
        RB5_ISR_High();

    else if(READ_BIT(INTCON,BIT0)&&(READ_BIT(PORTB,5))==0)
        RB5_ISR_Low();
    
    if(READ_BIT(INTCON,BIT0)&&(READ_BIT(PORTB,6))==1)
        RB6_ISR_High();

    else if(READ_BIT(INTCON,BIT0)&&(READ_BIT(PORTB,6))==0)
        RB6_ISR_Low();
    
    if(READ_BIT(INTCON,BIT0)&&(READ_BIT(PORTB,7))==1)
        RB7_ISR_High();

    else if(READ_BIT(INTCON,BIT0)&&(READ_BIT(PORTB,7))==0)
        RB7_ISR_Low();
    
    /********************on change ***********************/
    else if(READ_BIT(PIE1,BIT4))
        EUSART_TX_ISR();
    else if(READ_BIT(PIE1,BIT5))
        EUSART_RX_ISR();
    
}
void __interrupt (low_priority) InterruptLow(void){
    
    
    if(READ_BIT(PIR1,BIT1))
        Timer2_ISR();
    
    
    if(READ_BIT(PIR1,BIT0))
        Timer1_ISR();
    
    
    if(READ_BIT(INTCON,BIT2))
        Timer0_ISR();
    
    if(READ_BIT(INTCON3,BIT0))
        INT1_ISR();
    /*if(READ_BIT(INTCON3,BIT1))
        INT2_ISR();*/
    
    /*****************on change     ************/
    if(READ_BIT(INTCON,BIT0)&&(READ_BIT(PORTB,4))==1)
        RB4_ISR_High();

    else if(READ_BIT(INTCON,BIT0)&&(READ_BIT(PORTB,4))==0)
        RB4_ISR_Low();
    
}
   
#else
void __interrupt() InterruptHigh (void){
    
    if(READ_BIT(PIR1,BIT1))
        Timer2_ISR();
    
    if(READ_BIT(PIR1,BIT0))
        Timer1_ISR();
    
    if(READ_BIT(INTCON,BIT1))
        INT0_ISR();
    if(READ_BIT(INTCON3,BIT0))
        INT1_ISR();
    if(READ_BIT(INTCON3,BIT1))
        INT2_ISR();
    
    if(READ_BIT(INTCON,BIT2))
        Timer0_ISR();
 }

#endif

