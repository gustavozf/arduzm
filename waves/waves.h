#include <avr/io.h>

void pwmWave(uint8_t dutyCycle);
void startPwmWave(uint8_t pin);
void ctcWave(uint16_t freq);
void startCtcWave(uint8_t pin);
uint8_t ativaPrescaler(uint16_t freq);
void resetTCCR0A();
void resetTCCR0B();