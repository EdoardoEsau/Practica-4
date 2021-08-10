/*
 * @file    Practica 4.0.c
 * @brief   Application entry point.
 */
#include <stdio.h>
#include "board.h"
#include "peripherals.h"
#include "pin_mux.h"
#include "clock_config.h"
#include "MKL25Z4.h"
#include "fsl_debug_console.h"
#include "Libreria_ojo.h"
#include "PortsActivation.h"
/* TODO: insert other include files here. */

/* TODO: insert other definitions and declarations here. */
#define Limite_valor_1			200
#define Limite_valor_2			200
void Delay(long n);

int main(void) {
/*
	unsigned char Result1;
	unsigned char Result2;
	ADC0_init8b();
	ADC_read8b(8, &Result1);
	ADC_read8b(8D, &Result2);
	*/
	ADC0_init8b();
	PWM_vfnDriverInit ();
	//DPY_bInitialPosition ();
	//PWM_bfnAngleAdjustment ();


	while(1)
	{
		//DigitalRead('C', 2);
		//unsigned short x;
		//PWM_bfnAngleAdjustment(0);
		//Delay(0xFFFFF);
		//PWM_bfnAngleAdjustment(180);
		//Delay(0xFFFFFF);
		//PWM_bfnAngleAdjustment(-90);
		unsigned char Result1;
	    unsigned char Result2;
		ADC_read8b(8, &Result1);
		ADC_read8b(9, &Result2);

				if((Result1 >= Limite_valor_1) && (Result2 >= Limite_valor_2))
				{
					PWM_bfnAngleAdjustment(180);
					Delay(0xFFFFFA);

				}else if((Result1 <= Limite_valor_1) && (Result2 >= Limite_valor_2))
				{
					PWM_bfnAngleAdjustment(180);
					Delay(0xFFFFFA);

				}else if((Result1 >= Limite_valor_1) && (Result2 <= Limite_valor_2))
				{
					PWM_bfnAngleAdjustment(0);
					Delay(0xFFFFFA);
				}else if((Result1 <= Limite_valor_1) && (Result2 <= Limite_valor_2))
				{
					PWM_bfnAngleAdjustment(0);
					Delay(0xFFFFFA);
				}


		/*
		//DPY_bInitialPosition();
		PWM_bfnAngleAdjustment(0);
		Delay(0xFFFFF);
		PWM_bfnAngleAdjustment(360);
		//TPM0->CONTROLS[1].CnV = 2306;//Ciclo_Trabajo_0;
		Delay(0xFFFFF);
		PWM_bfnAngleAdjustment(0);
		Delay(0xFFFFF);
		*/
	}
    return 0 ;
}

void Delay(long n)
{
	while(n--);
	return;
	}
