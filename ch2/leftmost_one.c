/**
 * Homework Problem 2.66
 * ---------------------
 * Create a function that generates a mask indicating leftmost 1 in x. Assume w = 32.
 * For example, 0xFF00 -> 0x8000, and 0x6600 -> 0x4000.
 * If x = 0, then return 0.
 * 
 * Your function should follow the bit-level integer coding rules, except that you may
 * assume that data type int has w = 32 bits.
 * Your code should contain a total of at most 15 arithmetic, bitwise, and logical operations.
*/

#include <stdio.h>
#include <stdint.h>

int32_t leftmost_one(uint32_t x) {
    /**
     * This sequence of logical shifts and OR operations propogates
     * the leftmost 1 in x. For example, 0x6040 becomes 0x6FFF
    */
    x |= x >> 1;
    x |= x >> 2;
    x |= x >> 4;
    x |= x >> 8;
    x |= x >> 16;

    /* Gets only the leftmost 1 by XORing with itself shifting right once */
    return x ^ (x >> 1);
}

int main() {
    uint32_t t1 = 0xFF00;
    uint32_t t2 = 0x6600;
    printf("0x%x -> 0x%x\n", t1, leftmost_one(t1)); // expect 0x8000
    printf("0x%x -> 0x%x\n", t2, leftmost_one(t2)); // expect 0x4000

    return 0;
}