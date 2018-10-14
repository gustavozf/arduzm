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
void setOut(uint8_t i){
	addBit(*(pins[i].ddr), pins[i].p);
}

void setIn(uint8_t i){
	remBit(*(pins[i].ddr), pins[i].p);
}

// --------------------------------------- seta o valor presente (high/low)
void setHigh(uint8_t i){
	addBit(*(pins[i].port), pins[i].p);
}

void setLow(uint8_t i){
	remBit(*(pins[i].port), pins[i].p);
}

// --------------------------------------- pega o valor presente no pino
uint8_t getValue(uint8_t i){
	return *(pins[i].pin);
}

// -------------------------------------- ativa o pull up
void setPullUp(uint8_t i){
	// Se for de entrada
	if(!checkPin(*(pins[i].ddr), pins[i].p)){
		//*(pins[i].port) = ~(1<<pins[i].p);
		setHigh(i);
	} /*else {
		printf("ERRO: O pino %d nao eh de entrada! Impossivel ativar o pull up.\n", i);
	}*/
}