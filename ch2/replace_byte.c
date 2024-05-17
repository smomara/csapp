/**
 * Homework Problems 2.60
 * ----------------------
 * Suppose we number the bytes in a w-bit word from 0 (least significant)
 * to w/8-1 (most significant). Write code for the C function replace_byte, 
 * which will return an unsigned value in which byte i of argument x has been 
 * replaced by byte b.
*/

#include <stdio.h>

unsigned replace_byte(unsigned x, int i, unsigned char b) {
    // Create a mask with the byte at position i set to 0xFF, and the rest set to 0
    // 0xFF is 11111111 in binary, so shifting it left by i*8 positions moves it to the byte we want to replace
    unsigned mask = 0xFF << (i * 8);

    // Clear the byte at position i in the original number x
    // ~mask inverts the mask, turning the 0xFF byte to 0x00 and all other bytes to 0xFF
    // ANDing this with x clears the desired byte while keeping all other bytes unchanged
    unsigned x_masked = x & (~mask);

    // Shift the new byte b to the correct position
    // Cast b to unsigned to ensure the shift operation is performed correctly
    // Shifting left by i*8 positions moves the byte b to the correct position in the word
    unsigned b_masked = ((unsigned) b) << (i * 8);

    // Combine the modified original number with the new byte
    // ORing the two values sets the byte at position i to b, while leaving all other bytes unchanged
    return x_masked | b_masked;
}

int main() {
    unsigned x = 0x12345678;
    int i = 2;
    unsigned char b = 0xAB;
    unsigned result = replace_byte(x, i, b); // 0x12ab5678

    printf("0x%x\n", result);
}