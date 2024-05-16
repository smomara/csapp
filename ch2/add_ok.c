#include <stdio.h>
#include <limits.h>

/**
 * Practice Problem 2.27
 * ---------------------
 * Write a function that determines whether unsigned arguments can be
 * added without overflow. The function should return 1 if
 * arguments x and y can be added without causing overflow.
*/

/* Determine whether unsigned int arguments can be added without overflow */
int uadd_ok(unsigned x, unsigned y) {
    unsigned s = x + y;
    return !(s < x);
}

/**
 * Practice Problem 2.30
 * ---------------------
 * Write a function that determines whether two's complement arguments can be
 * added without overflow. The function should return 1 if
 * arguments x and y can be added without causing overflow.
*/

/* Determine whether signed int arguments can be added without overflow*/
int tadd_ok(int x, int y) {
    int s = x + y;
    int neg_over = x < 0 && y < 0 && s >= 0;
    int pos_over = x >= 0 && y >= 0 && s < 0;
    return !neg_over && !pos_over;
}

/**
 * Practice Problem 2.32
 * ---------------------
 * Write a function that determines whether two's complement arguments can be
 * subtracted without overflow. The function should return 1 if
 * arguments x and y can be subtracted without causing overflow.
*/

/* Determine whether signed int argments can be subtracted without overflow */
int tsub_ok(int x, int y) {
    if (y == INT_MIN) {
        return x < 0;
    }
    return tadd_ok(x, -y);
}

/* Main function to test uadd_ok, tadd_ok, and tsub_ok */
int main() {
    unsigned a = ~0; // ones
    unsigned b = 0;  // zeroes
    int c = INT_MAX;
    int d = INT_MIN;

    printf("unsigned: %u + %u = %u\tok? %d\n", a, a, a + a, uadd_ok(a, a));   // expect 0 (false)
    printf("unsigned: %u + %u = %u\tok? %d\n", a, b, a + b, uadd_ok(a, b));   // expect 1 (true)
    
    printf("signed: %d + %d = %d\tok? %d\n", c, c, c + c, tadd_ok(c, c));     // expect 0 (false - positive overflow)
    printf("signed: %d + %d = %d\tok? %d\n", d, d, d + d, tadd_ok(d, d));     // expect 0 (false - negative overflow)
    printf("signed: %d + %d = %d\tok? %d\n", c, d, c + d, tadd_ok(c, d));     // expect 1 (true)
    
    printf("signed: %d - %d = %d\tok? %d\n", d, c, d - c, tsub_ok(d, c));     // expect 1 (true)
    printf("signed: %d - %d = %d\tok? %d\n", c, d, c - d, tsub_ok(c, d));     // expect 0 (false - positive overflow)
    printf("signed: %d - %d = %d\tok? %d\n", c, c, c - c, tsub_ok(c, c));     // expect 1 (true)
    
    return 0;
}
