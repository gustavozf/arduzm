#include "pins.h"
#include "../else/util2.h"
#include "../uart/uart.h"

Pin pins[14] = {
	{.pin = &PIND, .ddr = &DDRD, .port = &PORTD, .p = PD0},
	{.pin = &PIND, .ddr = &DDRD, .port = &PORTD, .p = PD1},
	{.pin = &PIND, .ddr = &DDRD, .port = &PORTD, .p = PD2},
	{.pin = &PIND, .ddr = &DDRD, .port = &PORTD, .p = PD3},
	{.pin = &PIND, .ddr = &DDRD, .port = &PORTD, .p = PD4},
	{.pin = &PIND, .ddr = &DDRD, .port = &PORTD, .p = PD5},
	{.pin = &PIND, .ddr = &DDRD, .port = &PORTD, .p = PD6},
	{.pin = &PIND, .ddr = &DDRD, .port = &PORTD, .p = PD7},
	{.pin = &PINB, .ddr = &DDRB, .port = &PORTB, .p = PB0},
	{.pin = &PINB, .ddr = &DDRB, .port = &PORTB, .p = PB1},
	{.pin = &PINB, .ddr = &DDRB, .port = &PORTB, .p = PB2},
	{.pin = &PINB, .ddr = &DDRB, .port = &PORTB, .p = PB3},
	{.pin = &PINB, .ddr = &DDRB, .port = &PORTB, .p = PB4},
	{.pin = &PINB, .ddr = &DDRB, .port = &PORTB, .p = PB5}
};

// ---------------------------------------- seta o fluxo (entrada/saida)
void setOut(uint8_t i){
	add_bit(*pins[i].ddr, pins[i].p);
}

void setIn(uint8_t i){
	rem_bit(*pins[i].ddr, pins[i].p);
}

// --------------------------------------- seta o valor presente (high/low)
void setHigh(uint8_t i){
	add_bit(*pins[i].port, pins[i].p);
}

void setLow(uint8_t i){
	rem_bit(*pins[i].port, pins[i].p);
}

// --------------------------------------- pega o valor presente no pino
uint8_t getValue(uint8_t i){
	return *pins[i].pin;
}

// -------------------------------------- ativa o pull up
void setPullUp(uint8_t i){
	// Se for de entrada
	if(!check_pin(*pins[i].ddr, pins[i].p)){
		*pins[i].port = ~(1<<pins[i].p);
	} else {
		printf("ERRO: O pino %d nao eh de entrada! Impossivel ativar o pull up.\n", i);
	}
}