#include "../../7seg/7seg.h"
#include "../../button/button.h"
#include "../../delay/delay2.h"
#include "../../led/led.h"
#include "../../uart/uart.h"
#include "../../ultrasonic/ultrasonic.h"
#include "../../waves/waves.h"
#include <stdio.h>

int main(){
    uint8_t waver = 6;
    uint16_t freq;

    uartInit();
    startCtcWave(waver);
    
    while(1){
        //printf("\nInsira a nota frequencia: ");
        //scanf("%d", freq);
        ctcWave(200);

    }   
}
