/*
 * ADC.h
 *
 * Created: 4/14/2026 3:16:57 PM
 *  Author: obreg
 */ 

// "If not Define"
#ifndef ADC_H_
#define ADC_H_

// Incluye la librería en C, para poder usar tipos de variables, como u_int8, etc...
#include <stdint.h>

// Prototipo de función para inicializar el ADC
void ADC_init(void);

// Variable que realiza la lectura del pin configurado en el ADC (A0, A1, etc...)
uint16_t ADC_read(uint8_t channel);



#endif /* ADC_H_ */