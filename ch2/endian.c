/**
 * Homework Problem 2.58
 * ---------------------
 * Write a procedure is_little_endian that will return 1 when
 * compiled and run on a little-endian machine and will return 0
 * when run on a big-endian machine. This program should run
 * on any machine, regardless of its word size.
*/

#include <stdio.h>

char is_little_endian() {
    short x = 1;
    return *((unsigned char *)&x);
}

int main() {
    printf("%d\n", is_little_endian());
    return 0;
}