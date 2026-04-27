/* 
 * File:   std_types.h
 * Author: mahmo
 *
 * Created on January 16, 2023, 6:33 PM
 */

#ifndef STD_TYPES_H
#define	STD_TYPES_H
/*  Section : Includes  */
#include"std_Libraries.h"
#include"compiler.h"
/*  Section : Data type Declarations */
typedef unsigned char  uint8;
typedef unsigned short uint16;
typedef unsigned int   uint32;

typedef signed char   sint8;
typedef signed short  sint16;
typedef signed int    sint32;

typedef uint8  Std_ReturnType;

/*  Section : Macro Declarations  */
#define STD_HIGH        0x01
#define STD_LOW         0x00

#define STD_ON          0x01
#define STD_OFF         0x00

#define STD_ACTIVE      0x01
#define STD_IDEL        0x00

#define E_OK            (Std_ReturnType)0x01
#define E_NOT_OK        (Std_ReturnType)0x01
/*  Section :Macro Functions Declarations   */

/*  Section : Function Declarations  */

#endif	/* STD_TYPES_H */

