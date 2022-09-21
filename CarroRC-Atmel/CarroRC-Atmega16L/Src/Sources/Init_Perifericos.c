/* 
 * Init_Perifericos.c
 * Author: chech
 */ 


#include <avr/io.h>
#include "../Headers/Init_Perifericos.h"

#define F_CPU 16000000UL

void Init_Perifericos()
{
	/*DDD5 Salida Timer1
	  DDD7 Salida Timer2*/
	DDRD |= (0<<DDD0)|(1<<DDD1)|(1<<DDD5)|(1<<DDD7);
	PORTD |= (1<<PORTD0)|(0<<PORTD1)|(1<<PORTD5)|(1<<PORTD7);  
	
	/*DDA0 Salida Luz Delantera*/
	DDRA |= (1<<DDA0)|(1<<DDA6);
	PORTA |= (1<<PORTA0)|(1<<PORTA6);	
}








