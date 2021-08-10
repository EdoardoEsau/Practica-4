/*
 * Libreria_ojo.h
 *
 *  Created on: 8 jul. 2021
 *      Author: danovg
 */

#ifndef LIBRERIA_OJO_H_
#define LIBRERIA_OJO_H_
//ADC
extern void ADC0_init8b(void);
extern void ADC_read8b(unsigned char channelNumber, unsigned char *ADC_Result);

//PWM
extern void PWM_vfnDriverInit (void);
extern void DPY_bInitialPosition (void);
extern void PWM_bfnAngleAdjustment (int bNewAngl);
#endif /* LIBRERIA_OJO_H_ */
