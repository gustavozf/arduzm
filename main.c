#include "./led/led.h"
#include "./button/button.h"

int main(){
    uint8_t botao = 10, led = 8;

    createLed(led);
    createButton(botao);

    while(1){
        getButtonClick(botao);
        switchStateLed(led);
        //_delay_ms(150);
        //waitButtonRelease(botao);
    }
}
