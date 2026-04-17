/*
 * ADC.c
 *
 * Created: 4/14/2026 3:16:45 PM
 *  Author: obreg
 */ 

#include <avr/io.h>
#include "ADC.h"

// Función de inicializar ADC
void ADC_init(void) {
	// Referencia AVcc (5V)
	ADMUX = (1 << REFS0);

	// Habilitar ADC y prescaler 128
	ADCSRA = (1 << ADEN) | (1 << ADPS2) | (1 << ADPS1) | (1 << ADPS0);
}

// Lectura del pin configurado con el ADC
uint16_t ADC_read(uint8_t channel) {

	// Mantener referencia y limpiar solo canal
	ADMUX = (1 << REFS0) | (channel & 0x0F);

	// Pequeño tiempo de estabilización, o mas bien un delay
	for (volatile int i = 0; i < 100; i++);

	// Primera conversión 
	ADCSRA |= (1 << ADSC);
	while (ADCSRA & (1 << ADSC));

	// Segunda conversión, para mejorar la precisión de la lectura del ADC
	ADCSRA |= (1 << ADSC);
	while (ADCSRA & (1 << ADSC));

	// Retornar resultado 
	return ADC;
}