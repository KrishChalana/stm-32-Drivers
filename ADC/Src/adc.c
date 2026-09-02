#include "adc.h"

#define GPIOAEN (1U<<0)  // --enables clock for AHB1ENR REGISTER
#define ADC1EN (1U<<8) // enables adc1
#define ADC_CH1 (1U<<0) // selects channel 1 for adc in sqr3 register
#define ADC_SEQ_LEN_1 0x00
#define CR2_ADCON (1U<<0)
#define CR2_CONT (1U<<1)
#define CR2_SWSTART (1U<<30)
#define SR_EOC (1U<<1)

void pa1_adc_init(void){
	RCC->AHB1ENR |= GPIOAEN;
	// SETS GPIOA PIN 1 TO ANALOG MODE..
	GPIOA->MODER |= (1U<<2);
	GPIOA->MODER |= (1U<<3);

	// Enable clock access to the ADC Module
	RCC->APB2ENR |= ADC1EN;

	ADC1->SQR3 = ADC_CH1;
	//SET CONVERSION SEQUENCE LENGTH - HERE ONLY 1 PIN;
	ADC1->SQR1 = ADC_SEQ_LEN_1;

	ADC1->CR2 |= CR2_ADCON;


}


void start_conversion(void){
	// ENABLES CONTINOUS CONVERSION PROCESS
	ADC1->CR2 |= CR2_CONT;
	// STARTS THE CONVERSION PROCESS
	ADC1->CR2 |= CR2_SWSTART;
}


uint32_t adc_read(void){
// wait for conversion to complete
	while(!(ADC1->SR & SR_EOC)){}

	return (ADC1->DR);

}
