/**
 * Homework Problem 2.65
 * ---------------------
 * Write code to implement a function that returns 1 when x contains an
 * odd number of 1s; 0 otherwise. Assume w = 32.
 * 
 * Your function should follow the bit-level integer coding rules except
 * that you may assume the data type int has w = 32 bits.
 * 
 * Your code should contain a total of at most 12 arithmetic, bitwise,
 * and logical operations.
*/

#include <stdio.h>
#include <stdint.h>

// 11 total operations
int32_t odd_ones(uint32_t x) {
    x ^= x >> 16;
    x ^= x >> 8;
    x ^= x >> 4;
    x ^= x >> 2;
    x ^= x >> 1;
    return x & 1; // lsb
}

int main() {
    uint32_t t1 = 0xFFFFFFFF;   // All bits are 1;
    uint32_t t2 = 0x55555555;   // Every other bit is 1
    uint32_t t3 = 0x00000000;   // No bits are 1
    uint32_t t4 = 0x00000002;   // Second bit is 1
    uint32_t t5 = 0x00000001;   // First bit is 1

    printf("Test 1: %d\n", odd_ones(t1)); // Expected output: 0
    printf("Test 2: %d\n", odd_ones(t2)); // Expected output: 0
    printf("Test 3: %d\n", odd_ones(t3)); // Expected output: 0
    printf("Test 4: %d\n", odd_ones(t4)); // Expected output: 1
    printf("Test 5: %d\n", odd_ones(t5)); // Expected output: 1

    return 0;
}