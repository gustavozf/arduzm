#include "../pins/pins.h"
#include "../else/util2.h"

void PwmWave(uint8_t dutyCycle){
    OCR0A = dutyCycle;
}

void startPwmWave(uint8_t i){
    setOut(i);

    addBit(TCCR0A, WGM00);
    addBit(TCCR0A, WGM01); // Ativa o modo Fast PWM
    addBit(TCCR0A, COM0A1); // Configura o modo Fast PWM como padrão não-invertido
    addBit(TCCR0B, CS01); // Configura prescaler = 8;
}

void CtcWave(uint8_t freq){

}

void startCtcWave(uint8_t i){
    
}