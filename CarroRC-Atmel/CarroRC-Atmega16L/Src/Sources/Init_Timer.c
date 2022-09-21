/*
 * Init_Timer.c
 *  Author: chech
 */ 


#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>
#include "../Headers/Init_Timer.h"

#define F_CPU 16000000UL
#define FRECUENCIA 50 // 50Hz = 20mS
#define PRESCALER 64

void Init_Timer_1()
{

/************************************* TIMER 1 *************************************/

	//Se declaran las variables	
	
	cli(); //Se deshabilitan las interrupciones para asegurarse que no hay interrupciones encendidas
	sei(); //Se habilitan las interrupciones
	
	TCCR1A |= (1<<COM1A1); //Registros de comparación
	TCCR1B |= (1<<WGM13); //Modo de operación 8 (Frecuencia y Fase corregidas)
	TCCR1B |= (1<<CS11)|(1<<CS10); //Prescaler 64
	TCNT1 = 0; //Contador

	ICR1 = (F_CPU/2/PRESCALER/FRECUENCIA); //Valor de comparación
	OCR1A = (((F_CPU/2/PRESCALER/FRECUENCIA)*(50))/100); //Se configura el Duty Cycle

	//Banderas de la interrupción por Overflow
	TIMSK |= (1<<TOIE1);
	TIFR |= (1<<TOV1);
}

ISR(TIMER1_OVF_vect)
{
}


void Init_Timer_2()
{
	//int timerOverflowCount=0;
/************************************* TIMER 2 *************************************/

	TCCR2 |= (1<<WGM20); //Modo PWM, Phase Correct
	TCCR2 |= (1<<COM21);//Modo No Invertido (Limpia OC2)
	TCCR2 |= (1<<CS22)|(1<<CS21)|(1<<CS20); //Prescaler 1024 32mS
	OCR2 = 128; //Duty Cycle 128=50%

	TIMSK |= (1<<TOIE2);
	TIFR |= (1<<TOV2);
}

ISR(TIMER2_OVF_vect)
{		
}






















