#include <stdio.h>
#include <string.h>

void keyGeneration(unsigned char *key, unsigned char roundKeys[16][48]) {
    
    
    for (int i = 0; i < 16; i++) {
        for (int j = 0; j < 48; j++) {
            roundKeys[i][j] = key[j % 8]; 
        }
    }
}

void feistelFunction(unsigned char *right, unsigned char *subKey, unsigned char *output) {
    
    for (int i = 0; i < 32; i++) {
        output[i] = right[i] ^ subKey[i % 8];
    }
}

void desDecrypt(unsigned char *ciphertext, unsigned char *key, unsigned char *plaintext) {
    unsigned char roundKeys[16][48];
    keyGeneration(key, roundKeys);
    
    unsigned char left[32], right[32], temp[32];
    
   
    memcpy(left, ciphertext, 32);
    memcpy(right, ciphertext + 32, 32);
    
   
    for (int round = 15; round >= 0; round--) {
        unsigned char fOutput[32];
        feistelFunction(right, roundKeys[round], fOutput);
        
       
        memcpy(temp, right, 32);
        for (int i = 0; i < 32; i++) {
            right[i] = left[i] ^ fOutput[i];
            left[i] = temp[i];
        }
    }
  
    memcpy(plaintext, right, 32);
    memcpy(plaintext + 32, left, 32);
}

int main() {
    unsigned char ciphertext[64] = { 0,1,0,1,0,0,1,1,  0,0,1,0,1,1,0,1,  1,0,1,0,0,1,0,1,  0,1,0,1,0,0,1,1, 
        0,1,0,0,1,0,1,1,  1,0,0,1,0,1,1,0,  1,0,0,1,0,1,1,0,  0,0,1,1,0,0,1,0  };
    unsigned char key[8] = {1, 0, 1, 0, 1, 0, 1, 0};
    unsigned char plaintext[64];

   
    desDecrypt(ciphertext, key, plaintext);

    printf("Decrypted plaintext: ");
    for (int i = 0; i < 64; i++) {
        printf("%d", plaintext[i]);
    }
    printf("\n");

    return 0;
}

