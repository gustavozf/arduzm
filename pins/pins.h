#include "../else/util2.h"
#include <avr/io.h>
#include <avr/portpins.h> // Para mostrar os pins, como o PB5


typedef struct{
	volatile uint8_t* pin;
	volatile uint8_t* ddr;
	volatile uint8_t* port;
	const uint8_t p;
} Pin;

extern Pin pins[14];

void isOut(uint8_t i);
void isIn(uint8_t i);
void addBitPort(uint8_t i);
void remBitPort(uint8_t i);