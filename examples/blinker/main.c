#include "../../7seg/7seg.h"
#include "../../button/button.h"
#include "../../delay/delay2.h"
#include "../../led/led.h"
#include "../../uart/uart.h"
#include "../../ultrasonic/ultrasonic.h"
#include "../../waves/waves.h"
#include <stdio.h>

int main(){
    uint8_t led = 13;
    
    createLed(led);
    
    while(1){
        blinkLed(led, (uint8_t) 2000);
    }   
}
