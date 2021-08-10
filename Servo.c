/*
 * Servo.c
 *
 *  Created on: 6 jul. 2021
 *      Author: danovg
 */
#include "MKL25Z4.h"
#include "Libreria_ojo.h"

#define scgc_TPM0			0x1000000
#define Activar_mux			0x400
#define Activar_clk_C		0x800
#define Activar_SOPT2		0x1000000
#define Activar_SC			0xD//DIVIDE ENTRE 16
#define Activar_CnSC		0x28
//#define Activar_MOD			26249
#define Activar_MOD			13125


//Valores de interpolacion
//#define Ciclo_Trabajo_180	3200
//#define Ciclo_Trabajo_0		1312
#define Ciclo_Trabajo_180	1990
#define Ciclo_Trabajo_0		720
#define zero_degrees			0
#define cientoochenta_grados			180





//void PWM_vfnDriverInit (void);
void DPY_bInitialPosition (void);
void PWM_bfnAngleAdjustment (int bNewAngle);//int bNewAngle


void PWM_vfnDriverInit (void)
{
	SIM->SCGC5 |= Activar_clk_C;
	SIM->SCGC6 |= scgc_TPM0;
	PORTC->PCR[2] = Activar_mux;
	SIM->SOPT2 |= Activar_SOPT2;
	TPM0->SC = 0;
	TPM0->CONTROLS[1].CnSC = Activar_CnSC;
	TPM0->MOD = Activar_MOD;
	TPM0->CONTROLS[1].CnV = Ciclo_Trabajo_0;
	TPM0->SC = Activar_SC;
	return;
}

void DPY_bInitialPosition (void)
{

	TPM0->CONTROLS[1].CnV = Ciclo_Trabajo_0;//Ciclo_Trabajo_0;

	return;

}

void PWM_bfnAngleAdjustment (int bNewAngle)//int bNewAngle
{
	int X;
	//interpolacion
	/*
	 * 26249 = 0.02s que es el ciclo de trabajo que requiere el servo
	 *       = 0.001s es para que se ponga a 0 grados el servo
	 *
	 *  0° = 1312
	 *
	 *  Angulo = ¿X?
	 *
	 *  180° = 2624
	 *
	 * x - 1181         3200 -1181
	 * -----------  =  -------------
	 * Angulo - 0°      180° - 0°
	 *
	 * Despejando para x
	 *
	 *     (Angulo - 0°)(3200 - 1181)
	 * x = -------------------------- + 1181
	 *            (180° - 0°)
	 *
	 *
	 */

	X = (((bNewAngle - zero_degrees)*(Ciclo_Trabajo_180 - Ciclo_Trabajo_0))/(cientoochenta_grados - zero_degrees)) + Ciclo_Trabajo_0;


       TPM0->CONTROLS[1].CnV = X;
     //TPM0->CNT = X;
		return;
}
