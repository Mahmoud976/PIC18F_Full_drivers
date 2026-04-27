/* 
 * File:   main.c
 * Author: mahmoud saleh
 *
 * Created on March 25, 2023, 11:05 PM
 */

#include"Application/app/app.h"
/*
 * 
 */
volatile int x=0;
volatile int y=0;
volatile int z=0;

volatile uint8_t rec_uart_data;

void EUSART_RxDefaultInterruptHandler (void){
    x++;
    Std_ReturnType ret = E_NOT_OK;
    EUSART_ASYNC_ReadByte(&rec_uart_data);
    if('a' == rec_uart_data){
        led_on(0,'D');
        ret = EUSART_ASYNC_WriteByte('c');
        for(int i=0;i<=250;i++)
            for(int j=0;j<=250;j++);
    }
    if('b' == rec_uart_data){
        led_off(0,'D');
        ret = EUSART_ASYNC_WriteByte('d');
          for(int i=0;i<=250;i++)
            for(int j=0;j<=250;j++);
    }
}

void usart_module_int_init(void){
    Std_ReturnType ret = E_NOT_OK;
    usart_t usart_obj;
    usart_obj.baudrate = 9600;
    usart_obj.baudrate_gen_gonfig = BAUDRATE_ASYN_8BIT_lOW_SPEED;   
    usart_obj.usart_tx_cfg.usart_tx_enable = EUSART_ASYNCHRONOUS_TX_ENABLE;
    usart_obj.usart_tx_cfg.usart_tx_interrupt_enable = EUSART_ASYNCHRONOUS_INTERRUPT_TX_ENABLE;
    usart_obj.usart_tx_cfg.usart_tx_9bit_enable = EUSART_ASYNCHRONOUS_9Bit_TX_DISABLE;
    usart_obj.usart_rx_cfg.usart_rx_enable = EUSART_ASYNCHRONOUS_RX_ENABLE;
    usart_obj.usart_rx_cfg.usart_rx_interrupt_enable = EUSART_ASYNCHRONOUS_INTERRUPT_RX_ENABLE;
    usart_obj.usart_rx_cfg.usart_rx_9bit_enable = EUSART_ASYNCHRONOUS_9Bit_RX_DISABLE;
    usart_obj.EUSART_TxDefaultInterruptHandler = NULL;
    usart_obj.EUSART_RxDefaultInterruptHandler = EUSART_RxDefaultInterruptHandler;
    usart_obj.EUSART_FramingErrorHandler = NULL;
    usart_obj.EUSART_OverrunErrorHandler = NULL;   
    ret = EUSART_ASYNC_Init(&usart_obj);
}

int main() { 

    while(1){
        
    }
    return (EXIT_SUCCESS);
}




