/**
 * Practice Problem 2.13
 * ---------------------
 * Rather than instructions for Boolean operations, the Digital Equipment VAX
 * had instructions for bis (bit set) and bic (bit clear). Both instructions
 * take a data work x and a data mask m. With bis, the modification involves
 * setting z to 1 at each bit position where m is 1. With bic, the modification
 * involves setting z to 0 at each bit position where m is 1.
*/

#include <stdio.h>

int bis(int x, int m) {
    // setting z to 1 at each bit position where m is 1
    return x | m;
}

int bic(int x, int m) {
    // setting z to 0 at each bit position where m is 1
    return x & (~m);
}

int bool_or(int x, int y) {
    int result = bis(x, y);
    return result;
}

int bool_xor(int x, int y) {
    int a = bic(x, y);      // x & ~y
    int b = bic(y, x);      // y & ~x
    int result = bis(a, b); // (x & ~y) | (~x & y)
    return result;
}

int main() {
    int a = 5;  // 0101
    int b = 3;  // 0011

    int xor_result = bool_xor(a, b); // 0101 XOR 0011 = 0110 = 6
    int or_result = bool_or(a, b);   // 0101 OR 0011 = 0111 = 7

    printf("bool_xor(%d, %d) = %d\n", a, b, xor_result);    // expect 6
    printf("bool_or(%d, %d) = %d\n", a, b, or_result);      // expect 7

    return 0;
}