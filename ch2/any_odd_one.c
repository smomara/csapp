/**
 * Homework Problem 2.64
 * ---------------------
 * Write code to implement a function that returns 1 when any odd bit of x
 * equals 1; 0 otherwise. Assume w = 32. Your function should follow the
 * bit-level integer coding rules except that you may assume that data
 * int has w = 32 bits.
*/

#include <stdio.h>
#include <stdint.h>

int32_t any_odd_one(uint32_t x) {
    int32_t mask = 0xAAAAAAAA;
    return !!(x & mask);
}

int main() {
    uint32_t t1 = 0xAAAAAAAA;   // All odd bits are 1
    uint32_t t2 = 0x55555555;   // All odd bits are 0
    uint32_t t3 = 0x00000000;   // No bits are 1
    uint32_t t4 = 0x00000002;   // Second bit (an odd bit) is 1
    uint32_t t5 = 0x00000001;   // First bit (an even bit) is 1

    printf("Test 1: %d\n", any_odd_one(t1)); // Expected output: 1
    printf("Test 2: %d\n", any_odd_one(t2)); // Expected output: 0
    printf("Test 3: %d\n", any_odd_one(t3)); // Expected output: 0
    printf("Test 4: %d\n", any_odd_one(t4)); // Expected output: 1
    printf("Test 5: %d\n", any_odd_one(t5)); // Expected output: 0

    return 0;
}