/*
 * adc.h
 *
 *  Created on: 21-Aug-2026
 *      Author: dange
 */

#ifndef ADC_H_
#define ADC_H_
#include "stm32f4xx.h"
void start_conversion(void);
uint32_t adc_read(void);
void pa1_adc_init(void);
#endif /* ADC_H_ */
