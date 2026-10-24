/* Copyright 2026 rock3tsprocket

Redistribution and use in source and binary forms, with or without modification, are permitted
provided that the following conditions are met:

1. Redistributions of source code must retain the above copyright notice, this list of conditions and
the following disclaimer.

2. Redistributions in binary form must reproduce the above copyright notice, this list of conditions
and the following disclaimer in the documentation and/or other materials provided with the
distribution.

3. Neither the name of the copyright holder nor the names of its contributors may be used to
endorse or promote products derived from this software without specific prior written permission.

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS “AS IS”
AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR
TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF
THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE. */

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

#define max(x, y) ((x) > (y) ? (x) : (y))

long libcrazy_pow(long x, long n) {
    if (x == 0) return 0;
    if (x == 1 || n == 0) return 1;

    if (n < 0) {
        x = 1 / x;
        n -= n*2;
    }
    long y = 1;
    while (n > 1) {
        if (n & 1) {
            y *= x;
            n--;
        }
        x *= x;
        n /= 2;
    }
    return x*y;
}

long dectotern(long tobeterned) {
    /* Conversion to ternary */
    int remainder;
    long result = 0;
    int i = 0;
    
    while (tobeterned) {
        remainder = tobeterned % 3;
        tobeterned /= 3;
        result += remainder * libcrazy_pow(10, i);
        i++;
    }
    
    return result;

}

long terntodec(long tobedecimaled) {
    long result = 0;
    size_t i = 0;

    while (libcrazy_pow(10, i) < tobedecimaled) {
        result += ((tobedecimaled / libcrazy_pow(10, i)) % 10) * libcrazy_pow(3, i);
        i++;
    }
    return result;
}

long crazy(long tobecrazied1, long tobecrazied2, bool areintstern) {
    if (!areintstern) {
        tobecrazied1 = dectotern(tobecrazied1);
        tobecrazied2 = dectotern(tobecrazied2);
    }
    
    /* Preparing result variables */
    int trit1 = 0;
    int trit2 = 0;
    int tritresult = 0;
    uint64_t result = 0;

    /* Performing the *crazy* operation per the table at
     * https://en.wikipedia.org/wiki/Malbolge#Crazy_operation */
    
    size_t length = max(tobecrazied1, tobecrazied2);

    /* Comply with ANSI C */
    size_t i;

    for (i = 0; libcrazy_pow(10, i) < length*10; i++) {
        trit1 = (tobecrazied1 / libcrazy_pow(10, i)) % 10;
        trit2 = (tobecrazied2 / libcrazy_pow(10, i)) % 10;
        tritresult = 0;

        if      ((trit1 == 1 && trit2 == 0) ||
                 (trit1 == 2 && trit2 == 0) ||
                 (trit1 == 1 && trit2 == 1)) tritresult = 0;

        else if ((trit1 == 0 && trit2 == 0) ||
                 (trit1 == 0 && trit2 == 1) ||
                 (trit1 == 2 && trit2 == 2)) tritresult = 1;

        else if ((trit1 == 2 && trit2 == 1) ||
                 (trit1 == 0 && trit2 == 2) ||
                 (trit1 == 1 && trit2 == 2)) tritresult = 2;

        result += tritresult * libcrazy_pow(10, i);
    }

    return result;
}
