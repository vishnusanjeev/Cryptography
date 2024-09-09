#include <stdio.h>
#include <string.h>

#define BLOCK_SIZE 8


void encrypt_block(unsigned char *plaintext, unsigned char *key, unsigned char *ciphertext) {
    for (int i = 0; i < BLOCK_SIZE; i++) {
        ciphertext[i] = plaintext[i] ^ key[i]; 
    }
}
void pad_message(unsigned char *plaintext, int len, unsigned char *padded, int padded_len) {
    memcpy(padded, plaintext, len);
    padded[len] = 0x80;  
    for (int i = len + 1; i < padded_len; i++) {
        padded[i] = 0x00;  
    }
}


void ecb_encrypt(unsigned char *plaintext, unsigned char *key, unsigned char *ciphertext, int len) {
    unsigned char block[BLOCK_SIZE];
    for (int i = 0; i < len; i += BLOCK_SIZE) {
        memcpy(block, plaintext + i, BLOCK_SIZE);
        encrypt_block(block, key, ciphertext + i);
    }
}


void cbc_encrypt(unsigned char *plaintext, unsigned char *key, unsigned char *ciphertext, int len, unsigned char *iv) {
    unsigned char block[BLOCK_SIZE], temp[BLOCK_SIZE];
    memcpy(temp, iv, BLOCK_SIZE);  
    for (int i = 0; i < len; i += BLOCK_SIZE) {
        memcpy(block, plaintext + i, BLOCK_SIZE);
        for (int j = 0; j < BLOCK_SIZE; j++) {
            block[j] ^= temp[j]; 
        }
        encrypt_block(block, key, ciphertext + i);
        memcpy(temp, ciphertext + i, BLOCK_SIZE); 
    }
}


void cfb_encrypt(unsigned char *plaintext, unsigned char *key, unsigned char *ciphertext, int len, unsigned char *iv) {
    unsigned char temp[BLOCK_SIZE];
    memcpy(temp, iv, BLOCK_SIZE);  

    for (int i = 0; i < len; i += BLOCK_SIZE) {
        unsigned char encrypted_block[BLOCK_SIZE];
        encrypt_block(temp, key, encrypted_block);  

        for (int j = 0; j < BLOCK_SIZE; j++) {
            ciphertext[i + j] = plaintext[i + j] ^ encrypted_block[j]; 
        }

        memcpy(temp, ciphertext + i, BLOCK_SIZE);  
    }
}
int main() {
    unsigned char plaintext[] = "This is a test message for CBC, ECB, and CFB modes.";
    unsigned char key[BLOCK_SIZE] = {0x12, 0x34, 0x56, 0x78, 0x90, 0xAB, 0xCD, 0xEF};  // Key for encryption
    unsigned char iv[BLOCK_SIZE] = {0xFF, 0xEE, 0xDD, 0xCC, 0xBB, 0xAA, 0x99, 0x88};  // Initialization Vector (IV)
    int len = strlen((char *)plaintext);
    int padded_len = ((len / BLOCK_SIZE) + 1) * BLOCK_SIZE;  // Calculate padded length to multiple of BLOCK_SIZE
    unsigned char padded_plaintext[padded_len];
    unsigned char ciphertext_ecb[padded_len];
    unsigned char ciphertext_cbc[padded_len];
    unsigned char ciphertext_cfb[padded_len];
    pad_message(plaintext, len, padded_plaintext, padded_len);
    printf("ECB Mode Encryption:\n");
    ecb_encrypt(padded_plaintext, key, ciphertext_ecb, padded_len);
    for (int i = 0; i < padded_len; i++) {
        printf("%02x", ciphertext_ecb[i]);
    }
    printf("\n\n");
    printf("CBC Mode Encryption:\n");
    cbc_encrypt(padded_plaintext, key, ciphertext_cbc, padded_len, iv);
    for (int i = 0; i < padded_len; i++) {
        printf("%02x", ciphertext_cbc[i]);
    }
    printf("\n\n");
    printf("CFB Mode Encryption:\n");
    cfb_encrypt(padded_plaintext, key, ciphertext_cfb, padded_len, iv);
    for (int i = 0; i < padded_len; i++) {
        printf("%02x", ciphertext_cfb[i]);
    }
    printf("\n");

    return 0;
}
