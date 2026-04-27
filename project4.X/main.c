/* 
 * File:   main.c
 * Author: mahmoud saleh
 *
 * Created on December 4, 2023, 12:06 AM
 */


/*
 * 
 */

#include"ECUAL/LED_Driver/led.h"
#include"MCAL/Interrupt/interrupt_manager.h"
void del(){
    for(int i=0;i<250;i++)
        for(int j=0;j<250;j++);
}
void le(){
    led_on(0,'A');
    del();
    led_off(0,'A');
}
int main() {
 Interrupt_INTx(0,1,0,le);
    while(1){
        
    }

    return (0);
}

