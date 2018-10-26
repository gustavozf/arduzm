#include "../../7seg/7seg.h"
#include "../../button/button.h"
#include "../../delay/delay2.h"
#include "../../led/led.h"
#include "../../uart/uart.h"
#include "../../ultrasonic/ultrasonic.h"
#include "../../waves/waves.h"
#include <stdio.h>

int main(){
    uint8_t segm[] = {4, 5, 6, 8, 9, 10, 11, 12};
    uint8_t botao = 13, state = 0, i = 0;

    init7segDis(segm);
    createButton(botao);
    display7seg(i, segm);

    while(1){
        if(state = switchMode(botao, state)){
            i = (i+1)%16;
            display7seg(i, segm);
            state = 0;
            delayMs((uint8_t) 200);
        }
    }   
}
