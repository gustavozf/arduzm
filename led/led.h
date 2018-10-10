#include "../pins/pins.h"
#define F_CPU 16000000UL // UL == Unsigned Long
#include <util/delay.h>

void createLed(uint8_t i);
void turOnLed(uint8_t i);
void turnOffLed(uint8_t i);
void switchStateLed(uint8_t i);
void blinkLed(uint8_t i, uint8_t time);