/* 
 * File:   eusart.h
 * Author: mahmoud saleh
 *
 * Created on September 28, 2023, 8:56 PM
 */

#ifndef EUSART_H
#define	EUSART_H

/* Section : Includes */
#include"eusart_cfg.h"
#include"../../Utilities/Registers/registers.h"
#include"../Interrupt/Internal_Interrupt.h"
/* Section : Macro Declarations */

/* Enable / Disable EUSART Module */
#define EUSART_MODULE_ENABLE   1
#define EUSART_MODULE_DISABLE  0

/* Selecting EUSART Working Mode */  
#define EUSART_SYNCHRONOUS_MODE  		1
#define EUSART_ASYNCHRONOUS_MODE 		0
/* Baud Rate Generator Asynchronous Speed Mode */
#define EUSART_ASYNCHRONOUS_HIGH_SPEED  1
#define EUSART_ASYNCHRONOUS_LOW_SPEED  	0
/* Baud Rate Generator Register Size */
#define EUSART_16BIT_BAUDRATE_GEN  		1
#define EUSART_08BIT_BAUDRATE_GEN  		0

/* EUSART Transmit Enable */
#define EUSART_ASYNCHRONOUS_TX_ENABLE   1
#define EUSART_ASYNCHRONOUS_TX_DISABLE  0
/* EUSART Transmit Interrupt Enable */
#define EUSART_ASYNCHRONOUS_INTERRUPT_TX_ENABLE   1
#define EUSART_ASYNCHRONOUS_INTERRUPT_TX_DISABLE  0
/* EUSART 9-Bit Transmit Enable */
#define EUSART_ASYNCHRONOUS_9Bit_TX_ENABLE   1
#define EUSART_ASYNCHRONOUS_9Bit_TX_DISABLE  0

/* EUSART Receiver Enable */
#define EUSART_ASYNCHRONOUS_RX_ENABLE   1
#define EUSART_ASYNCHRONOUS_RX_DISABLE  0
/* EUSART Receiver Interrupt Enable */
#define EUSART_ASYNCHRONOUS_INTERRUPT_RX_ENABLE   1
#define EUSART_ASYNCHRONOUS_INTERRUPT_RX_DISABLE  0
/* EUSART 9-Bit Receiver Enable */
#define EUSART_ASYNCHRONOUS_9Bit_RX_ENABLE   1
#define EUSART_ASYNCHRONOUS_9Bit_RX_DISABLE  0
/* EUSART Framing Error */
#define EUSART_FRAMING_ERROR_DETECTED 1
#define EUSART_FRAMING_ERROR_CLEARED  0
/* EUSART Overrun Error */
#define EUSART_OVERRUN_ERROR_DETECTED 1
#define EUSART_OVERRUN_ERROR_CLEARED  0

/* ----------------- Macro Functions Declarations -----------------*/

/* ----------------- Data Type Declarations -----------------*/
typedef enum{
    BAUDRATE_ASYN_8BIT_lOW_SPEED,
    BAUDRATE_ASYN_8BIT_HIGH_SPEED,
    BAUDRATE_ASYN_16BIT_lOW_SPEED,   
    BAUDRATE_ASYN_16BIT_HIGH_SPEED,
    BAUDRATE_SYN_8BIT,
    BAUDRATE_SYN_16BIT
}baudrate_gen_t;

typedef struct{
    interrupt_priority_cfg usart_tx_int_priority;
	uint8_t usart_tx_enable : 1;
	uint8_t usart_tx_interrupt_enable : 1;
	uint8_t usart_tx_9bit_enable : 1;
    uint8_t usart_tx_reserved : 5;
}usart_tx_cfg_t;

typedef struct{
    interrupt_priority_cfg usart_rx_int_priority;
	uint8_t usart_rx_enable : 1;
	uint8_t usart_rx_interrupt_enable : 1;
	uint8_t usart_rx_9bit_enable : 1;
    uint8_t usart_rx_reserved : 5;
}usart_rx_cfg_t;

typedef union{
	struct{
		uint8_t usart_tx_reserved : 6;
		uint8_t usart_ferr : 1;
		uint8_t usart_oerr : 1;
	};
	uint8_t status;
}usart_error_status_t;

typedef struct{
    uint32_t baudrate;
    baudrate_gen_t baudrate_gen_gonfig;
    usart_tx_cfg_t usart_tx_cfg;
	usart_rx_cfg_t usart_rx_cfg;
	usart_error_status_t error_status;
	void (*EUSART_TxDefaultInterruptHandler)(void);
    void (*EUSART_RxDefaultInterruptHandler)(void);
    void (*EUSART_FramingErrorHandler)(void);
    void (*EUSART_OverrunErrorHandler)(void);
}usart_t;

/* ----------------- Software Interfaces Declarations -----------------*/

Std_ReturnType EUSART_ASYNC_Init(const usart_t *_eusart);
Std_ReturnType EUSART_ASYNC_DeInit(const usart_t *_eusart);
Std_ReturnType EUSART_ASYNC_ReadByte(uint8_t *_data);
Std_ReturnType EUSART_ASYNC_RX_Restart(void);
Std_ReturnType EUSART_ASYNC_WriteByte(uint8_t _data);
Std_ReturnType EUSART_ASYNC_WriteString(uint8_t *_data, uint16_t str_len);
#endif	/* EUSART_H */

