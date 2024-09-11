#include <stdio.h>

#define BLOCK_SIZE 64


void xor_blocks(char *block1, char *block2, char *result) {
    for (int i = 0; i < BLOCK_SIZE; i++) {
        result[i] = block1[i] ^ block2[i];
    }
}

void CBC_MAC(char *key, char *message, char *mac) {
    
    xor_blocks(key, message, mac);
}

int main() {
    char key[BLOCK_SIZE] = "SecretKey";
    char message[BLOCK_SIZE] = "MessageX";
    char mac[BLOCK_SIZE];

    
    CBC_MAC(key, message, mac);
    printf("MAC of message: %s\n", mac);
    
   
    char xor_message[BLOCK_SIZE];
    xor_blocks(message, mac, xor_message);

    
    printf("Two-block XOR-ed message: %s\n", xor_message);

    return 0;
}
