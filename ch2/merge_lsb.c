/**
 * Homework Problem 2.59
 * ---------------------
 * Write a C expression that will yield a word consisting
 * of the least significant byte of x and the remaining bytes
 * of y. For operands x = 0x89ABCDEF and y = 0x76543210, this
 * would give 0x765432EF
*/

#include <stdio.h>
#include <stdint.h>

uint32_t merge_lsb(uint32_t x, uint32_t y) {
    uint32_t x_masked = x & 0xFF;
    uint32_t y_masked = y & (~0xFF);
    return x_masked | y_masked;
}

int main() {
    uint32_t x = 0x89ABCDEF;
    uint32_t y = 0x76543210;

    printf("0x%x\n", merge_lsb(x, y));  // expect 0x765432ef

    return 0;
}