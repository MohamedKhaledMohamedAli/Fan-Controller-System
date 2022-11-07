 /******************************************************************************
 *
 * Module: TEMPERATURE_LM35_SENSOR
 *
 * File Name: lm35.h
 *
 * Description: Header file for the AVR lm35 driver
 *
 * Author: Mohamed Khaled
 *
 *******************************************************************************/

#ifndef LM35_SENSOR_H_
#define LM35_SENSOR_H_

#include "std_types.h"

/*******************************************************************************
 *                                Definitions                                  *
 *******************************************************************************/

#define LM35_MAX_VOLT 1.5
#define LM35_MAX_TEMP 150

#define LM35_PIN_ID   ADC_CHANNEL2

/*******************************************************************************
 *                              Functions Prototypes                           *
 *******************************************************************************/

/*
 * Description :
 * Function that returns the temperature by using ADC
 */
uint8 LM35_getTemperature(void);

#endif /* LM35_SENSOR_H_ */
