#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define SIZE 5


void createMatrix(char key[], char matrix[][SIZE]) {
    int i, j, k = 0;
    int used[26] = {0};
    char alphabet[26] = "ABCDEFGHIKLMNOPQRSTUVWXYZ";

    
    for (i = 0; key[i]; i++) {
        key[i] = toupper(key[i]);
    }
    key[i] = '\0';

    
    for (i = 0; key[i]; i++) {
        if (key[i] == 'J') {
            key[i] = 'I';  
        }
        if (!used[key[i] - 'A']) {
            used[key[i] - 'A'] = 1;
            matrix[k / SIZE][k % SIZE] = key[i];
            k++;
        }
    }

   
    for (i = 0; i < 26; i++) {
        if (!used[i] && (i + 'A') != 'J') {
            matrix[k / SIZE][k % SIZE] = (char)(i + 'A');
            k++;
        }
    }
}


void findPosition(char matrix[][SIZE], char letter, int *row, int *col) {
    *row = -1;
    *col = -1;
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (matrix[i][j] == letter) {
                *row = i;
                *col = j;
                return;
            }
        }
    }
}


void encrypt(char matrix[][SIZE], char a, char b, char *ciphertext) {
    int row1, col1, row2, col2;
    findPosition(matrix, a, &row1, &col1);
    findPosition(matrix, b, &row2, &col2);

    if (row1 == row2) {  
        ciphertext[0] = matrix[row1][(col1 + 1) % SIZE];
        ciphertext[1] = matrix[row2][(col2 + 1) % SIZE];
    }
    else if (col1 == col2) {  
        ciphertext[0] = matrix[(row1 + 1) % SIZE][col1];
        ciphertext[1] = matrix[(row2 + 1) % SIZE][col2];
    }
    else {  
        ciphertext[0] = matrix[row1][col2];
        ciphertext[1] = matrix[row2][col1];
    }
}


void playfairEncrypt(char plaintext[], char matrix[][SIZE], char *ciphertext) {
    int len = strlen(plaintext);
    int j = 0;

  
    for (int i = 0; i < len; i++) {
        if (plaintext[i] == 'J') {
            plaintext[i] = 'I'; 
        }
        if (i + 1 < len && plaintext[i] == plaintext[i + 1]) {
            ciphertext[j++] = plaintext[i];
            ciphertext[j++] = 'X'; 
        } else {
            ciphertext[j++] = plaintext[i];
        }
    }
    if (j % 2 != 0) {
        ciphertext[j++] = 'X';  
    }
    ciphertext[j] = '\0';

    
    j = 0;
    for (int i = 0; i < strlen(ciphertext); i += 2) {
        char enc[2];
        encrypt(matrix, ciphertext[i], ciphertext[i + 1], enc);
        ciphertext[i] = enc[0];
        ciphertext[i + 1] = enc[1];
    }
}

int main() {
    char key[100], plaintext[100], ciphertext[100];
    char matrix[SIZE][SIZE];

   
    printf("Enter the keyword (letters only): ");
    fgets(key, sizeof(key), stdin);
    key[strcspn(key, "\n")] = '\0';  

    
    printf("Enter the plaintext (letters only): ");
    fgets(plaintext, sizeof(plaintext), stdin);
    plaintext[strcspn(plaintext, "\n")] = '\0'; 

   t
    char filteredText[100];
    int j = 0;
    for (int i = 0; i < strlen(plaintext); i++) {
        if (isalpha(plaintext[i])) {
            filteredText[j++] = toupper(plaintext[i]);
        }
    }
    filteredText[j] = '\0';

   
    createMatrix(key, matrix);

   
    playfairEncrypt(filteredText, matrix, ciphertext);

    
    printf("Ciphertext: %s\n", ciphertext);

    return 0;
}

