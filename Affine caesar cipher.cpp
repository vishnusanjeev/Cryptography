#include <stdio.h>
#include <ctype.h>
#include <string.h> // Include this for strlen function

#define ALPHABET_SIZE 26

// Function to encrypt a plaintext letter using the affine Caesar cipher
char affine_encrypt(char p, int a, int b) {
    // Encrypt character only if it's a letter
    if (isalpha(p)) {
        // Convert to uppercase for consistency
        p = toupper(p);
        // Apply the affine transformation
        return (char)((a * (p - 'A') + b) % ALPHABET_SIZE + 'A');
    }
    return p; // Return non-alphabet characters unchanged
}

// Function to decrypt a ciphertext letter using the affine Caesar cipher
char affine_decrypt(char c, int a, int b) {
    // Decrypt character only if it's a letter
    if (isalpha(c)) {
        // Convert to uppercase for consistency
        c = toupper(c);
        // Calculate modular inverse of a (mod ALPHABET_SIZE)
        int a_inv = 0;
        for (int i = 1; i < ALPHABET_SIZE; i++) {
            if ((a * i) % ALPHABET_SIZE == 1) {
                a_inv = i;
                break;
            }
        }
        // Apply the inverse affine transformation
        return (char)((a_inv * (c - 'A' - b + ALPHABET_SIZE)) % ALPHABET_SIZE + 'A');
    }
    return c; // Return non-alphabet characters unchanged
}

int main() {
    char plaintext[] = "HELLO";
    char ciphertext[100];
    char decryptedtext[100];
    int a = 5; 
    int b = 8; 

 
    for (int i = 0; plaintext[i] != '\0'; i++) {
        ciphertext[i] = affine_encrypt(plaintext[i], a, b);
    }
    ciphertext[strlen(plaintext)] = '\0';

    printf("Encrypted text: %s\n", ciphertext);

 
    for (int i = 0; ciphertext[i] != '\0'; i++) {
        decryptedtext[i] = affine_decrypt(ciphertext[i], a, b);
    }
    decryptedtext[strlen(ciphertext)] = '\0';

    printf("Decrypted text: %s\n", decryptedtext);

    return 0;
}
