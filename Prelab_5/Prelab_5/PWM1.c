/*
 * PWM1.c
 *
 * Created: 4/14/2026 1:54:47 PM
 *  Author: obreg
 */ 

// Incluimos definiciones propias del Atmega328p
#include <avr/io.h>

// Incluimos la librería creada
#include "PWM1.h"

// Declaramos la funcion que inicializa el Timer 1 en PWM
void PWM1_init(void) {
	
	// Configuramos los pines D9 y D10 como salidas
	DDRB |= (1 << PB1) | (1 << PB2);

	// Configuración del Timer 1 para PWM en D9 y D10
	TCCR1A = (1 << COM1A1) | (1 << COM1B1) | (1 << WGM11);
	TCCR1B = (1 << WGM13) | (1 << WGM12) | (1 << CS11);

	// Definimos el periodo del PWM para obtener una frecuencia de 50 Hz
	ICR1 = 39999;

	// Inicializa los Servos en posición central
	OCR1A = 3000;
	OCR1B = 3000;
}

// Función para controlar el Servo en D9
void PWM1_setServoA(uint16_t angulo) {
	// Conversión del ángulo para pulso a enviar al Servo
	uint16_t pulso = 1800 + ((uint32_t)angulo * 2400) / 180;
	
	// Actualizar pulso en Servo
	OCR1A = pulso;
}

// Función para controlar el Servo en D10
void PWM1_setServoB(uint16_t angulo) {
	// Conversión del ángulo para pulso a enviar al Servo
	uint16_t pulso = 1800 + ((uint32_t)angulo * 2400) / 180;
	
	// Actualizar pulso en Servo
	OCR1B = pulso;
}
