#include "../pins/pins.h"

/*
         a=2
    ############
    #          #
f=7 #          # b=3
    #          #
    ############
    #    g=8   #
e=6 #          # c=4
    #          #      ##
    ############      ## p=9
         d=5

*/

const uint8_t exaNum[] = {
    //gfedcba.    gfedcba.    gfedcba.    gfedcba.
    0b01111110, 0b00001100, 0b10110110, 0b10011110, // 0, 1, 2, 3
    0b11001100, 0b11011010, 0b11111010, 0b00001110, // 4, 5, 6, 7
    0b11111110, 0b11011110, 0b11101110, 0b11111000, // 8, 9, A, B
    0b01110010, 0b10111100, 0b11110010, 0b11100010  // C, D, E, F
};

void init7segDis(uint8_t *segd){
    uint8_t i;

    // Sequencia: 
    // [., a, b, c, d, e, f, g]
    for(i=0; i<8; i++){
        setOut(segd[i]);
        setHigh(segd[i]);
    }
}

void display7seg(uint8_t num, uint8_t *segd){
    uint8_t i;

    for(i=0; i<8; i++){
        // se for necessario acender o segmento
        if(check_pin(exaNum[num], i+1)){
            setLow(segd[i]);
        } else {
            setHigh(segd[i]);
        }
    }

}