#include "../pins/pins.h"
#include "../else/util2.h"
#include "./waves.h"

#define fosc 16000000

uint8_t prescalers[3][5] ={
//  1            8           64          256         1024
    {0b00000001, 0b00000010, 0b00000011, 0b00000100, 0b00000101}, //TC0
    {0b00000001, 0b00000010, 0b00000011, 0b00000100, 0b00000101}, //TC1
    {0b00000001, 0b00000010, 0b00000100, 0b00000110, 0b00000111}, //TC2
};

void ativaPrescaler(uint8_t tc, uint16_t pres){
    uint8_t i, j;
    uint8_t *cs0, *cs1, *cs2;

    switch(pres){
        case 1:    j=0; break;
        case 8:    j=1; break;
        case 64:   j=2; break;
        case 256:  j=3; break;
        case 1024: j=4; break;
    }

    /*switch(tc){

    }

    for(i=1; i <= 3; i++){
        if(checkPin(prescalers[tc][j], i)){
            addBit()
        } else {
            remBit()
        }
    }*/
}

uint8_t getPrescaler(uint16_t freq){
    if(freq < 31250) {
        return (uint8_t) 8;
    }else if(freq < 3906){
        return (uint8_t) 64;
    }else if(freq < 488){
        return (uint8_t) 256;
    }else if (freq < 122){
        return (uint8_t) 1024;
    } else {
        return (uint8_t) 1;
    }
}

void pwmWave(uint8_t dutyCycle){
    OCR0A = dutyCycle;
}

void ctcWave(uint16_t freq, uint8_t pin){
    uint8_t presc = getPrescaler(freq);
    uint8_t num = (uint8_t) (fosc/(2*(presc)*freq))-1;


    switch(pin){
        case 3: //PD3 OC2B
            ativaPrescaler((uint8_t) 2, pin);
            break;
        case 5: //PD5 OC0B
            break;
        case 6: //PD6 OC0A
            break;
        case 9: //PB1 OC1A
            break;
        case 10: //PB2 OC1B
            break;
        case 11: //PB3 OC2A
            break;
        default:
            setHigh(pin);
    }
}

void startPwmWave(uint8_t pin){
    setOut(pin);

    switch(pin){
        case 3: //PD3 OC2B
            addBit(TCCR2B, WGM20);
            addBit(TCCR2B, WGM21);  // Ativa o modo Fast PWM
            addBit(TCCR2B, COM2B1);

            addBit(TCCR2B, CS21);
            break;

        case 5: //PD5 OC0B
            break;

        case 6: //PD6 OC0A
            break;

        case 9: //PB1 OC1A
            break;

        case 10: //PB2 OC1B
            break;

        case 11: //PB3 OC2A
            break;

        default:
            setHigh(pin);
    }


 // Configura o modo Fast PWM como padrão não-invertido
 // Configura prescaler = 8;
}


void startCtcWave(uint8_t i){
    setOut(i);

    if((i == 3) || (i == 5) || (i == 6) || (i == 9) || (i == 10) || (i==11)){
        
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
