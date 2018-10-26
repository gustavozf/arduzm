#include "../../7seg/7seg.h"
#include "../../button/button.h"
#include "../../delay/delay2.h"
#include "../../led/led.h"
#include "../../uart/uart.h"
#include "../../ultrasonic/ultrasonic.h"
#include "../../waves/waves.h"
#include <stdio.h>

int main(){
    uint8_t led[] = {6, 7};
    uint8_t botao = 10;
    uint8_t trigger = 11, echo = 12;

    createLed(led[0]);
    createLed(led[1]);
    createButton(botao);
    startUltrasonic(echo, trigger);

    while(1){
        if(getButtonClick(botao)){
            if(getSonarDistance(echo, trigger) > 15){
                turnOnLed(led[0]);
                turnOffLed(led[1]);
            } else {
                turnOnLed(led[1]);
                turnOffLed(led[0]);
            }

            delayMs((uint8_t) 200);
            //waitButtonRelease(botao);
        }
    }   
}
