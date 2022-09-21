/*
 * Init_Usart.c
 *  Author: chech
 */ 

#include <avr/io.h>
#include "../Headers/Init_Usart.h"

#define F_CPU 16000000UL

void Init_Usart()
{	
	DDRD |= (1<<DDD3);
	PORTD |= (0<<PORTD3);
	
	UDR = 1; 
	UCSRA |= (1<<RXC)|(0<<TXC)|(1<<UDRE)|(0<<FE)|(0<<DOR);
	UCSRB |= (1<<RXEN)|(1<<TXEN);
	UCSRC |= (1<<URSEL)|(1<<UMSEL)|(1<<UPM1)|(1<<UCSZ1)|(1<<UCSZ0)|(0<<UCPOL);
	UBRRL = 416;  
	
}

ISR(USART_RXC_vect)
{
	PORTD |=~ (1<<PIND3);
}





