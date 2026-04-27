
#include"gpio.h"
//Reference to the Data Direction control registers 
volatile uint8 *tris_registers[]={&TRISA,&TRISB,&TRISC,&TRISE,&TRISD};
//Reference to the Data Latch  registers(read || write) 
volatile uint8 *lat_registers[]={&LATA,&LATB,&LATC,&LATE,&LATD};
//Reference to the port Status Register 
volatile uint8 *port_registers[]={&PORTA,&PORTB,&PORTC,&PORTE,&PORTD};


/**
 * 
 * @param _pin_config pointer to the configurations @ref pin_config_t
 * @return Status of the function
 *         (E_OK) : The Function Done Successfully
 *         (E_NOT_OK) : The Function has issue to Perform this action 
 */
#if GPIO_PORT_PIN_CONFIGURATION==CONFIG_ENABLE
Std_ReturnType gpio_pin_direction_initialize(const pin_config_t *_pin_config){
    Std_ReturnType ret=E_OK;
    if (NULL==_pin_config || _pin_config->pin > MAX_PIN_NUMBER -1 || _pin_config->port > MAX_PORT_NUMBER -1  )
    ret=E_NOT_OK;
    else
    {
        switch (_pin_config->direction)
        {
            case GPIO_DIRECTION_OUTPUT:
               CLEAR_BIT(*tris_registers[_pin_config->port],_pin_config->pin); 
                break;
            case GPIO_DIRECTION_INPUT:
               SET_BIT(*tris_registers[_pin_config->port],_pin_config->pin); 
                break;
            default: ret = E_NOT_OK;    
        }
    }
    return ret;
}
#endif 
/**
 * 
 * @param _pin_config  pointer to the configurations @ref pin_config_t
 * @param direction_status
 * @return Status of the function
 *         (E_OK) : The Function Done Successfully
 *         (E_NOT_OK) : The Function has issue to Perform this action 
 */
#if GPIO_PORT_PIN_CONFIGURATION==CONFIG_ENABLE
Std_ReturnType gpio_pin_get_direction_status(const pin_config_t *_pin_config,direction_t *direction_status){
    Std_ReturnType ret=E_OK;
    if (NULL==_pin_config || _pin_config->pin > MAX_PIN_NUMBER -1 || _pin_config->port > MAX_PORT_NUMBER -1 || NULL==direction_status)
    ret=E_NOT_OK; 
    else
    {
        *direction_status=READ_BIT(*tris_registers[_pin_config->port],_pin_config->pin)
    }
    return ret;
}    
#endif
/**
 * 
 * @param _pin_config  pointer to the configurations @ref pin_config_t
 * @param logic
 * @return Status of the function
 *         (E_OK) : The Function Done Successfully
 *         (E_NOT_OK) : The Function has issue to Perform this action 
 */
#if GPIO_PORT_PIN_CONFIGURATION==CONFIG_ENABLE
Std_ReturnType gpio_pin_write_logic(const pin_config_t *_pin_config,logic_t logic)  {
    Std_ReturnType ret=E_OK;
    if (NULL==_pin_config || _pin_config->pin > MAX_PIN_NUMBER -1 ||
        _pin_config->port > MAX_PORT_NUMBER -1  )
    ret=E_NOT_OK;
    else
    {
        switch( logic )
        {
            case GPIO_LOW:
                CLEAR_BIT(*lat_registers[_pin_config->port],_pin_config->pin); 
                break;
            case GPIO_HIGH:
                SET_BIT(*lat_registers[_pin_config->port],_pin_config->pin);
                break;
            default: ret=E_NOT_OK;
        }
    }
    return ret;
}
#endif
/**
 * 
 * @param _pin_config  pointer to the configurations @ref pin_config_t
 * @param logic
 * @return Status of the function
 *         (E_OK) : The Function Done Successfully
 *         (E_NOT_OK) : The Function has issue to Perform this action 
 */
#if GPIO_PORT_PIN_CONFIGURATION==CONFIG_ENABLE
Std_ReturnType gpio_pin_read_logic(const pin_config_t *_pin_config,logic_t *logic){
    Std_ReturnType ret=E_OK;
    if (NULL==_pin_config || _pin_config->pin > MAX_PIN_NUMBER -1 ||
        _pin_config->port > MAX_PORT_NUMBER -1 || NULL==logic )
    ret=E_NOT_OK;
    else
    { 
        *logic=READ_BIT(*port_registers[_pin_config->port],_pin_config->pin);
    }
    return ret;
}
#endif
/**
 * 
 * @param _pin_config   pointer to the configurations @ref pin_config_t
 * @return Status of the function
 *         (E_OK) : The Function Done Successfully
 *         (E_NOT_OK) : The Function has issue to Perform this action 
 */
