#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define ALPHABET_SIZE 26

void generateCipherAlphabet(char* keyword, char* cipherAlphabet) {
    int used[ALPHABET_SIZE] = {0};  
    int index = 0;
    for (int i = 0; keyword[i] != '\0'; i++) {
        char letter = toupper(keyword[i]);
        if (!used[letter - 'A']) {
            cipherAlphabet[index++] = letter;
            used[letter - 'A'] = 1;
        }
    }
    for (char letter = 'A'; letter <= 'Z'; letter++) {
        if (!used[letter - 'A']) {
            cipherAlphabet[index++] = letter;
        }
    }
}
void encrypt(char* plaintext, char* cipherAlphabet) {
    for (int i = 0; plaintext[i] != '\0'; i++) {
        if (isalpha(plaintext[i])) {
            char letter = toupper(plaintext[i]);
            int pos = letter - 'A';
            printf("%c", cipherAlphabet[pos]);
        } else {
            printf("%c", plaintext[i]);  
        }
    }
    printf("\n");
}

int main() {
    char keyword[] = "CIPHER";  
    char cipherAlphabet[ALPHABET_SIZE + 1];  
    char plaintext[100];

    
    generateCipherAlphabet(keyword, cipherAlphabet);
    printf("Generated Cipher Alphabet:\n");
    for (int i = 0; i < ALPHABET_SIZE; i++) {
        printf("%c ", cipherAlphabet[i]);
    }
    printf("\n");
    printf("Enter the plaintext: ");
    fgets(plaintext, sizeof(plaintext), stdin);
    plaintext[strcspn(plaintext, "\n")] = '\0';   
    printf("Encrypted Ciphertext:\n");
    encrypt(plaintext, cipherAlphabet);

    return 0;
}
