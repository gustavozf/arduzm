#include <avr/io.h>

void PwmWave(uint8_t dutyCycle);
void startPwmWave(uint8_t i);
void CtcWave(uint16_t freq);
void startCtcWave(uint8_t i);
uint8_t ativaPrescaler(uint16_t freq);
void resetTCCR0A();
void resetTCCR0B();