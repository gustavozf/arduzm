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

void setOut(uint8_t i);
void setIn(uint8_t i);
void setHigh(uint8_t i);
void setLow(uint8_t i);
uint8_t getValue(uint8_t i);
void setPullUp(uint8_t i);