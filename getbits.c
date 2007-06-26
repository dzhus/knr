#include <stdio.h>

unsigned getbits (unsigned x, int p, int n)
{
    return (x >> (p+1-n)) & ~(~0 << n);
}

/**
 * Returns x with the n bits that begin at position p set to the rightmost n bits of y, leaving the other bits unchanged.
 * Rightmost bit is in 0 position.
 */
unsigned setbits(unsigned x, int p, int n, unsigned y)
{
    return ((x >> (p - n)) & ((~0 << n) | y) | (~(~0 << n) & y)) << (p - n) | (~(~0 << (p - n)) & x);
}

