/**
 * Homework Problems 2.60
 * ----------------------
 * Suppose we number the bytes in a w-bit word from 0 (least significant)
 * to w/8-1 (most significant). Write code for the C function replace_byte, 
 * which will return an unsigned value in which byte i of argument x has been 
 * replaced by byte b.
*/

#include <stdio.h>

unsigned replace_byte(unsigned x, int i, unsigned char b) {
    // create a mask where only the bits we want to replace are 1
    unsigned mask = 0xFF << (i * 8);

    // clear the bits that we are replacing in x
    unsigned x_masked = x & (~mask);

    // create an unsigned where the only non-zero bits are the ones we are using to replace
    unsigned b_masked = ((unsigned) b) << (i * 8);

    // combine
    return x_masked | b_masked;
}

int main() {
    unsigned x = 0x12345678;
    int i = 2;
    unsigned char b = 0xAB;
    unsigned result = replace_byte(x, i, b); // 0x12ab5678

    printf("0x%x\n", result);
}