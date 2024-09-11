#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_TEXT_LENGTH 1000
#define ALPHABET_SIZE 26


double english_freq[ALPHABET_SIZE] = {
    8.167, 1.492, 2.782, 4.253, 12.702, 2.228, 2.015, 6.094, 6.966, 0.153,
    0.772, 4.025, 2.406, 6.749, 7.507, 1.929, 0.095, 5.987, 6.327, 9.056,
    2.758, 0.978, 2.360, 0.150, 1.974, 0.074
};

void calculate_frequency(char *ciphertext, double *freq) {
    int count[ALPHABET_SIZE] = {0};
    int total_letters = 0;

    for (int i = 0; ciphertext[i] != '\0'; i++) {
        if (isalpha(ciphertext[i])) {
            count[tolower(ciphertext[i]) - 'a']++;
            total_letters++;
        }
    }

    for (int i = 0; i < ALPHABET_SIZE; i++) {
        freq[i] = ((double)count[i] / total_letters) * 100;
    }
}

void decrypt_monoalphabetic(char *ciphertext, char *plaintext, const char *key) {
    for (int i = 0; ciphertext[i] != '\0'; i++) {
        if (isalpha(ciphertext[i])) {
            char base = isupper(ciphertext[i]) ? 'A' : 'a';
            plaintext[i] = key[tolower(ciphertext[i]) - 'a'] + (base - 'a');
        } else {
            plaintext[i] = ciphertext[i]; 
        }
    }
    plaintext[strlen(ciphertext)] = '\0'; 
}

int main() {
    char ciphertext[MAX_TEXT_LENGTH];
    char plaintext[MAX_TEXT_LENGTH];
    double cipher_freq[ALPHABET_SIZE];
    const char *key = "etaoinshrdlcumwfgypbvkjxqz"; 
    printf("Enter the ciphertext: ");
    fgets(ciphertext, MAX_TEXT_LENGTH, stdin);
    ciphertext[strcspn(ciphertext, "\n")] = 0; 


    calculate_frequency(ciphertext, cipher_freq);

 
    decrypt_monoalphabetic(ciphertext, plaintext, key);

    printf("Decrypted message: %s\n", plaintext);

    return 0;
}
