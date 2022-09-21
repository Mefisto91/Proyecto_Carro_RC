///*
 //* CarroRC-Atmega16L.c
 //*
 //* Created: 11/10/2021 2:00:08 p. m.
 //* Author : chech
 //*/ 
//
#include <avr/io.h>
#include "Src/Headers/Init_Perifericos.h"
#include "Src/Headers/Init_Timer.h"
#include <util/delay.h>

#define F_CPU 16000000UL

int main(void)
{

	Init_Perifericos();
	//Init_Timer_1();
	//Init_Timer_2();
	Init_Usart();
	
  	while (1)
  	{

  	}
}










