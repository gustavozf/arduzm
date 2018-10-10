#include "./button.h"
#include "../else/util2.h"

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