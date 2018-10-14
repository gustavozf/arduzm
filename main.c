#include "./led/led.h"
#include "./button/button.h"
#include "./ultrasonic/ultrasonic.h"
#include "./uart/uart.h"
#include <stdio.h>

int main(){
    uint8_t echo = 8, 
            trigger = 9, 
            led = 4, 
            led2= 3, 
            button = 10;
    uint16_t cont;

    uartInit();

    createButton(button);
    createLed(led);
    createLed(led2);
    startUltrasonic(echo, trigger);
    
    while(1){
        if(getButtonClick(button)){
            cont = getSonarDistance(echo, trigger);

            printf("Valor em cm: ");
            printf("%d \n", cont);

            if(cont < 15){
                turnOnLed(led);
                turnOffLed(led2);
            } else {
                turnOnLed(led2);
                turnOffLed(led);
            }
            
            waitButtonRelease(button);
            turnOffLed(led);
            turnOffLed(led2);
        }
        
    }
}
