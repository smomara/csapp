/**
 * Homework Problem 2.69
 * ---------------------
 * Write code for a function that does rotating left shift. Assume 0 <= n < w.
 * Examples when x = 012345678 and w = 32:
 *      n = 4 -> 0x23456781
 *      n = 20 -> 0x67812345
*/

#include <stdio.h>

unsigned rotate_left(unsigned x, int n) {
    int w = sizeof(int) << 3;
    // mask to extract the bits that will wrap around
    unsigned mask = ~0 << (w - n);
    // shift the bits that will wrap around to the rgiht
    unsigned wrapped = (x & mask) >> (w - n);
    // shift the remaining bits to the left
    unsigned shifted = (x & ~mask) << n;
    // combine the wrapped and shifted bits
    return wrapped | shifted;
}

int main() {
    int n;
    unsigned x = 0x012345678;
    
    printf("x = 0x%x\n", x);

    n = 4;
    printf("n = %d -> 0x%x\n", n, rotate_left(x, n));

    n = 20;
    printf("n = %d -> 0x%x\n", n, rotate_left(x, n));
}