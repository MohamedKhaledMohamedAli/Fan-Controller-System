 /******************************************************************************
 *
 * Module: TEMPERATURE_LM35_SENSOR
 *
 * File Name: lm35.c
 *
 * Description: Source file for the AVR lm35 driver
 *
 * Author: Mohamed Khaled
 *
 *******************************************************************************/

#include "lm35_sensor.h"
#include "adc.h"

/*
 * Description :
 * Function that returns the temperature by using ADC
 */
uint8 LM35_getTemperature(void){

	/* Get value from ADC */
	uint16 adcConversion = ADC_readChannel(LM35_PIN_ID);

	uint8 result;

	/* From Equation */
	/* There is explicit casting to prevent any loss of data */
	/* For Example: if adcConversion was 1023 therefore the adcConversion * LM35_MAX_TEMP * ADC_VREF_MAX = 767250
	 * which is larger than uint16 range 0:65535 thats why explicit casting is needed */
	result = (uint8)(((uint32)adcConversion * LM35_MAX_TEMP * ADC_VREF_MAX)/(LM35_MAX_VOLT * ADC_MAX_VALUE));

	return result;
}
