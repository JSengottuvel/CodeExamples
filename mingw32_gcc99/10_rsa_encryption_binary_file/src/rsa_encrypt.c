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

#include <stdio.h>
#include <openssl/rsa.h>
#include <openssl/pem.h>
#include <openssl/err.h>
#include "rsa_helper.h"

int main() {
    const char *public_key_file = ".\\data\\public_key.pem";
    const char *input_file = ".\\data\\input.dat";
    const char *output_file = ".\\data\\encrypted.dat";

    FILE *input = fopen(input_file, "rb");
    if (!input) {
        perror("Failed to open input file");
        return 1;
    }

    FILE *output = fopen(output_file, "wb");
    if (!output) {
        perror("Failed to open output file");
        fclose(input);
        return 1;
    }
    printf("\n read RSA public key.");
    RSA *rsa = load_public_key(public_key_file);
    if (!rsa) {
        fprintf(stderr, "Failed to load the public key.\n");
        return 1;
    }
    printf("\n RSA public key read SUCCESSFULL");
    unsigned char plaintext[245]; // 2048-bit RSA key with PKCS1.5 padding can encrypt up to 245 bytes
    printf("\n step1.");
    int bytes_read;
    while ((bytes_read = fread(plaintext, 1, sizeof(plaintext), input)) > 0) {
        printf("\n segment...");
        unsigned char encrypted[256]; // Adjust the buffer size accordingly
        int encrypted_len = RSA_public_encrypt(bytes_read, plaintext, encrypted, rsa, RSA_PKCS1_PADDING);
        if (encrypted_len == -1) {
            ERR_print_errors_fp(stderr);
            RSA_free(rsa);
            fclose(input);
            fclose(output);
            printf("\n encryption failed...");
            return 1;
        }
        fwrite(encrypted, 1, encrypted_len, output);
    }

    RSA_free(rsa);
    fclose(input);
    fclose(output);
    return 0;
}
