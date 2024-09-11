#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_LEN 1000


const char common_letters[] = "ETAOINSHRDLCUMWFGYPBVKJXQZ";

void count_frequencies(const char *text, int *freq) {
    memset(freq, 0, 26 * sizeof(int));
    for (int i = 0; text[i] != '\0'; i++) {
        if (isalpha(text[i])) {
            freq[toupper(text[i]) - 'A']++;
        }
    }
}


void generate_plaintexts(const char *ciphertext, const int *freq) {
    
    printf("Top possible plaintexts (based on frequency analysis):\n");
    for (int k = 0; k < 10; k++) { 
        for (int i = 0; ciphertext[i] != '\0'; i++) {
            if (isalpha(ciphertext[i])) {
                char decrypted_char = (ciphertext[i] - 'A' + k) % 26 + 'A'; 
                printf("%c", decrypted_char);
            } else {
                printf("%c", ciphertext[i]);
            }
        }
        printf("\n");
    }
}

int main() {
    char ciphertext[MAX_LEN] = "GSRH RH Z HVXIVG NVHHZTV";
    int freq[26] = {0};

    
    count_frequencies(ciphertext, freq);

 
    generate_plaintexts(ciphertext, freq);

    return 0;
}
