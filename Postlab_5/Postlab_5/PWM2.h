/*
 * PWM2.h
 *
 * Created: 4/15/2026 4:06:07 PM
 *  Author: obreg
 */ 


#ifndef PWM2_H_
#define PWM2_H_

// Incluye la librería en C, para poder usar tipos de variables, como u_int8, etc...
#include <stdint.h>


// Prototipo de función para inicializar el Timer 2 en modo Fast PWM
void PWM2_init(void);

// Prototipo de función para el control del PWM conectado en D3
void PWM2_setA(uint8_t pulso2);

// Prototipo de función para el control del PWM conectado en D11
void PWM2_setB(uint8_t pulso2);


// Fin del bloque de progra
#endif /* PWM2_H_ */