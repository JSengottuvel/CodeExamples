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

/*rsa_delper.c*/
#include "rsa_helper.h"
#include <openssl/pem.h>

RSA *load_public_key(const char *public_key_file) {
    FILE *file = fopen(public_key_file, "rb");
    if (!file) {
        return NULL;
    }
    
    RSA *rsa = PEM_read_RSA_PUBKEY(file, NULL, NULL, NULL);
    fclose(file);
    return rsa;
}

RSA *load_private_key(const char *private_key_file) {
    FILE *file = fopen(private_key_file, "rb");
    if (!file) {
        return NULL;
    }
    
    RSA *rsa = PEM_read_RSAPrivateKey(file, NULL, NULL, NULL);
    fclose(file);
    return rsa;
}

int rsa_public_encrypt(RSA *rsa, const unsigned char *in, int in_len, unsigned char *out) {
    return RSA_public_encrypt(in_len, in, out, rsa, RSA_PKCS1_PADDING);
}

int rsa_private_decrypt(RSA *rsa, const unsigned char *in, int in_len, unsigned char *out) {
    return RSA_private_decrypt(in_len, in, out, rsa, RSA_PKCS1_PADDING);
}
