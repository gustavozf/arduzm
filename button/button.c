#include "./button.h"
#include "../else/util2.h"
#include "../pins/pins.h"

uint8_t check_press(uint8_t i){
	return (!check_pin((*pins[i].pin), pins[i].p));
}

void createButton(uint8_t i){
    setIn(i);
    setPullUp(i);
}

void getButtonClick(uint8_t i){
    // Enquanto nao estiver pressionado
    while(!check_press(i));
}

void waitButtonRelease(uint8_t i){
    while(check_press(i));
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