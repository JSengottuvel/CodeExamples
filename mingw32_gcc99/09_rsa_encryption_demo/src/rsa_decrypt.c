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

/*rsa_decrypt.c*/
#include <stdio.h>
#include <string.h>
#include "rsa_helper.h"

extern unsigned char encrypted[256];

int main_decrypt() {
    const char *private_key_file = ".\\data\\private_key.pem";

    unsigned char decrypted[256];
    int decrypted_len;

    RSA *rsa = load_private_key(private_key_file);
    if (!rsa) {
        fprintf(stderr, "Failed to load the private key.\n");
        return 1;
    }
    printf("Loading private key SUCCESS\n");
    decrypted_len = rsa_private_decrypt(rsa, encrypted, sizeof(encrypted), decrypted);

    if (decrypted_len == -1) {
        fprintf(stderr, "Decryption failed.\n");
    } else {
        decrypted[decrypted_len] = '\0'; //NULL termination of string message
        printf("Decrypted message: %s\n", (const char *)decrypted);
    }

    RSA_free(rsa);
    return 0;
}
