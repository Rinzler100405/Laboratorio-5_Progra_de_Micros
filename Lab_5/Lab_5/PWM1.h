/*
 * PWM1.h
 *
 * Created: 4/14/2026 1:55:27 PM
 *  Author: obreg
 */ 

// "If not Define"
#ifndef PWM1_H_
#define PWM1_H_

// Incluye la librería en C, para poder usar tipos de variables, como u_int8, etc...
#include <stdint.h>


// Prototipo de función para inicializar el Timer 1 en modo Fast PWM
void PWM1_init(void);

// Prototipo de función para el control del Servo conectado en D9
void PWM1_setServoA(uint16_t angulo1);

// Prototipo de función para el control del Servo conectado en D10
void PWM1_setServoB(uint16_t angulo1);

// Fin del bloque de progra
#endif /* PWM1_H_ */