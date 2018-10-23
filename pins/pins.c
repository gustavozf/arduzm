#include "./pins.h"
#include "../else/util2.h"
#include "../uart/uart.h"

Pin pins[14] = {
	{&PIND, &DDRD, &PORTD, PD0},
	{&PIND, &DDRD, &PORTD, PD1},
	{&PIND, &DDRD, &PORTD, PD2},
	{&PIND, &DDRD, &PORTD, PD3},
	{&PIND, &DDRD, &PORTD, PD4},
	{&PIND, &DDRD, &PORTD, PD5},
	{&PIND, &DDRD, &PORTD, PD6},
	{&PIND, &DDRD, &PORTD, PD7},
	{&PINB, &DDRB, &PORTB, PB0},
	{&PINB, &DDRB, &PORTB, PB1},
	{&PINB, &DDRB, &PORTB, PB2},
	{&PINB, &DDRB, &PORTB, PB3},
	{&PINB, &DDRB, &PORTB, PB4},
	{&PINB, &DDRB, &PORTB, PB5}
};

// ---------------------------------------- seta o fluxo (entrada/saida)
void setOut(uint8_t pin){
	addBit(*(pins[pin].ddr), pins[pin].p);
}

void setIn(uint8_t pin){
	remBit(*(pins[pin].ddr), pins[pin].p);
}

// --------------------------------------- seta o valor presente (high/low)
void setHigh(uint8_t pin){
	addBit(*(pins[pin].port), pins[pin].p);
}

void setLow(uint8_t pin){
	remBit(*(pins[pin].port), pins[pin].p);
}

// --------------------------------------- pega o valor presente no pino
uint8_t getValue(uint8_t pin){
	return *(pins[pin].pin);
}

// -------------------------------------- ativa o pull up
void setPullUp(uint8_t pin){
	// Se for de entrada
	if(!checkPin(*(pins[pin].ddr), pins[pin].p)){
		//*(pins[i].port) = ~(1<<pins[i].p);
		setHigh(pin);
	} /*else {
		printf("ERRO: O pino %d nao eh de entrada! Impossivel ativar o pull up.\n", i);
	}*/
}