#include "pins.h"
#include "../else/util2.h"

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

void isOut(uint8_t i){
	add_bit(*pins[i].ddr, pins[i].p);
}

void isIn(uint8_t i){
	rem_bit(*pins[i].ddr, pins[i].p);
}

void addBitPort(uint8_t i){
	add_bit(*pins[i].port, pins[i].p);
}

void remBitPort(uint8_t i){
	rem_bit(*pins[i].port, pins[i].p);
}
