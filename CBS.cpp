#include <stdio.h>
#include <string.h>

#define BLOCK_SIZE 8  


void xor_blocks(unsigned char *block1, unsigned char *block2, unsigned char *output, int size) {
    for (int i = 0; i < size; i++) {
        output[i] = block1[i] ^ block2[i];
    }
}


void des_encrypt(unsigned char *plaintext, unsigned char *key, unsigned char *ciphertext) {
  
    for (int i = 0; i < BLOCK_SIZE; i++) {
        ciphertext[i] = plaintext[i] ^ key[i];
    }
}
void triple_des_cbc_encrypt(unsigned char *plaintext, unsigned char *key1, unsigned char *key2, unsigned char *key3,
                            unsigned char *iv, unsigned char *ciphertext, int plaintext_len) {
    unsigned char block[BLOCK_SIZE], temp[BLOCK_SIZE];
    unsigned char prev_ciphertext[BLOCK_SIZE];

    memcpy(prev_ciphertext, iv, BLOCK_SIZE); 

    for (int i = 0; i < plaintext_len; i += BLOCK_SIZE) {
   
        xor_blocks(plaintext + i, prev_ciphertext, block, BLOCK_SIZE);

      
        des_encrypt(block, key1, temp);       
        des_encrypt(temp, key2, block);      
        des_encrypt(block, key3, ciphertext + i);  

    
        memcpy(prev_ciphertext, ciphertext + i, BLOCK_SIZE);
    }
}

int main() {
    unsigned char plaintext[] = "This is a secret message.";  
    unsigned char key1[BLOCK_SIZE] = {0x12, 0x34, 0x56, 0x78, 0x90, 0xAB, 0xCD, 0xEF};  
    unsigned char key2[BLOCK_SIZE] = {0x98, 0x76, 0x54, 0x32, 0x10, 0xFE, 0xDC, 0xBA};  
    unsigned char key3[BLOCK_SIZE] = {0x22, 0x44, 0x66, 0x88, 0xAA, 0xCC, 0xEE, 0xFF};  
    unsigned char iv[BLOCK_SIZE]   = {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};  
    
    int plaintext_len = strlen((char *)plaintext);
    int padded_len = (plaintext_len % BLOCK_SIZE == 0) ? plaintext_len : (plaintext_len + (BLOCK_SIZE - (plaintext_len % BLOCK_SIZE)));
    unsigned char ciphertext[padded_len];
    unsigned char padded_plaintext[padded_len];
    memcpy(padded_plaintext, plaintext, plaintext_len);
    for (int i = plaintext_len; i < padded_len; i++) {
        padded_plaintext[i] = 0; 
    }
    triple_des_cbc_encrypt(padded_plaintext, key1, key2, key3, iv, ciphertext, padded_len);
    printf("Ciphertext:\n");
    for (int i = 0; i < padded_len; i++) {
        printf("%02x", ciphertext[i]);
    }
    printf("\n");

    return 0;
}

