#include <avr/io.h>

/*typedef struct{
    uint8_t state, i;
} button; */

void createButton(uint8_t buttonPin);
void waitButtonRelease(uint8_t buttonPin);
uint8_t getButtonClick(uint8_t buttonPin);
uint8_t testBit(uint8_t buttonPin);
uint8_t holdMode(uint8_t buttonPin, uint8_t state);
uint8_t switchMode(uint8_t buttonPin, uint8_t state);