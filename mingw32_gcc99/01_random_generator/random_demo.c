/*
MIT License

Copyright (c) 2023 Jayakumar Sengottuvel

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in
all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS," WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
THE SOFTWARE.
*/

/*random_demo.c*/
#include <stdio.h>
#include <stdint.h>
#include <openssl/rand.h>
#include <openssl/err.h>

int main() {
    printf("Demo program to generate RANDOM numbers using OpenSSL\n");
    printf("on Windows32 environment with MinGW GCC and C99\n");
    printf("Copyright (c) 2023 Jayakumar Sengottuvel\n");

    // Initialize AES key and IV arrays
    unsigned char key[16];
    unsigned char iv[16];

    // Initialize OpenSSL library
    if (!RAND_poll()) {
        fprintf(stderr, "RAND_poll failed.\n");
        ERR_print_errors_fp(stderr);
        return 1;
    }

    // Generate a random key and IV
    RAND_bytes(key, sizeof(key));
    RAND_bytes(iv, sizeof(iv);

    printf("Random Key (Hexadecimal): ");
    for (int i = 0; i < sizeof(key); i++) {
        // Print each byte in hexadecimal format with leading zeros
        printf("%02x ", key[i]);
    }
    printf("\n");

    printf("Random IV  (Decimal)    : ");
    for (int i = 0; i < sizeof(iv); i++) {
        // Print each byte in decimal format
        printf("%d ", iv[i]);
    }
    printf("\n");

    return 0;
}
