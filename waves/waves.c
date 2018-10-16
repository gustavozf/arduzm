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
    OCR0A = freq;
    calculaPrescaler(freq); 
}

void startCtcWave(uint8_t i){
    setOut(i);

    addBit(TCCR0A, WGM01); // Ativa o modo CTC
    addBit(TCCR0A, COM0A0); // Configura o modo CTC = OCR0A
}

void calculaPrescaler(uint8_t freq){
    if(freq > TANTO) && (freq < TANTO){
        addBit(TCCR0B, CS01); //prescaler = 8
    }else if(freq < TANTO){
        addBit(TCCR0B, CS01); //prescaler = 64
        addBit(TCCR0B, CS00);
    }else if(freq < TANTO){
        addBit(TCCR0B, CS02); // prescaler = 256
    }else{
        addBit(TCCR0B, CS02); // prescaler = 1024
        addBit(TCCR0B, CS00);
    }
}