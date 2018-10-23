#include "./button.h"
#include "../else/util2.h"
#include "../pins/pins.h"

uint8_t testBit(uint8_t buttonPin){
	return (!checkPin((*pins[buttonPin].pin), pins[buttonPin].p));
}

void createButton(uint8_t buttonPin){
    setIn(buttonPin);
    setPullUp(buttonPin);
}

uint8_t getButtonClick(uint8_t buttonPin){
    return testBit(buttonPin);
}

void waitButtonRelease(uint8_t buttonPin){
    while(testBit(buttonPin));
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