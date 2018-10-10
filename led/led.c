#include "led.h"
#include "../else/util2.h"


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
    swt_bit(*(pins[i].port), pins[i].p);
}

void blinkLed(uint8_t i, uint8_t time){
    turnOnLed(i);
    _delay_ms(150); // LEMBRAR DE MUDAR PELO NOSSO
    turnOffLed(i);
}