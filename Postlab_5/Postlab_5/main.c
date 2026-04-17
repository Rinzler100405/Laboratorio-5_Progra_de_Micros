/*
 * Postlab_5.c
 *
 * Created: 4/15/2026 5:35:41 PM
 * Author : obreg
 */ 

/****************************************/
// Encabezado (Libraries)
#define F_CPU 16000000UL
#include <avr/io.h>
#include "PWM1.h"
#include "PWM2.h"
#include "PWM0.h"
#include "ADC.h"
/****************************************/
// Function prototypes

/****************************************/
// Main Function
int main(void)
{
		// Llamamos a la función declarada en librería para inicializar el PWM en el Timer 1
		PWM1_init();
		
		// Llamamos a la función declarada en librería para inicializar el PWM en el Timer 2
		PWM2_init();
		
		// Llamamos a la función declarada en librería ára inicializar el PWM manual (Timer 0)
		PWM0_init();
		
		// Llamamos a la función declarada en librería para inicializar el ADC en pin a seleccionar
		ADC_init();
			
	while (1)
	{

			
		// Realizamos la lectura del ADC habilitado en  A0, A1 y A2
		uint16_t	pot0	=	ADC_read(0); // Lectura en el pin A0
		uint16_t	pot1	=	ADC_read(1); // Lectura en el pin A1
		uint16_t	pot2	=	ADC_read(2); // Lectura en el pin A2
			
		// Servo B	(D11)
		uint8_t anguloB = pot1 / 4;
		PWM2_setA(anguloB);
		
		// Servo A	(D9)
		uint16_t anguloA = ((uint32_t)pot2 * 180) / 1023;
		PWM1_setServoA(anguloA);
		
		// LED variable (D5)
		uint8_t duty = pot0 / 10; // 0–100
		PWM0_setDuty(duty);
		
		
	}
}

/****************************************/
// NON-Interrupt subroutines

/****************************************/
// Interrupt routines