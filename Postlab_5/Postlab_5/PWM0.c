/*
 * PWM0.c
 *
 * Created: 4/15/2026 5:42:23 PM
 *  Author: obreg
 */ 

#include <avr/io.h>
#include <avr/interrupt.h>
#include "PWM0.h"

volatile uint8_t duty_cycle = 0;
volatile uint8_t counter = 0;

void PWM0_init(void) {

	// Inicializamos el pin D5 como salida
	DDRD |= (1 << PD5);

	// Timer0 en modo normal
	TCCR0A = 0;

	// Prescaler 1
	TCCR0B = (1 << CS00);

	// Habilitar interrupción por overflow
	TIMSK0 = (1 << TOIE0);

	// Habilitar interrupciones globales
	sei();
}

// Set duty (0–255)
void PWM0_setDuty(uint8_t duty) {
	duty_cycle = duty;
}

ISR(TIMER0_OVF_vect) {

	counter++;

	// Reiniciar contador
	if (counter >= 100)
	counter = 0;

	// Generar PWM
	if (counter < duty_cycle)
	PORTD |= (1 << PD5);   // LED encendido
	else
	PORTD &= ~(1 << PD5);  // LED apagado
}