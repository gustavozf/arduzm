#include "./delay2.h"

void delayMs(uint8_t i){
   uint8_t j;

   for(j= (uint8_t ) 0; j<i; j+= (uint8_t) 1){delayOneMs();}
}

void delayUs(uint8_t i){
    uint8_t j;

   for(j=(uint8_t ) 0; j<i;j+= (uint8_t) 1){delayOneUs();}
}


void delayOneMs(){
    asm volatile (
        "    ldi  r18, 21"	"\n"
        "    ldi  r19, 196"	"\n"
        "1:  dec  r19"	"\n"
        "    brne 1b"	"\n"
        "    dec  r18"	"\n"
        "    brne 1b"	"\n"
        "    nop"	"\n"
    );
}

void delayOneUs(){
    asm volatile (
        "    lpm"	"\n"
        "    lpm"	"\n"
        "    rjmp 1f"	"\n"
        "1:"	"\n"
        );
}
