#include"eusart.h"

static void EUSART_Baud_Rate_Calculation(const usart_t *_eusart);
static void EUSART_ASYNC_TX_Init(const usart_t *_eusart);
static void EUSART_ASYNC_RX_Init(const usart_t *_eusart);


Std_ReturnType EUSART_ASYNC_Init(const usart_t *_eusart){
    Std_ReturnType ret = E_NOT_OK;
    if(NULL == _eusart){
        ret = E_NOT_OK;
    }
    else{
        RCSTAbits.SPEN = EUSART_MODULE_DISABLE; /* Disable EUSART Module */
        TRISCbits.RC7 = 1;                      /* RX : Input Configuration as needed */
        TRISCbits.RC6 = 1;                      /* TX : Input Configuration as needed */
        EUSART_Baud_Rate_Calculation(_eusart);
        EUSART_ASYNC_TX_Init(_eusart);
        EUSART_ASYNC_RX_Init(_eusart);
        RCSTAbits.SPEN = EUSART_MODULE_ENABLE;  /* Enable EUSART Module */
        ret = E_OK;
    }
    return ret;
}
Std_ReturnType EUSART_ASYNC_DeInit(const usart_t *_eusart){
    Std_ReturnType ret = E_NOT_OK;
    if(NULL == _eusart){
        ret = E_NOT_OK;
    }
    else{
        RCSTAbits.SPEN = EUSART_MODULE_DISABLE; /* Disable EUSART Module */
        ret = E_OK;
    }
    return ret;
}
Std_ReturnType EUSART_ASYNC_ReadByte(uint8_t *_data){
    Std_ReturnType ret = E_NOT_OK;
    #if DISABLE_INTERRUPT 
        while(!PIR1bits.RCIF);
        *_data = RCREG;
        return ret;
    #endif
    #if ENABLE_INTERRUPT
        if(1 == PIR1bits.RCIF){
            *_data = RCREG;
            ret = E_OK;
        }
        else{
            ret = E_NOT_OK;
        }
        return ret;
    #endif
}
Std_ReturnType EUSART_ASYNC_RX_Restart(void){
    Std_ReturnType ret = E_OK;
    RCSTAbits.CREN = 0; /* Disables receiver */
    RCSTAbits.CREN = 1; /* Enables receiver */
    return ret;
}
Std_ReturnType EUSART_ASYNC_WriteByte(uint8_t _data){
    Std_ReturnType ret = E_OK;
#if DISABLE_INTERRUPT 
    while(!TXSTAbits.TRMT);
        #if EUSART_TX_ENABLE
            EUSART_TX_INTERRUPT_DISABLE();
        #endif
            TXREG = _data;
#endif
#if ENABLE_INTERRUPT
    Enable_General_INT();
    if(TXSTAbits.TRMT){
        #if EUSART_TX_ENABLE
            EUSART_TX_INTERRUPT_DISABLE();
        #endif
            TXREG = _data;
            ret=E_OK;
    }
    else {/*Nothing*/}  
#endif   
    
    return ret;
}
Std_ReturnType EUSART_ASYNC_WriteString(uint8_t *_data, uint16_t str_len){
    Std_ReturnType ret = E_OK;
    uint16_t char_counter = 0;
    for(char_counter=0; char_counter < str_len; char_counter++){
        ret = EUSART_ASYNC_WriteByte(_data[char_counter]);
    }
    return ret;
}


