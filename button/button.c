#include "./button.h"
#include "../else/util2.h"
#include "../pins/pins.h"

uint8_t testBit(uint8_t i){
	return (!checkPin((*pins[i].pin), pins[i].p));
}

void createButton(uint8_t i){
    setIn(i);
    setPullUp(i);
}

uint8_t getButtonClick(uint8_t i){
    return testBit(i);
}

void waitButtonRelease(uint8_t i){
    while(testBit(i));
}

/*  Nao espera ser solto
    if(check_press(botao)){
        switchStateLed(led);
    }

    waitButtonRelease(botao);
    _delay_ms(20);
*/

/*  Espera ser solto
    if(check_press(botao)){
        switchStateLed(led) 
        waitButtonRelease(botao);
        switchStateLed(led);
    }

    _delay_ms(20);
*/