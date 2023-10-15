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

/*rsa_encrypt.c*/
#include <stdio.h>
#include <string.h>
#include "rsa_helper.h"

unsigned char encrypted[256];

int main_encrypt() {
    const char *public_key_file = ".\\data\\public_key.pem";
    const char *message = "Hello, RSA Encryption! Demo by Jayakumar Sengottuvel!";
    int encrypted_len;

    RSA *rsa = load_public_key(public_key_file);
    if (!rsa) {
        fprintf(stderr, "Failed to load the public key.\n");
        return 1;
    }

    printf("Loading public key SUCCESS\n");
    encrypted_len = rsa_public_encrypt(rsa, (const unsigned char *)message, strlen(message), encrypted);

    if (encrypted_len == -1) {
        fprintf(stderr, "Encryption failed.\n");
    } else {
        printf("Encrypted message: (length=%d)\n", encrypted_len);
        for (int i = 0; i < encrypted_len; i++) {
            printf("0x%02x,", encrypted[i]);
        }
        printf("\n");
    }

    RSA_free(rsa);
    return 0;
}
