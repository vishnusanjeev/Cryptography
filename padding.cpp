#include <stdio.h>
#include <string.h>

#define BLOCK_SIZE 8

void pad_block(char *block, int length) {
    if (length == BLOCK_SIZE) {
        return;  
    }

    block[length] = 0x80; 
    for (int i = length + 1; i < BLOCK_SIZE; i++) {
        block[i] = 0x00;  
    }
}

int main() {
    char plaintext[BLOCK_SIZE] = "Hello";
    printf("Original text: %s\n", plaintext);

    pad_block(plaintext, strlen(plaintext));
    printf("Padded block: ");
    for (int i = 0; i < BLOCK_SIZE; i++) {
        printf("%02x ", plaintext[i]);
    }
    printf("\n");

    return 0;
}
