#include <avr/io.h>

typedef struct{
    uint8_t state, pressed, i;
} button;

void createButton(uint8_t i);
void waitButtonRelease(uint8_t i);
uint8_t getButtonClick(uint8_t i);
uint8_t testBit(uint8_t i);