static void EUSART_Baud_Rate_Calculation(const usart_t *_eusart){
    float Baud_Rate_Temp = 0;
    switch(_eusart->baudrate_gen_gonfig){
        case BAUDRATE_ASYN_8BIT_lOW_SPEED:
            TXSTAbits.SYNC = EUSART_ASYNCHRONOUS_MODE;
            TXSTAbits.BRGH = EUSART_ASYNCHRONOUS_LOW_SPEED;
            BAUDCONbits.BRG16 = EUSART_08BIT_BAUDRATE_GEN;
            Baud_Rate_Temp = ((_XTAL_FREQ / (float)_eusart->baudrate) / 64) - 1;
            break;
        case BAUDRATE_ASYN_8BIT_HIGH_SPEED:
            TXSTAbits.SYNC = EUSART_ASYNCHRONOUS_MODE;
            TXSTAbits.BRGH = EUSART_ASYNCHRONOUS_HIGH_SPEED;
            BAUDCONbits.BRG16 = EUSART_08BIT_BAUDRATE_GEN;
            Baud_Rate_Temp = ((_XTAL_FREQ / (float)_eusart->baudrate) / 16) - 1;
            break;
        case BAUDRATE_ASYN_16BIT_lOW_SPEED:
            TXSTAbits.SYNC = EUSART_ASYNCHRONOUS_MODE;
            TXSTAbits.BRGH = EUSART_ASYNCHRONOUS_LOW_SPEED;
            BAUDCONbits.BRG16 = EUSART_16BIT_BAUDRATE_GEN;
            Baud_Rate_Temp = ((_XTAL_FREQ / (float)_eusart->baudrate) / 16) - 1;
            break;
        case BAUDRATE_ASYN_16BIT_HIGH_SPEED:
            TXSTAbits.SYNC = EUSART_ASYNCHRONOUS_MODE;
            TXSTAbits.BRGH = EUSART_ASYNCHRONOUS_HIGH_SPEED;
            BAUDCONbits.BRG16 = EUSART_16BIT_BAUDRATE_GEN;
            Baud_Rate_Temp = ((_XTAL_FREQ / (float)_eusart->baudrate) / 4) - 1;
            break;
        case BAUDRATE_SYN_8BIT:
            TXSTAbits.SYNC = EUSART_SYNCHRONOUS_MODE;
            BAUDCONbits.BRG16 = EUSART_08BIT_BAUDRATE_GEN;
            Baud_Rate_Temp = ((_XTAL_FREQ / (float)_eusart->baudrate) / 4) - 1;
            break;
        case BAUDRATE_SYN_16BIT:
            TXSTAbits.SYNC = EUSART_SYNCHRONOUS_MODE;
            BAUDCONbits.BRG16 = EUSART_16BIT_BAUDRATE_GEN;
            Baud_Rate_Temp = ((_XTAL_FREQ / (float)_eusart->baudrate) / 4) - 1;
            break;
        default : ;
    }
    SPBRG = (uint8_t)((uint32_t)Baud_Rate_Temp);
    SPBRGH = (uint8_t)(((uint32_t)Baud_Rate_Temp) >> 8);
}
static void EUSART_ASYNC_TX_Init(const usart_t *_eusart){
    if(EUSART_ASYNCHRONOUS_TX_ENABLE == _eusart->usart_tx_cfg.usart_tx_enable){
        TXSTAbits.TXEN = EUSART_ASYNCHRONOUS_TX_ENABLE;
        EUSART_TX_SetInterruptHandler(_eusart->EUSART_TxDefaultInterruptHandler);
        /* EUSART Transmit Interrupt Configuration */
        if(EUSART_ASYNCHRONOUS_INTERRUPT_TX_ENABLE == _eusart->usart_tx_cfg.usart_tx_interrupt_enable){
            PIE1bits.TXIE = EUSART_ASYNCHRONOUS_INTERRUPT_TX_ENABLE;
            /* Interrupt Configurations */ 
#if EUSART_TX_ENABLE 
        Enable_General_INT();    
        EUSART_TX_INTERRUPT_ENABLE();
        /* Interrupt Priority Configurations */
   
#if ENABLE_PRIORITY 
        ENABLE_ALL_PRIORITY();
        EUSART_TX_INTERRUPT_ENABLE();
        if(INTERRUPT_HIGH_PRIORITY == _eusart->usart_tx_cfg.usart_tx_int_priority){
            EUSART_TX_SET_HIGH_PRIORITY();//enable priority HIGH
        }
        else if(INTERRUPT_LOW_PRIORITY == _eusart->usart_tx_cfg.usart_tx_int_priority){
            EUSART_TX_SET_LOW_PRIORITY();//enable priority LOW
        }
        else{ /* Nothing */ }
#else
        Enable_General_INT();
#endif
#endif
        }
        else if(EUSART_ASYNCHRONOUS_INTERRUPT_TX_DISABLE == _eusart->usart_tx_cfg.usart_tx_interrupt_enable){
            PIE1bits.TXIE = EUSART_ASYNCHRONOUS_INTERRUPT_TX_DISABLE;
        }
        else{ /* Nothing */}

        /* EUSART  9-Bit Transmit Configuration */
        if(EUSART_ASYNCHRONOUS_9Bit_TX_ENABLE == _eusart->usart_tx_cfg.usart_tx_9bit_enable){
            TXSTAbits.TX9 = EUSART_ASYNCHRONOUS_9Bit_TX_ENABLE;
        }
        else if(EUSART_ASYNCHRONOUS_9Bit_TX_DISABLE == _eusart->usart_tx_cfg.usart_tx_9bit_enable){
            TXSTAbits.TX9 = EUSART_ASYNCHRONOUS_9Bit_TX_DISABLE;
        }
        else{ /* Nothing */}
    }
    else { /* Nothing */}
}
static void EUSART_ASYNC_RX_Init(const usart_t *_eusart){
    if(EUSART_ASYNCHRONOUS_RX_ENABLE == _eusart->usart_rx_cfg.usart_rx_enable){
        RCSTAbits.CREN = EUSART_ASYNCHRONOUS_RX_ENABLE;
        EUSART_RX_SetInterruptHandler( _eusart->EUSART_RxDefaultInterruptHandler);
        EUSART_FramingSetInterruptHandler(_eusart->EUSART_FramingErrorHandler);
        EUSART_Overrun_SetInterruptHandler(_eusart->EUSART_OverrunErrorHandler);
        /* EUSART Receiver Interrupt Configuration */
        if(EUSART_ASYNCHRONOUS_INTERRUPT_RX_ENABLE == _eusart->usart_rx_cfg.usart_rx_interrupt_enable){
            PIE1bits.RCIE = EUSART_ASYNCHRONOUS_INTERRUPT_RX_ENABLE;
            /* Interrupt Configurations */ 
#if EUSART_RX_ENABLE 
        Enable_General_INT();    
        EUSART_RX_INTERRUPT_ENABLE();
        /* Interrupt Priority Configurations */
   
#if ENABLE_PRIORITY 
        ENABLE_ALL_PRIORITY();
        EUSART_RX_INTERRUPT_ENABLE();
        if(INTERRUPT_HIGH_PRIORITY == _eusart->usart_rx_cfg.usart_rx_int_priority){
            EUSART_RX_SET_HIGH_PRIORITY();//enable priority HIGH
        }
        else if(INTERRUPT_LOW_PRIORITY == _eusart->usart_rx_cfg.usart_rx_int_priority){
            EUSART_RX_SET_LOW_PRIORITY();//enable priority LOW
        }
        else{ /* Nothing */ }
#else
        Enable_General_INT();
#endif
#endif
        }
        else if(EUSART_ASYNCHRONOUS_INTERRUPT_RX_DISABLE == _eusart->usart_rx_cfg.usart_rx_interrupt_enable){
            PIE1bits.RCIE = EUSART_ASYNCHRONOUS_INTERRUPT_RX_DISABLE;
        }
        else{ /* Nothing */}

        /* EUSART  9-Bit Receiver Configuration */
        if(EUSART_ASYNCHRONOUS_9Bit_RX_ENABLE == _eusart->usart_rx_cfg.usart_rx_9bit_enable){
            RCSTAbits.RX9 = EUSART_ASYNCHRONOUS_9Bit_RX_ENABLE;
        }
        else if(EUSART_ASYNCHRONOUS_9Bit_RX_DISABLE == _eusart->usart_rx_cfg.usart_rx_9bit_enable){
            RCSTAbits.RX9 = EUSART_ASYNCHRONOUS_9Bit_RX_DISABLE;
        }
        else{ /* Nothing */}
    }
    else { /* Nothing */}
}






