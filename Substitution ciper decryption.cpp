#include <stdio.h>
#include <string.h>

#define MAX_LEN 1000


void decrypt(char *ciphertext, char *substitution) {
    char decrypted[MAX_LEN];
    int i;

    for(i = 0; ciphertext[i] != '\0'; i++) {
        if(ciphertext[i] >= 'A' && ciphertext[i] <= 'Z') {
            decrypted[i] = substitution[ciphertext[i] - 'A'];  
        } else {
            decrypted[i] = ciphertext[i];  
        }
    }
    decrypted[i] = '\0';  
    printf("Decrypted text: %s\n", decrypted);
}

int main() {
    char ciphertext[MAX_LEN];

   
    printf("Enter the ciphertext (in uppercase letters): ");
    fgets(ciphertext, MAX_LEN, stdin);  

   
    char substitution[26] = {
        'E', 'T', 'A', 'O', 'I', 'N', 'S', 'H', 'R', 'D', 'L', 'C', 'U', 
        'M', 'W', 'F', 'G', 'Y', 'P', 'B', 'V', 'K', 'J', 'X', 'Q', 'Z'
    };

    decrypt(ciphertext, substitution);  

    return 0;
}

