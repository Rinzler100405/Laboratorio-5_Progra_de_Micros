/*
 * PWM2.c
 *
 * Created: 4/15/2026 4:05:22 PM
 *  Author: obreg
 */ 

// Incluimos definiciones propias del Atmega328p
#include <avr/io.h>

// Incluimos la librería creada
#include "PWM2.h"

// Declaramos la funcion que inicializa el Timer 2 en PWM
void PWM2_init(void) {
	
	// Configuramos los pines D3 y D11 como salidas
	DDRD |= (1 << PD3);
	DDRB |= (1 << PB3);

	
	// Fast PWM en Timer2, no invertido en ambos canales
	TCCR2A = (1 << COM2A1) | (1 << COM2B1) | (1 << WGM21) | (1 << WGM20);
	
	// Prescaler 64
	TCCR2B = (1 << CS22);



	// Inicializa PWM en apagado
	OCR2A = 0;
	OCR2B = 0;
}

// Función para controlar el PWM en D11
void PWM2_setA(uint8_t pulso2) {
	
	// Actualizar pulso en PWM (0-255)
	OCR2A = pulso2;
}

// Función para controlar el PWM en D3
void PWM2_setB(uint8_t pulso2) {
	
	// Actualizar pulso en PWM (0-255)
	OCR2B = pulso2;
}