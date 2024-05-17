/**
 * Homework Problem 2.62
 * ---------------------
 * Write a function int_shifts_are_arithmetic() that yields 1 when run
 * on a machine that uses arithmetic right shifts for data type int and
 * yields 0 otherwise. Your code should work on a machine with any word
 * size. Test your code on several machines.
*/

#include <stdio.h>

int int_shifts_arithmetic() {
    int x = ~0;
    x >>= 1;
    return x == ~0;
}

int main() {
    printf("%d\n", int_shifts_arithmetic());
    return 0;
}