/*
 * ADC_ojo.c
 *
 *  Created on: 6 jul. 2021
 *      Author: danovg
 */

#include "MKL25Z4.h"
#include "Libreria_ojo.h"

void ADC0_init8b(void);
void ADC_read8b(unsigned char channelNumber, unsigned char *ADC_Result);

void ADC0_init8b(void)
{
	SIM->SCGC6 = 0x8000000; //RELOJ ADC0
	SIM->SCGC5 = 0x400; //ACTIVO TODOS LOS PUERTOS DE RELOJ POR SI ACASO
	PORTB->PCR[0] = 0;// PORTB0
	PORTB->PCR[1] = 0;// PORTB1
	ADC0->CFG1 = 0x54; // 8 BITS (0x76 10 BITS)
	ADC0->CFG1 |= (ADC_CFG1_ADLPC(1)); //Configuración ADLPC (Low power confuguration)
	ADC0->SC1[0] = ADC_SC1_ADCH(31);
	return;
}
void ADC_read8b(unsigned char channelNumber, unsigned char *ADC_Result)
{
	//unsigned short ADC_Result;

	ADC0->SC1[0] = channelNumber & ADC_SC1_ADCH_MASK;

	while(ADC0->SC2 & ADC_SC2_ADACT_MASK);
	while(!(ADC0->SC1[0] & ADC_SC1_COCO_MASK));// Conversion complete flag
	*ADC_Result = ADC0->R[0];
	//return;
}

