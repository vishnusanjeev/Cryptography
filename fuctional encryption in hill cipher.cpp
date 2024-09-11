#include <stdio.h>
#include <string.h>


void hill_cipher_encrypt(int key[2][2], const char *plaintext, char *ciphertext) {
    for (int i = 0; plaintext[i] != '\0'; i += 2) {
        if (plaintext[i + 1] == '\0') {
            
            ciphertext[i] = ((key[0][0] * (plaintext[i] - 'A')) + (key[0][1] * ('X' - 'A'))) % 26 + 'A';
            ciphertext[i + 1] = ((key[1][0] * (plaintext[i] - 'A')) + (key[1][1] * ('X' - 'A'))) % 26 + 'A';
            ciphertext[i + 2] = '\0';
        } else {
            ciphertext[i] = ((key[0][0] * (plaintext[i] - 'A')) + (key[0][1] * (plaintext[i + 1] - 'A'))) % 26 + 'A';
            ciphertext[i + 1] = ((key[1][0] * (plaintext[i] - 'A')) + (key[1][1] * (plaintext[i + 1] - 'A'))) % 26 + 'A';
        }
    }
    ciphertext[strlen(plaintext)] = '\0'; 
}

int main() {
    char plaintext[] = "HI";
    char ciphertext[100];
    int key[2][2] = {{3, 2}, {5, 7}}; 

    hill_cipher_encrypt(key, plaintext, ciphertext);
    printf("Encrypted text: %s\n", ciphertext);

    return 0;
}
