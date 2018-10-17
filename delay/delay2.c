#include "./delay2.h"

void delayMs(uint16_t i){
   uint16_t j;

   for(j=0; j<i; j++){delayOneMs();}
}

void delayUs(uint16_t i){
    uint16_t j;

   for(j=0; j<i;j++){delayOneUs();}
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
