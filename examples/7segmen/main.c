#include "../../7seg/7seg.h"
#include "../../button/button.h"
#include "../../delay/delay2.h"
#include "../../led/led.h"
#include "../../uart/uart.h"
#include "../../ultrasonic/ultrasonic.h"
#include "../../waves/waves.h"
#include <stdio.h>

int main(){
    uint8_t segm[] = {4, 5, 6, 7, 8, 9, 10, 11};
    uint8_t botao = 12, state = 0, i = 0;

    init7segDis(segm);
    createButton(botao);
    uartInit();
    display7seg(0, segm);

    while(1){
        if(state = switchMode(botao, state)){
            i = (uint8_t) (i+1)%16;
            printf("%d\n", i);
            display7seg(i, segm);
            state = 0;
            delayMs((uint8_t) 200);
        }
    }   
}
