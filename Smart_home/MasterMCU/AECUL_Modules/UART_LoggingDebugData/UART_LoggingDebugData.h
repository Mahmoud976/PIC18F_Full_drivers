/* 
 * File:   UART_LoggingDebugData.h
 * Author: Ahmed Abd El-Ghafar
 * Created on February 18, 2023, 4:42 PM
 */

#ifndef UART_LOGGINGDEBUGDATA_H
#define	UART_LOGGINGDEBUGDATA_H

#include "../../mcc_generated_files/eusart.h"

void UART_LoggingDebugData_Send_String(uint8_t *String, uint16_t String_Length);

#endif	/* UART_LOGGINGDEBUGDATA_H */

