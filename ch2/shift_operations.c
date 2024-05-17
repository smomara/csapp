/**
 * Homework Problem 2.63
 * ---------------------
 * Fill in code for the following C functions. Function srl performs
 * a logical right shift uisng an arithmetic right shift (given by 
 * value xsra), followed by other operations not including right
 * shifts or division. Function sra performs an arithmetic right shift
 * using a logical right shift (given by value xsrl), followed by
 * other operations not including right shifts or division. You may
 * use the computation 8*sizeof(int) to determine w, the number of
 * bits in data type int. The shift amount k can range from 0 to w-1.
*/

#include <stdio.h>
#include <assert.h>

unsigned srl(unsigned x, int k) {
    // Perform shift arithmetically
    unsigned xsra = (int) x >> k;
    // Get word size
    int w = sizeof(int) << 3;
    // mask is 1s from msb to kth bit from most
    int mask = ~0 << (w - k);
    // 0 if k == 0, 1 if k != 0
    unsigned k_zero = !!k;

    return (xsra & ~mask) | (x & ~(-k_zero));
}


int sra(int x, int k) {
    // Perform shift logically
    int xsrl = (unsigned) x >> k;
    // Get word size
    int w = sizeof(int) << 3;
    // mask is 1s from msb to kth bit from most
    int mask = ~0 << (w - k);
    // Get msb and adjust mask based on whether x is pos or neg
    int msb = 1 << (w - 1);
    mask &= ((x & msb) >> (w - 1)) | ((~(x & msb) + 1) >> (w - 1));
    
    return xsrl | mask;
}

void test_srl() {
    printf("Testing srl...\n");
    assert(srl(0xF1234567, 4) == 0x0F123456);
    assert(srl(0xF1234567, 8) == 0x00F12345);
    assert(srl(0x81234567, 16) == 0x00008123);
    assert(srl(0x01234567, 0) == 0x01234567);
    assert(srl(0xFFFFFFFF, 31) == 0x00000001);
    printf("All srl tests passed!\n");
}

void test_sra() {
    printf("Testing sra...\n");
    assert(sra(0xF1234567, 4) == 0xFF123456);
    assert(sra(0xF1234567, 8) == 0xFFF12345);
    assert(sra(0x81234567, 16) == 0xFFFF8123);
    assert(sra(0x01234567, 0) == 0x01234567);
    assert(sra(0xFFFFFFFF, 31) == 0xFFFFFFFF);
    printf("All sra tests passed!\n");
}

int main() {
    test_srl();
    test_sra();
    printf("All tests passed!\n");
    return 0;
}