#include <stdio.h>
#include <string.h>


void decryptCaesar(char* ciphertext, int shift) {
    for (int i = 0; i < strlen(ciphertext); i++) {
        if (ciphertext[i] >= 'A' && ciphertext[i] <= 'Z') {
            printf("%c", (ciphertext[i] - 'A' - shift + 26) % 26 + 'A');
        } else {
            printf("%c", ciphertext[i]);
        }
    }
    printf("\n");
}

int main() {
    char ciphertext[] = "ZKZK TJWXQ JXY SL";
    
    printf("Top 10 possible plaintexts using frequency attack:\n");
    for (int i = 1; i <= 10; i++) {
        printf("Shift %d: ", i);
        decryptCaesar(ciphertext, i);
    }
    
    return 0;
}

