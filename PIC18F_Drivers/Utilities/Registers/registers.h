/* 
 * File:   registers.h
 * Author: mahmo
 *
 * Created on March 26, 2023, 3:48 PM
 */



/************************************************************************/
/*                All Micro controller registers                        */
/************************************************************************/
#ifndef REGISTERS_H
#define	REGISTERS_H
#include"../types/types_t.h"

/************************************************************************/
/*                         DIO Registers                                */
/************************************************************************/

//PORT A Register
#define TRISA   *((volatile uint8_t *)0xF92)  //8 bit register
#define PORTA   *((volatile uint8_t *)0xF80)  //8 bit register
#define LATA    *((volatile uint8_t *)0xF89)  //8 bit register

//PORT B Register
#define TRISB   *((volatile uint8_t *)0xF93)  //8 bit register
#define PORTB   *((volatile uint8_t *)0xF81)  //8 bit register
#define LATB    *((volatile uint8_t *)0xF8A)  //8 bit register

//PORT C Register
#define TRISC   *((volatile uint8_t *)0xF94)  //8 bit register
#define PORTC   *((volatile uint8_t *)0xF82)  //8 bit register
#define LATC    *((volatile uint8_t *)0xF8B)  //8 bit register

//PORT D Register
#define TRISD   *((volatile uint8_t *)0xF95)  //8 bit register
#define PORTD   *((volatile uint8_t *)0xF83)  //8 bit register
#define LATD    *((volatile uint8_t *)0xF8C)  //8 bit register

//PORT E Register
#define TRISE   *((volatile uint8_t *)0xF96)  //8 bit register
#define PORTE   *((volatile uint8_t *)0xF84)  //8 bit register
#define LATE    *((volatile uint8_t *)0xF8D)  //8 bit register


/************************************************************************/
/*                    timers registers                                  */
/************************************************************************/


// timer0 register
#define T0CON *((volatile uint8_t *)0xFD5)  //8 bit register
#define TMR0L *((volatile uint8_t *)0xFD6)  //8 bit register
#define TMR0H *((volatile uint8_t *)0xFD7)  //8 bit register

// timer1 register
#define T1CON *((volatile uint8_t *)0xFCD)  //8 bit register
#define TMR1L *((volatile uint8_t *)0xFCE)  //8 bit register
#define TMR1H *((volatile uint8_t *)0xFCF)  //8 bit register

// timer2 register
#define TMR2  *((volatile uint8_t *)0xFCC)  //8 bit register
#define T2CON *((volatile uint8_t *)0xFCA)  //8 bit register


// timer3 register
#define T3CON *((volatile uint8_t *)0x)  //8 bit register
#define TMR3L *((volatile uint8_t *)0x)  //8 bit register
#define TMR3H *((volatile uint8_t *)0x)  //8 bit register


/************************************************************************/
/*               External&Internal  InterruptS  Register                */
/************************************************************************/
#define INTCON    *((volatile uint8_t *)0xFF2)  //8 bit register
#define INTCON2   *((volatile uint8_t *)0xFF1)  //8 bit register
#define INTCON3   *((volatile uint8_t *)0xFF0)  //8 bit register
#define PIR1      *((volatile uint8_t *)0xF9E)  //8 bit register
#define PIR2      *((volatile uint8_t *)0xFA1)  //8 bit register
#define PIE1      *((volatile uint8_t *)0xF9D)  //8 bit register
#define PIE2      *((volatile uint8_t *)0xFA0)  //8 bit register
#define IPR1      *((volatile uint8_t *)0xF9F)  //8 bit register
#define IPR2      *((volatile uint8_t *)0xFA2)  //8 bit register
#define RCON      *((volatile uint8_t *)0xFD0)  //8 bit register
/************************************************************************/
/*               EEPROM  Registers                                      */
/************************************************************************/
#define EECON1      *((volatile uint8_t *)0xFA6)  //8 bit register
#define EECON2      *((volatile uint8_t *)0xFA7)  //8 bit register
#define EEDATA      *((volatile uint8_t *)0xFA8)  //8 bit register
#define EEADR       *((volatile uint8_t *)0xFA9)  //8 bit register
#define EEADRH      *((volatile uint8_t *)0xFAA)  //8 bit register
/************************************************************************/
/*                   ADC Registers                                      */
/************************************************************************/
#define ADRESH      *((volatile uint8_t *)0xFC4)  //8 bit register
#define ADRESL      *((volatile uint8_t *)0xFC3)  //8 bit register
#define ADCON0      *((volatile uint8_t *)0xFC2)  //8 bit register
#define ADCON1      *((volatile uint8_t *)0xFC1)  //8 bit register
#define ADCON2      *((volatile uint8_t *)0xFC0)  //8 bit register

/************************************************************************/
/*                            EUSART                                    */
/************************************************************************/
#define RCSTA       *((volatile uint8_t *)0xFAB)  //8 bit register
#define TXREG       *((volatile uint8_t *)0xFAD)  //8 bit register
#define TXSTA       *((volatile uint8_t *)0xFAC)  //8 bit register
#define BAUDCON     *((volatile uint8_t *)0xFB8)  //8 bit register
#define SPBRGH      *((volatile uint8_t *)0xFB0)  //8 bit register
#define SPBRG       *((volatile uint8_t *)0xFAF)  //8 bit register

#endif	/* REGISTERS_H */

