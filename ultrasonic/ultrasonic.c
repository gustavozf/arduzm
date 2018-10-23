#include "../delay/delay2.h"
#include "../pins/pins.h"
#include "../button/button.h"
#include "ultrasonic.h"

void startUltrasonic(uint8_t echo, uint8_t trigger){
    setOut(trigger);
    setIn(echo);
    setLow(trigger);
    setLow(echo);

    // Configuração padrão do CT1 (16bits).
    // Quando o prescaler do CT1 for ativado ele começa a contar
    addBit(TCCR1B, CS01); //Prescaler = 8
}

uint16_t getSonarDistance(uint8_t echo, uint8_t trigger){
    uint16_t cont = 0;

    setHigh(trigger);
    delayUs((uint8_t) 10);
    setLow(trigger);

    while(testBit(echo));
    TCNT1 = 0;

    while(!testBit(echo));
    cont = TCNT1;

    return (uint16_t)(cont/116);
}

