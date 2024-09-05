#include <stdio.h>
#include <string.h>

#define MAX_LENGTH 500

void frequencyAnalysis(char *ciphertext, int freq[]) {
    for (int i = 0; ciphertext[i] != '\0'; i++) {
        if (ciphertext[i] >= 'A' && ciphertext[i] <= 'Z')
            freq[ciphertext[i] - 'A']++;
        else if (ciphertext[i] >= 'a' && ciphertext[i] <= 'z')
            freq[ciphertext[i] - 'a']++;
    }
}

void decrypt(char *ciphertext, char *substitution) {
    for (int i = 0; ciphertext[i] != '\0'; i++) {
        if (ciphertext[i] >= 'A' && ciphertext[i] <= 'Z')
            printf("%c", substitution[ciphertext[i] - 'A']);
        else if (ciphertext[i] >= 'a' && ciphertext[i] <= 'z')
            printf("%c", substitution[ciphertext[i] - 'a']);
        else
            printf("%c", ciphertext[i]); 
    }
}

int main() {
    char ciphertext[MAX_LENGTH] = "53+305))6:4826)41.)41):806*:48+860))85::]8*::8+83 ...";  
    char substitution[26] = {'T', 'H', 'E', };

    int freq[26] = {0};
    frequencyAnalysis(ciphertext, freq);

   
    for (int i = 0; i < 26; i++) {
        printf("%c: %d\n", 'A' + i, freq[i]);
    }

    printf("\nDecrypted message:\n");
    decrypt(ciphertext, substitution);

    return 0;
}
