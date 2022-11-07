 /******************************************************************************
 *
 * Module: ADC
 *
 * File Name: adc.h
 *
 * Description: Header file for the AVR ADC driver
 *
 * Author: Mohamed Khaled
 *
 *******************************************************************************/

#ifndef ADC_H_
#define ADC_H_

#include "std_types.h"

/*******************************************************************************
 *                                Definitions                                  *
 *******************************************************************************/

#define ADC_VREF_MAX	2.56
#define ADC_MAX_VALUE	1023

#define ADC_CHANNEL0	0
#define ADC_CHANNEL1	1
#define ADC_CHANNEL2	2
#define ADC_CHANNEL3	3
#define ADC_CHANNEL4	4
#define ADC_CHANNEL5	5
#define ADC_CHANNEL6	6
#define ADC_CHANNEL7	7

/*******************************************************************************
 *                               Types Declaration                             *
 *******************************************************************************/

/* enum represents all voltage reference selection options */
typedef enum{
	AREF, AVCC, Internal = 3
}ADC_ReferenceVolatge;

/* enum represents all ADC Prescaler Selection options */
typedef enum{
	F_CPU_2 = 1, F_CPU_4, F_CPU_8, F_CPU_16, F_CPU_32, F_CPU_64, F_CPU_128
}ADC_Prescaler;

/* Structure that contain members to set the configurations of ADC */
typedef struct{
	ADC_ReferenceVolatge ref_volt;
	ADC_Prescaler prescaler;
}ADC_ConfigType;

/*******************************************************************************
 *                              Functions Prototypes                           *
 *******************************************************************************/

/*
 * Description :
 * Initialize ACD:
 * 1. Enable ADC
 * 2. Set ADC pre-scale
 * 3. Disable ADC Interrupt
 */
void ADC_init(const ADC_ConfigType * Config_Ptr);

/*
 * Description :
 * Select channel pin which needs to be converted from analog to digital and convert it
 * by using polling and return result
 */
uint16 ADC_readChannel(uint8 channel);

#endif /* ADC_H_ */
