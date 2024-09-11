#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void encrypt(char *plaintext, int *key, char *ciphertext, int len) {
    for (int i = 0; i < len; i++) {
        ciphertext[i] = ((plaintext[i] - 'A') + key[i]) % 26 + 'A';
    }
}

int main() {
    char plaintext[] = "HELLO";
    int key[] = {3, 19, 5, 8, 14}; 
    char ciphertext[6];  

    encrypt(plaintext, key, ciphertext, 5);
    ciphertext[5] = '\0';

    printf("Ciphertext: %s\n", ciphertext);

    return 0;
}
