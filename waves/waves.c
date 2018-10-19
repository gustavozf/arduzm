#include "../pins/pins.h"
#include "../else/util2.h"
#include "./waves.h"

#define fosc 16000000

/*
wavePins wPins[] = {
    {&OCR2B, &TCCR2B, COM
    {&OCR0B, &TCCR0B, COM
    {&OCR0A, &TCCR0A, COM
    {&OCR1A, &TCCR1A, COM
    {&OCR1B, &TCCR1B, COM
    {&OCR2A, &TCCR2A, COM
};

3  = 2 B
5  = 0 B
6  = 0 A
9  = 1 A
10 = 1 B
11 = 2 A
*/

uint8_t ativaPrescaler(uint16_t freq){
    uint8_t ret = 1;

    if(freq < 31250) {
        addBit(TCCR0B, CS01); //prescaler = 8
        
        ret = (uint8_t) 8;
    }else if(freq < 3906){
        addBit(TCCR0B, CS01); //prescaler = 64
        addBit(TCCR0B, CS00);
    
        ret = (uint8_t) 64;
    }else if(freq < 488){
        addBit(TCCR0B, CS02); // prescaler = 256
    
        ret = (uint8_t) 256;
    }else if (freq < 122){
        addBit(TCCR0B, CS02); // prescaler = 1024
        addBit(TCCR0B, CS00);
    
        ret = (uint8_t) 1024;
    }

    return ret;
}

void resetTCCR0B(){
    remBit(TCCR0B, CS00);
    remBit(TCCR0B, CS01);
    remBit(TCCR0B, CS02);
}

void resetTCCR0A(){
    remBit(TCCR0A, WGM00);
    remBit(TCCR0A, WGM01);
    remBit(TCCR0A, COM0A0);
    remBit(TCCR0A, COM0A1); 
}

void pwmWave(uint8_t dutyCycle){
    OCR0A = dutyCycle;
}

void ctcWave(uint16_t freq){
    resetTCCR0B();
    OCR0A = (uint8_t) (fosc/(2*(ativaPrescaler(freq))*freq))-1;
}

void startPwmWave(uint8_t i){
    setOut(i);

    if((i == 3) || (i == 5) || (i == 6) || (i == 9) ||  (i == 10) || (i==11)){

        resetTCCR0A();
        resetTCCR0B();

        addBit(TCCR0A, WGM00);
        addBit(TCCR0A, WGM01); // Ativa o modo Fast PWM
        addBit(TCCR0A, COM0A1); // Configura o modo Fast PWM como padrão não-invertido
        addBit(TCCR0B, CS01); // Configura prescaler = 8;

    } else {
        setHigh(i);
    }
}


void startCtcWave(uint8_t i){
    setOut(i);

    if((i == 3) || (i == 5) || (i == 6) || (i == 9) || (i == 10) || (i==11)){
        resetTCCR0A();

        addBit(TCCR0A, WGM01); // Ativa o modo CTC
        addBit(TCCR0A, COM0A0); // Configura o modo CTC = OCR0A

    } else {
        setHigh(i);
    }
}



/* 

Utilizado:
1 =    [31250, 4000000]
8 =    [3906 , 31250]
64 =   [488  , 3906)
256 =  [122  , 488)
1024 = [30   , 122)

Calculado:
1 =    [31250, 4000000]
8 =    [3906 , 500000]
64 =   [488  , 62500]
256 =  [122  , 15625]
1024 = [30   , 3906]

*/