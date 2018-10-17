#include "../../7seg/7seg.h"
#include "../../button/button.h"
#include "../../delay/delay2.h"
#include "../../led/led.h"
#include "../../uart/uart.h"
#include "../../ultrasonic/ultrasonic.h"
#include <stdio.h>

int main(){
    uint8_t led = 8;
    
    createLed(led);
    
    while(1){
        blinkLed(led, 2000);
    }   
}
