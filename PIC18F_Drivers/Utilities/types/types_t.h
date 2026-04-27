/* 
 * File:   types_t.h
 * Author: mahmo
 *
 * Created on March 26, 2023, 12:44 AM
 */

#ifndef TYPES_T_H
#define	TYPES_T_H
/*Section : Includes*/
#include"../DEV_CONFIG/dev_config.h"
#include"../std_Library/libraries.h"


/*   Section : Data Type Declarations     */

typedef unsigned char uint8_t;
typedef unsigned short uint16_t;
typedef unsigned long uint32_t;
typedef unsigned long long uint64_t;

typedef signed char sint8_t;
typedef signed short sint16_t;
typedef signed long sint32_t;
typedef signed long long sint64_t;

typedef uint8_t Std_ReturnType ;


/* Section : Macro Declarations */
#define STD_HIGH        0x01
#define STD_LOW         0x00

#define STD_ON          0x01
#define STD_OFF         0x00

#define STD_ACTIVE      0x01
#define STD_IDLE        0x00

#define E_OK            (Std_ReturnType)0x01
#define E_NOT_OK        (Std_ReturnType)0x00

uint32_t _XTAL_FREQ=8000000;

#endif	/* TYPES_T_H */

