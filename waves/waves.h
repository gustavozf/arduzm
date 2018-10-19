#include <avr/io.h>

typedef struct {
    uint8_t *ocr;
    uint8_t *tccr;
    uint8_t com, wgm;
    uint8_t cs[3];
} wavePins;

extern wavePins wPins[6];

void pwmWave(uint8_t dutyCycle);
void startPwmWave(uint8_t i);
void ctcWave(uint16_t freq);
void startCtcWave(uint8_t i);
uint8_t ativaPrescaler(uint16_t freq);
void resetTCCR0A();
void resetTCCR0B();