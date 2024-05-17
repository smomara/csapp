#include <stdio.h>

typedef unsigned char *byte_pointer;

void show_bytes(byte_pointer start, size_t len) {
    int i;
    for (i = 0; i < len; i++)
        printf(" %.2x", start[i]);
    printf("\n");
}

void show_int(int x) {
    show_bytes((byte_pointer) &x, sizeof(int));
}

void show_float(float x) {
    show_bytes((byte_pointer) &x, sizeof(float));
}

void show_short(short x) {
    show_bytes((byte_pointer) &x, sizeof(short));
}

void show_long(long x) {
    show_bytes((byte_pointer) &x, sizeof(long));
}

void show_double(double x) {
    show_bytes((byte_pointer) &x, sizeof(double));
}

void show_pointer(void *x) {
    show_bytes((byte_pointer) &x, sizeof(void *));
}

void test_show_bytes(int val) {
    int ival = val;             // Integer variable
    float fval = (float) ival;  // Float variable, cast from integer
    int *pval = &ival;           // Pointer to the integer variable ival
    short sval = (short) ival;  // Short variable, cast from integer
    long lval = (long) ival;    // Long variable, cast from integer
    double dval = (double) ival; // Double variable, cast from integer
    
    printf("Byte representation of integer %d:\n", ival);
    show_int(ival);

    printf("Byte representation of float %f:\n", fval);
    show_float(fval);

    printf("Byte representation of pointer to integer %d:\n", ival);
    show_pointer(pval);

    printf("Byte representation of short %d:\n", sval);
    show_short(sval);

    printf("Byte representation of long %ld:\n", lval);
    show_long(lval);

    printf("Byte representation of double %f:\n", dval);
    show_double(dval);
}

int main() {
    test_show_bytes(12345);

    return 0;
}