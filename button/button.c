#include "./button.h"
#include "../else/util2.h"
#include "../pins/pins.h"
#include "../delay/delay2.h"

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

uint8_t switchMode(uint8_t buttonPin, uint8_t state){
    uint8_t aux = 0;

    // se tiver sido pressionado
    if(getButtonClick(buttonPin)){
        // inverte o estado
        if (state == ((uint8_t) 0)){
            aux = (uint8_t) 1;
        }
        delayMs((uint8_t) 20);
        // retorna
        return aux;
    }
    // senao, retorna o estado como esta
    return state;
}

uint8_t holdMode(uint8_t buttonPin, uint8_t state){
    uint8_t aux = 0;

    if(getButtonClick(buttonPin)){
        if (state == ((uint8_t) 0)){
            aux = (uint8_t) 1;
        }

        waitButtonRelease(buttonPin);
        delayMs((uint8_t) 20);

        return aux;
    }

    return state;
}