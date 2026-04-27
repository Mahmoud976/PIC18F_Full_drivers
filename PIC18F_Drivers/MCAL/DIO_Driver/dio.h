/* 
 * File:   dio.h
 * Author: mahmo
 *
 * Created on March 25, 2023, 11:27 PM
 */

#ifndef DIO_H
#define	DIO_H
/* Section : Includes */

#include"../../Utilities/Registers/registers.h"
#include"dio_cfg.h"

/* Section : Macro Declarations */
#define BIT_MASK           (uint8_t)0x01

#define PORT_MASK_IN       (uint8_t)0x00 
#define PORT_MASK_OUT      (uint8_t)0xFF

#define PORT_MASK_HIGH     (uint8_t)0xFF 
#define PORT_MASK_LOW      (uint8_t)0x00

#define PORT_MASK_READ     (uint8_t)0xFF
#define PORT_MASK_TOGGLE   (uint8_t)0xFF


#define DIO_PIN_CFG    CFG_ENABLE
#define DIO_PORT_CFG   CFG_ENABLE
 
 
#define PORT_A             'A'
#define PORT_B             'B'
#define PORT_C             'C'
#define PORT_D             'D'
#define pin_max             7


/*  Section : Macro Functions Declarations */
#define SET_BIT(REG,BIT_POSN)       (REG |= (BIT_MASK << BIT_POSN))
#define CLEAR_BIT(REG,BIT_POSN)     (REG &= ~(BIT_MASK << BIT_POSN))
#define TOGGLE_BIT(REG,BIT_POSN)    (REG ^= (BIT_MASK << BIT_POSN))
#define READ_BIT(REG,BIT_POSN)      ((REG >> BIT_POSN)& BIT_MASK)

/* Section : Data Type Declarations */
typedef enum{
    DIO_OUTPUT=0,
    DIO_INPUT
}direction_t;
typedef enum{
    DIO_LOW=0,
    DIO_HIGH
}logic_t;

typedef enum{
    PIN0=0,
    PIN1,
    PIN2,
    PIN3,
    PIN4,
    PIN5,
    PIN6,
    PIN7
}pin_index_t;


/* Section : Function Declarations */

Std_ReturnType dio_pin_direction_initialize(uint8_t pinNum,uint8_t port,uint8_t direction);
Std_ReturnType dio_pin_write_logic( uint8_t pinNum,uint8_t port, logic_t logic);
Std_ReturnType dio_pin_read_logic(uint8_t pinNum,uint8_t port,logic_t* logic_status);
Std_ReturnType dio_pin_toggle_logic(uint8_t pinNum,uint8_t port);


Std_ReturnType dio_port_direction_initialize(uint8_t port,uint8_t direction);
Std_ReturnType dio_port_write_logic(uint8_t port,logic_t logic);
Std_ReturnType dio_port_read_logic(uint8_t port,logic_t* logic_status);
Std_ReturnType dio_port_toggle_logic(uint8_t port);



#endif	/* DIO_H */

