/* 
 * File:   TemSensor_TC74.h
 * Author: Ahmed Abd El-Ghafar
 * Created on February 19, 2023, 5:33 PM
 */

#ifndef TEMSENSOR_TC74_H
#define	TEMSENSOR_TC74_H

#include "../../mcc_generated_files/mcc.h"
#include "../../mcc_generated_files/examples/i2c_master_example.h"

uint8_t TempSensor_TC74_Read_Temp(i2c_address_t TC74_Address);

#endif	/* TEMSENSOR_TC74_H */

