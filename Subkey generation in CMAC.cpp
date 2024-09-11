#include <stdio.h>
#include <string.h>

#define BLOCK_SIZE 128 


void left_shift(unsigned char *input, unsigned char *output, int size) {
    unsigned char overflow = 0;
    for (int i = size - 1; i >= 0; i--) {
        unsigned char next_overflow = input[i] >> 7;
        output[i] = (input[i] << 1) | overflow;
        overflow = next_overflow;
    }
}
void xor_constant(unsigned char *block, int size) {
    if (size == 128)
        block[0] ^= 0x87; 
    else if (size == 64)
        block[0] ^= 0x1B;  
}

void generate_subkeys(unsigned char *key) {
    unsigned char K1[BLOCK_SIZE / 8], K2[BLOCK_SIZE / 8], L[BLOCK_SIZE / 8];
    
    
    for (int i = 0; i < BLOCK_SIZE / 8; i++) {
        L[i] = i + 1; 
    }

    printf("L (simulated encryption output): ");
    for (int i = 0; i < BLOCK_SIZE / 8; i++)
        printf("%02x", L[i]);
    printf("\n");

  
    left_shift(L, K1, BLOCK_SIZE / 8);  
    if (L[0] & 0x80)  
        xor_constant(K1, BLOCK_SIZE);

   
    left_shift(K1, K2, BLOCK_SIZE / 8);  
    if (K1[0] & 0x80)
        xor_constant(K2, BLOCK_SIZE);

   
    printf("K1: ");
    for (int i = 0; i < BLOCK_SIZE / 8; i++)
        printf("%02x", K1[i]);
    printf("\nK2: ");
    for (int i = 0; i < BLOCK_SIZE / 8; i++)
        printf("%02x", K2[i]);
    printf("\n");
}

int main() {
    unsigned char key[BLOCK_SIZE / 8] = {0};  
    generate_subkeys(key);
    return 0;
}
