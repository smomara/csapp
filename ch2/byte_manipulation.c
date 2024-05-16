/**
 * Practice Problem 2.12
 * ---------------------
 * Write C expressions, in terms of variable x, for the following values.
 * Your code should work for any word size w >= 8.
 * 
 * A. The least significant byte of x, with all other bits set to 0.
 * B. All but the least significant byte of x complemented, with the least
 *    significant byte left unchanged.
 * C. The least significant byte set to all ones, and all other bytes of x
 *    left unchanged.
 */

#include <stdio.h>

int lsb(int x) {
    return x & 0xFF;
}

int complement_except_lsb(int x) {
    return lsb(x) | (~x & ~0xFF);
}

int ones_lsb(int x) {
    return x | 0xFF;
}

int main() {
    int x = 0x87654321;
    printf("0x%.8x\n", lsb(x));
    printf("0x%.8x\n", complement_except_lsb(x));
    printf("0x%.8x\n", ones_lsb(x));
    return 0;
}