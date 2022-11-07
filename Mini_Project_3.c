/*
 ================================================================================================
 Name        : Mini_Project_3.c
 Author      : Mohamed Khaled
 Description : Fan Controller system
 Date        : 10/4/2022
 ================================================================================================
 */

#include "adc.h"
#include "lcd.h"
#include "dc_motor.h"
#include "lm35_sensor.h"

typedef enum{
	NO_DUTY_CYCLE = 0 ,DUTY_CYCLE_25 = 25, DUTY_CYCLE_50 = 50, DUTY_CYCLE_75 = 75,
	DUTY_CYCLE_100 = 100
}DutyCycleStates;

int main(void){

	/* Variable to Store Current Temperature */
	uint8 currTemp = 0;

	/* Configure ADC settings */
	ADC_ConfigType config = {Internal, F_CPU_8};

	/* Initiate Drivers */
	LCD_init();			/* Initiate LCD */
	DcMotor_Init();		/* Initiate DC Motor*/
	ADC_init(&config);	/* Initiate ADC */

	LCD_displayStringRowColumn(0, 2, "FAN is ");
	LCD_displayStringRowColumn(1, 2, "Temp =    C");

	for(;;){
		currTemp = LM35_getTemperature();

		if(currTemp < 30){

			/* To display Fan State */
			LCD_displayStringRowColumn(0, 9, "OFF");

			/* Move Cursor to display the Temperature Value in the right place in LCD*/
			LCD_moveCursor(1, 9);
			LCD_integerToString(currTemp);
			LCD_displayCharacter(' ');

			/* To turn off the fan */
			DcMotor_Rotate(STOP, NO_DUTY_CYCLE);
		}
		else if((currTemp <60) && (currTemp >= 30)){

			/* To display Fan State */
			LCD_displayStringRowColumn(0, 9, "ON ");

			/* Move Cursor to display the Temperature Value in the right place in LCD*/
			LCD_moveCursor(1, 9);
			LCD_integerToString(currTemp);
			LCD_displayCharacter(' ');

			/* To turn on the fan with 25% of its maximum speed */
			DcMotor_Rotate(CW, DUTY_CYCLE_25);
		}
		else if((currTemp <90) && (currTemp >= 60)){

			/* To display Fan State */
			LCD_displayStringRowColumn(0, 9, "ON ");

			/* Move Cursor to display the Temperature Value in the right place in LCD*/
			LCD_moveCursor(1, 9);
			LCD_integerToString(currTemp);
			LCD_displayCharacter(' ');

			/* To turn on the fan with 50% of its maximum speed */
			DcMotor_Rotate(CW, DUTY_CYCLE_50);
		}
		else if((currTemp <120) && (currTemp >= 90)){

			/* To display Fan State */
			LCD_displayStringRowColumn(0, 9, "ON ");

			/* Move Cursor to display the Temperature Value in the right place in LCD*/
			LCD_moveCursor(1, 9);

			if(currTemp < 100){
				LCD_integerToString(currTemp);
				LCD_displayCharacter(' ');
			}
			else{
				LCD_integerToString(currTemp);
			}

			/* To turn on the fan with 75% of its maximum speed */
			DcMotor_Rotate(CW, DUTY_CYCLE_75);
		}
		else if(currTemp >= 120){

			/* To display Fan State */
			LCD_displayStringRowColumn(0, 9, "ON ");

			/* Move Cursor to display the Temperature Value in the right place in LCD*/
			LCD_moveCursor(1, 9);
			LCD_integerToString(currTemp);

			/* To turn on the fan with 100% of its maximum speed */
			DcMotor_Rotate(CW, DUTY_CYCLE_100);
		}
	}
}
