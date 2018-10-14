#include <avr/io.h>

void startUltrasonic(uint8_t echo, uint8_t trigger);
uint16_t getSonarDistance(uint8_t echo, uint8_t trigger);