#if GPIO_PORT_PIN_CONFIGURATION==CONFIG_ENABLE
Std_ReturnType gpio_pin_toggel_logic(const pin_config_t *_pin_config){
    Std_ReturnType ret=E_OK;
    if (NULL==_pin_config || _pin_config->pin > MAX_PIN_NUMBER -1 ||
        _pin_config->port > MAX_PORT_NUMBER -1)
    ret=E_NOT_OK;
    else
    { 
        TOGGLE_BIT(*lat_registers[_pin_config->port],_pin_config->pin);
    }
    return ret;
}
#endif
/**
 * 
 * @param _pin_config  pointer to the configurations @ref pin_config_t
 * @return Status of the function
 *         (E_OK) : The Function Done Successfully
 *         (E_NOT_OK) : The Function has issue to Perform this action 
 */
#if GPIO_PORT_CONFIGURATION==CONFIG_ENABLE
Std_ReturnType gpio_pin_initialize(const pin_config_t *_pin_config)
{
    gpio_pin_direction_initialize(_pin_config);
    gpio_pin_write_logic(_pin_config,_pin_config->logic);
}
#endif
/**
 * 
 * @param port
 * @return Status of the function
 *         (E_OK) : The Function Done Successfully
 *         (E_NOT_OK) : The Function has issue to Perform this action 
 */
#if GPIO_PORT_CONFIGURATION==CONFIG_ENABLE
Std_ReturnType gpio_port_direction_initialize(port_index_t port,uint8 direction){
    Std_ReturnType ret=E_OK;
    if (port > MAX_PORT_NUMBER -1)
    ret=E_NOT_OK;
    else
    { 
        *tris_registers[port]=direction;
    }
    return ret;
}
#endif
/**
 * 
 * @param port
 * @param direction_status
 * @return Status of the function
 *         (E_OK) : The Function Done Successfully
 *         (E_NOT_OK) : The Function has issue to Perform this action 
 */
#if GPIO_PORT_CONFIGURATION==CONFIG_ENABLE
Std_ReturnType gpio_port_git_direction_status(port_index_t port,uint8 *direction_status){
   Std_ReturnType ret=E_OK;
    if (port > MAX_PORT_NUMBER -1||NULL==direction_status)
    ret=E_NOT_OK;
    else 
    { 
        *direction_status=*tris_registers[port];
    }
    return ret;  
}
#endif
/** 
 * 
 * @param port
 * @param logic
 * @return Status of the function
 *         (E_OK) : The Function Done Successfully
 *         (E_NOT_OK) : The Function has issue to Perform this action 
 */
#if GPIO_PORT_CONFIGURATION==CONFIG_ENABLE
Std_ReturnType gpio_port_write_logic(port_index_t port,uint8 logic){
    Std_ReturnType ret=E_OK;
    if (port > MAX_PORT_NUMBER -1||logic > 0xFF)
    ret=E_NOT_OK;
    else 
    { 
        *lat_registers[port]=logic;
    }
    return ret;

}
#endif
/**
 * 
 * @param port
 * @param logic
 * @return Status of the function
 *         (E_OK) : The Function Done Successfully
 *         (E_NOT_OK) : The Function has issue to Perform this action 
 */
#if GPIO_PORT_CONFIGURATION==CONFIG_ENABLE
Std_ReturnType gpio_port_read_logic(port_index_t port ,uint8 *logic){
    Std_ReturnType ret=E_OK;
    if (port > MAX_PORT_NUMBER -1||NULL==logic)
    ret=E_NOT_OK;
    else 
    { 
        *logic=*port_registers[port];
    }
    return ret;
}
#endif
/**
  * 
  * @param port
  * @return Status of the function
 *         (E_OK) : The Function Done Successfully
 *         (E_NOT_OK) : The Function has issue to Perform this action  
  */
#if GPIO_PORT_CONFIGURATION==CONFIG_ENABLE
Std_ReturnType gpio_port_toggel_logic(port_index_t port){
    Std_ReturnType ret=E_OK;
    if (port > MAX_PORT_NUMBER -1)
    ret=E_NOT_OK;
    else 
    { 
        *lat_registers[port]^=PORTC_MASK;
    }
    return ret;
}
#endif