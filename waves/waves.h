#include <avr/io.h>

void pwmWave(uint8_t dutyCycle, uint8_t pin);
void startPwmWave(uint8_t pin);
void ctcWave(uint16_t freq, uint8_t pin);
void startCtcWave(uint8_t pin);
void ativaPrescaler(uint8_t tc, uint16_t pres);
uint8_t getPrescaler(uint16_t freq);