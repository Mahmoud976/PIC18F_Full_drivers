/* 
 * File:   Registers.h
 * Author: mahmo
 *
 * Created on December 4, 2023, 12:15 AM
 */

#ifndef REGISTERS_H
#define	REGISTERS_H
#include"STD_Types.h"

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

#endif	/* REGISTERS_H */

