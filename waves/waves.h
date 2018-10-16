#include <avr/io.h>

void PwmWave(uint8_t dutyCycle);
void startPwmWave(uint8_t i);
void CtcWave(uint8_t freq);
void startCtcWave(uint8_t i);
void calculaPrescaler(uint8_t freq)