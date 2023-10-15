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
    const char *private_key_file = ".\\data\\private_key.pem";
    const char *encrypted_file = ".\\data\\encrypted.dat";
    const char *decrypted_file = ".\\data\\decrypted.dat";
    
    FILE *encrypted_input = fopen(encrypted_file, "rb");
    if (!encrypted_input) {
        perror("Failed to open encrypted input file");
        return 1;
    }
    
    FILE *decrypted_output = fopen(decrypted_file, "wb");
    if (!decrypted_output) {
        perror("Failed to open decrypted output file");
        fclose(encrypted_input);
        return 1;
    }
    
    RSA *rsa = load_private_key(private_key_file);
    if (!rsa) {
        fprintf(stderr, "Failed to load the private key.\n");
        return 1;
    }
    
    unsigned char encrypted[256]; // Adjust the buffer size accordingly
    unsigned char decrypted[245];
    
    int bytes_read;
    while ((bytes_read = fread(encrypted, 1, sizeof(encrypted), encrypted_input)) > 0) {
        int decrypted_len = RSA_private_decrypt(bytes_read, encrypted, decrypted, rsa, RSA_PKCS1_PADDING);
        if (decrypted_len == -1) {
            ERR_print_errors_fp(stderr);
            RSA_free(rsa);
            fclose(encrypted_input);
            fclose(decrypted_output);
            return 1;
        }
        fwrite(decrypted, 1, decrypted_len, decrypted_output);
    }
    
    RSA_free(rsa);
    fclose(encrypted_input);
    fclose(decrypted_output);
    return 0;
}
