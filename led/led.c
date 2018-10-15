#include "led.h"
#include "../else/util2.h"
#include "../delay/delay2.h"


void createLed(uint8_t i){
    setOut(i);
    setLow(i);
}

void turnOnLed(uint8_t i){
    setHigh(i);
}

void turnOffLed(uint8_t i){
    setLow(i);
}

void switchStateLed(uint8_t i){
    swtBit(*(pins[i].port), pins[i].p);
}

void blinkLed(uint8_t i, uint16_t timeMs){
    turnOnLed(i);
    delayMs(timeMs);
    turnOffLed(i);
    delayMs(timeMs);
}