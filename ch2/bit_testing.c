/**
 * Homework Problem 2.61
 * ---------------------
 * Write C expressions that evalute to 1 whe nthe follwoing conditions
 * are true and to 0 when they are false. Assume x is of type int.
 * 
 * A. Any bit of x equals 1.
 * B. Any bit of x equals 0.
 * C. Any bit in the least significant byte of x equals 1.
 * D. Any bit in the most significant byte of x equals 0.
 * 
 * Your code should follow hte bit-level integer coding rules, with the
 * additional restriction that you may not use equality (==) or inequality
 * (!=) tests.
*/

#include <stdio.h>

int any_bit_equals_one(int x) {
    return !!x;
}

int any_bit_equals_zero(int x) {
    return !!(~x);
}

int any_lsb_bit_equals_one(int x) {
    int x_lsb = x & 0xFF;
    return !!x_lsb;
}

int any_lsb_bit_equals_zero(int x) {
    int x_lsb = x & 0xFF;
    return !!(~x_lsb & 0xFF);
}


int main() {
    int x1 = 0;             // All bits are 0
    int x2 = ~0;            // All bits are 1 
    int x3 = 0xFF;          // Only the least significant byte is 1
    int x4 = 0x80000000;    // Only the most significant bit is 1
    int x5 = 0x12345678;    // Mixed bits

    // testing part A
    printf("Part A\n");
    printf("x1: %d\n", any_bit_equals_one(x1)); // Output: 0
    printf("x1: %d\n", any_bit_equals_one(x2)); // Output: 1
    printf("x2: %d\n", any_bit_equals_one(x3)); // Output: 1
    printf("x3: %d\n", any_bit_equals_one(x4)); // Output: 1
    printf("x4: %d\n", any_bit_equals_one(x5)); // Output: 1

    // testing part B
    printf("Part B\n");
    printf("x1: %d\n", any_bit_equals_zero(x1)); // Output: 1
    printf("x1: %d\n", any_bit_equals_zero(x2)); // Output: 0
    printf("x2: %d\n", any_bit_equals_zero(x3)); // Output: 1
    printf("x3: %d\n", any_bit_equals_zero(x4)); // Output: 1
    printf("x4: %d\n", any_bit_equals_zero(x5)); // Output: 1

    // testing part C
    printf("Part C\n");
    printf("x1: %d\n", any_lsb_bit_equals_one(x1)); // Output: 0
    printf("x1: %d\n", any_lsb_bit_equals_one(x2)); // Output: 1
    printf("x2: %d\n", any_lsb_bit_equals_one(x3)); // Output: 1
    printf("x3: %d\n", any_lsb_bit_equals_one(x4)); // Output: 0
    printf("x4: %d\n", any_lsb_bit_equals_one(x5)); // Output: 1

    // testing part D
    printf("Part D\n");
    printf("x1: %d\n", any_lsb_bit_equals_zero(x1)); // Output: 1
    printf("x1: %d\n", any_lsb_bit_equals_zero(x2)); // Output: 0
    printf("x2: %d\n", any_lsb_bit_equals_zero(x3)); // Output: 0
    printf("x3: %d\n", any_lsb_bit_equals_zero(x4)); // Output: 1
    printf("x4: %d\n", any_lsb_bit_equals_zero(x5)); // Output: 1

    return 0;
}