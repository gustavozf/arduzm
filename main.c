#include "./led/led.h"
#include "./button/button.h"
#include "./7seg/7seg.h"

int main(){
    //uint8_t botao = 10, led = 8;
    uint8_t segm[] = {3,4,6, 8,10,11, 12, 13}, i;

    //createLed(led);
    //createButton(botao);

    init7segDis(segm);

    while(1){
        /*if(check_press(botao)){
            switchStateLed(led);

            waitButtonRelease(botao);
            switchStateLed(led);
        }*/
        
        for(i=0; i < 16; i++){
            display7seg(i, segm);
            _delay_ms(400);
        }
    }
}
