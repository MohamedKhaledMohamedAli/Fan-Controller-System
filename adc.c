 /******************************************************************************
 *
 * Module: ADC
 *
 * File Name: adc.c
 *
 * Description: Source file for the AVR ADC driver
 *
 * Author: Mohamed Khaled
 *
 *******************************************************************************/

#include "adc.h"
#include <avr/io.h>
#include "common_macros.h"

/*******************************************************************************
 *                      Functions Definitions                                  *
 *******************************************************************************/

/*
 * Description :
 * Initialize ACD:
 * 1. Enable ADC
 * 2. Set ADC prescaler
 * 3. Disable ADC Interrupt
 */
void ADC_init(const ADC_ConfigType * Config_Ptr){

	/*
	 * Configure ADC Multiplexer Selection Register:
	 * 1. Clear Bit 5 to Adjust Result Right ADC register
	 * 2. Clear Bits 4,3,2,1,0 to Select channel ADC0
	 */
	ADMUX = 0;

	/* Configure Voltage Reference Selections for ADC by Bit 7:6 in ADMUX */
	ADMUX = (ADMUX & 0x3F) | ((Config_Ptr->ref_volt)<<REFS0);

	/*
	 * Configure ADC Control and Status Register A:
	 * 1. Set Bit 7(ADEN) to enable ADC
	 * 2. Clear Bit 5(ADATE) to disable ADC Auto Trigger
	 * 3. Clear Bit 3(ADIE) to disable ADC Interrupt
	 */
	ADCSRA = (1<<ADEN);

	/* Configure ADC Prescaler for ADC by Bits 2:0 in ADCSRA */
	ADCSRA = (ADCSRA & 0xF8) | ((Config_Ptr->prescaler)<<ADPS0);
}

/*
 * Description :
 * Select channel pin which needs to be converted from analog to digital and convert it
 * by using polling and return result
 */
uint16 ADC_readChannel(uint8 channel){

	/* Select channel pin */
	ADMUX = (ADMUX & 0xE0) | (channel & 0x07);

	/* Set Bit 6(ADSC) to start ADC Conversion*/
	ADCSRA |= (1<<ADSC);

	/* By using polling: wait until the flag is raised(i.e. ADC finish conversion) */
	while(BIT_IS_CLEAR(ADCSRA,ADIF));

	/* To Clear Flag*/
	SET_BIT(ADCSRA,ADIF);

	return ADC;
}
