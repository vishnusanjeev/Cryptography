#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define ALPHABET_SIZE 26

int modInverse(int a, int m) {
    a = a % m;
    for (int x = 1; x < m; x++) {
        if ((a * x) % m == 1) {
            return x;
        }
    }
    return -1;
}

void affineDecrypt(char *ciphertext, int a, int b) {
    int m = ALPHABET_SIZE;
    int a_inv = modInverse(a, m);
    if (a_inv == -1) {
        printf("No modular inverse for a = %d\n", a);
        return;
    }
    
    char decryptedText[1000];
    for (int i = 0; ciphertext[i] != '\0'; i++) {
        char c = ciphertext[i];
        if (isalpha(c)) {
            c = toupper(c);
            int x = c - 'A';
            int decrypted = (a_inv * (x - b + m)) % m;
            decryptedText[i] = decrypted + 'A';
        } else {
            decryptedText[i] = c;
        }
    }
    decryptedText[strlen(ciphertext)] = '\0';
    printf("Decrypted text: %s\n", decryptedText);
}

int main() {
    char ciphertext[] = "HAI HELLO";
    
    int freq1 = 1;
    int freq2 = 20;
    
    int a = (freq2 - freq1 + ALPHABET_SIZE) % ALPHABET_SIZE;
    int b = (freq1 - (a * 0) + ALPHABET_SIZE) % ALPHABET_SIZE;
    
    int a_inv = modInverse(a, ALPHABET_SIZE);
    if (a_inv == -1) {
        printf("No modular inverse for a = %d\n", a);
        return 1;
    }

    affineDecrypt(ciphertext, a, b);

    return 0;
}

