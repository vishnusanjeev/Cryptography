#include <stdio.h>
#include <string.h>

#define BLOCK_SIZE 8  


void encrypt_block(unsigned char *plaintext, unsigned char *key, unsigned char *ciphertext) {
    for (int i = 0; i < BLOCK_SIZE; i++) {
        ciphertext[i] = plaintext[i] ^ key[i];  
    }
}


void ecb_encrypt(unsigned char *plaintext, unsigned char *key, unsigned char *ciphertext, int len) {
    unsigned char block[BLOCK_SIZE];

    for (int i = 0; i < len; i += BLOCK_SIZE) {
       
        memcpy(block, plaintext + i, BLOCK_SIZE);

        
        encrypt_block(block, key, ciphertext + i);
    }
}

int main() {
    unsigned char plaintext[] = "this is my secret msg";  
    unsigned char key[BLOCK_SIZE] = {0x12, 0x34, 0x56, 0x78, 0x90, 0xAB, 0xCD, 0xEF}; 

    int len = strlen((char *)plaintext);
    int padded_len = (len % BLOCK_SIZE == 0) ? len : len + (BLOCK_SIZE - (len % BLOCK_SIZE)); 

    unsigned char ciphertext[padded_len];

    
    unsigned char padded_plaintext[padded_len];
    memcpy(padded_plaintext, plaintext, len);
    for (int i = len; i < padded_len; i++) {
        padded_plaintext[i] = 0;  
    }

    
    ecb_encrypt(padded_plaintext, key, ciphertext, padded_len);

    
    printf("Ciphertext (ECB mode):\n");
    for (int i = 0; i < padded_len; i++) {
        printf("%02x", ciphertext[i]);
    }
    printf("\n");

    return 0;
}
