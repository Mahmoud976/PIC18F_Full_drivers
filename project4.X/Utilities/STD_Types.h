/* 
 * File:   STD_Types.h
 * Author: mahmo
 *
 * Created on December 4, 2023, 12:18 AM
 */

#ifndef STD_TYPES_H
#define	STD_TYPES_H

#include"STD_Library.h"
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

#define E_OK            (Std_ReturnType)0x01
#define E_NOT_OK        (Std_ReturnType)0x00


#endif	/* STD_TYPES_H */

