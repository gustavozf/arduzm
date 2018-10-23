#include "led.h"
#include "../else/util2.h"
#include "../delay/delay2.h"


void createLed(uint8_t ledPin){
    setOut(ledPin);
    setLow(ledPin);
}

void turnOnLed(uint8_t ledPin){
    setHigh(ledPin);
}

void turnOffLed(uint8_t ledPin){
    setLow(ledPin);
}

void switchStateLed(uint8_t ledPin){
    swtBit(*(pins[ledPin].port), pins[ledPin].p);
}

void blinkLed(uint8_t ledPin, uint8_t timeMs){
    turnOnLed(ledPin);
    delayMs(timeMs);
    turnOffLed(ledPin);
    delayMs(timeMs);
}