#include "../pins/pins.h"
#include "../else/util2.h"

#define fosc 16000000

void PwmWave(uint8_t dutyCycle){
    OCR0A = dutyCycle;
}

void resetWave(){
    remBit(TCCR0B, CS00);
    remBit(TCCR0B, CS01);
    remBit(TCCR0B, CS02);
    remBit(TCCR0A, WGM00);
    remBit(TCCR0A, WGM01);
}

void startPwmWave(uint8_t i){
    setOut(i);

    resetWave();

    addBit(TCCR0A, WGM00);
    addBit(TCCR0A, WGM01); // Ativa o modo Fast PWM
    addBit(TCCR0A, COM0A1); // Configura o modo Fast PWM como padrão não-invertido
    addBit(TCCR0B, CS01); // Configura prescaler = 8;
}

void CtcWave(uint8_t freq){
    OCR0A = (fosc/(2*(ativaPrescaler(freq))*freq))-1;
}

void startCtcWave(uint8_t i){
    setOut(i);

    resetWave();

    addBit(TCCR0A, WGM01); // Ativa o modo CTC
    addBit(TCCR0A, COM0A0); // Configura o modo CTC = OCR0A
}


uint8_t ativaPrescaler(uint8_t freq){
    uint8_t ret = 1;

    if(freq >= 125000) {
        addBit(TCCR0B, CS01); //prescaler = 8
        
        ret = 8;
    }else if(freq >= 31250){
        addBit(TCCR0B, CS01); //prescaler = 64
        addBit(TCCR0B, CS00);
    
        ret = 64;
    }else if(freq >= 7812){
        addBit(TCCR0B, CS02); // prescaler = 256
    
        ret = 256;
    }else if (freq >= 30){
        addBit(TCCR0B, CS02); // prescaler = 1024
        addBit(TCCR0B, CS00);
    
        ret = 1024;
    }

    return ret;
}

/* 
    prescaler = 8

max -> 16000000/2*8(1+0) = 10000000hz
min -> 16000000/2*8(1+255) = 3906,25


8 =    [125000 , 1000000]
64 =   [31250  , 125000)
256 =  [7812   , 31250)
1024 = [30     , 7812)

*/