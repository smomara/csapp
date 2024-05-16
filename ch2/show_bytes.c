#include <stdio.h>
#include <string.h>

// Type definition for a pointer to an unsigned char
typedef unsigned char *byte_pointer;

/**
 * Function: show_bytes
 * --------------------
 * Displays the bytes of the given data in hexadecimal format.
 *
 * start: A pointer to the starting byte of the data.
 * len: The number of bytes to display.
 */
void show_bytes(byte_pointer start, size_t len) {
    int i;
    for (i = 0; i < len; i++)
        printf(" %.2x", start[i]);
    printf("\n");
}

/**
 * Function: show_int
 * ------------------
 * Displays the byte representation of an integer.
 *
 * x: An integer value.
 */
void show_int(int x) {
    // Casts the address of the integer x to a byte_pointer and calls show_bytes
    show_bytes((byte_pointer) &x, sizeof(int));
}

/**
 * Function: show_float
 * --------------------
 * Displays the byte representation of a float.
 *
 * x: A float value.
 */
void show_float(float x) {
    // Casts the address of the float x to a byte_pointer and calls show_bytes
    show_bytes((byte_pointer) &x, sizeof(float));
}

/**
 * Function: show_pointer
 * ----------------------
 * Displays the byte representation of a pointer.
 *
 * x: A pointer to any data type.
 */
void show_pointer(void *x) {
    // Casts the address of the pointer x to a byte_pointer and calls show_bytes
    show_bytes((byte_pointer) &x, sizeof(void *));
}

/**
 * Function: test_show_bytes
 * -------------------------
 * Demonstrates the use of show_int, show_float, and show_pointer functions.
 * 
 * val: An integer value to be demonstrated.
*/
void test_show_bytes(int val) {
    int ival = val;             // Integer variable
    float fval = (float) ival;  // Float variable, cast from integer
    int *pval =&ival;           // Pointer to the integer variable ival
    
    // Display the byte representation of the integer ival
    printf("Byte representation of integer %d:\n", ival);
    show_int(ival);

    // Display the byte representation of the float fval
    printf("Byte representation of float %f:\n", fval);
    show_float(fval);

    // Display the byte representation of the pointer pval
    printf("Byte representation of pointer to integer %d:\n", ival);
    show_pointer(pval);
}

int main() {
    //test_show_bytes(12345);

    short sx = -12345;
    unsigned short usx = sx;
    int x = sx;
    unsigned ux = usx;

    printf("sx\t= %d:\t", sx);
    show_bytes((byte_pointer) &sx, sizeof(short));
    printf("usx\t= %u:\t", usx);
    show_bytes((byte_pointer) &usx, sizeof(unsigned short));
    printf("x\t= %d:\t", x);
    show_bytes((byte_pointer) &x, sizeof(int));
    printf("ux = %d:\t", ux);
    show_bytes((byte_pointer) &ux, sizeof(unsigned int));
    printf("\n");
    

    return 0;
}