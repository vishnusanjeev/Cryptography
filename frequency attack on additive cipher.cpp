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


void decrypt_additive(char *ciphertext, char *plaintext, int key) {
    for (int i = 0; ciphertext[i] != '\0'; i++) {
        if (isalpha(ciphertext[i])) {
            char base = isupper(ciphertext[i]) ? 'A' : 'a';
            plaintext[i] = ((ciphertext[i] - base - key + ALPHABET_SIZE) % ALPHABET_SIZE) + base;
        } else {
            plaintext[i] = ciphertext[i]; 
        }
    }
    plaintext[strlen(ciphertext)] = '\0'; 
}


double chi_squared(double *cipher_freq, double *expected_freq) {
    double chi_sq = 0.0;
    for (int i = 0; i < ALPHABET_SIZE; i++) {
        if (expected_freq[i] != 0) {
            chi_sq += ((cipher_freq[i] - expected_freq[i]) * (cipher_freq[i] - expected_freq[i])) / expected_freq[i];
        }
    }
    return chi_sq;
}

int main() {
    char ciphertext[MAX_TEXT_LENGTH];
    char plaintext[MAX_TEXT_LENGTH];
    double cipher_freq[ALPHABET_SIZE];
    double chi_scores[ALPHABET_SIZE];

    printf("Enter the ciphertext: ");
    fgets(ciphertext, MAX_TEXT_LENGTH, stdin);
    ciphertext[strcspn(ciphertext, "\n")] = 0; 

    
    calculate_frequency(ciphertext, cipher_freq);


    for (int key = 0; key < ALPHABET_SIZE; key++) {
        decrypt_additive(ciphertext, plaintext, key);
        calculate_frequency(plaintext, cipher_freq);
        chi_scores[key] = chi_squared(cipher_freq, english_freq);
    }

  
    int n;
    printf("Enter the number of top plaintexts to display: ");
    scanf("%d", &n);

    printf("\nTop %d possible plaintexts:\n", n);
    for (int i = 0; i < n; i++) {
        decrypt_additive(ciphertext, plaintext, i);
        printf("Key %d: %s\n", i, plaintext);
    }

    return 0;
}
