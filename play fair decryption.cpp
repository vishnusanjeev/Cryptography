#include <stdio.h>
#include <string.h>

#define SIZE 5

char playfairMatrix[SIZE][SIZE] = {
    {'M', 'F', 'H', 'I', 'K'},
    {'U', 'N', 'O', 'P', 'Q'},
    {'Z', 'V', 'W', 'X', 'Y'},
    {'E', 'L', 'A', 'R', 'G'},
    {'D', 'S', 'T', 'B', 'C'}
};


void findPosition(char letter, int* row, int* col) {
    if (letter == 'J') letter = 'I';
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (playfairMatrix[i][j] == letter) {
                *row = i;
                *col = j;
                return;
            }
        }
    }
}


void decryptPair(char a, char b) {
    int row1, col1, row2, col2;
    findPosition(a, &row1, &col1);
    findPosition(b, &row2, &col2);

    if (row1 == row2) {
        printf("%c%c", playfairMatrix[row1][(col1 + SIZE - 1) % SIZE], playfairMatrix[row2][(col2 + SIZE - 1) % SIZE]);
    } else if (col1 == col2) {
        printf("%c%c", playfairMatrix[(row1 + SIZE - 1) % SIZE][col1], playfairMatrix[(row2 + SIZE - 1) % SIZE][col2]);
    } else {
        printf("%c%c", playfairMatrix[row1][col2], playfairMatrix[row2][col1]);
    }
}


void decryptMessage(char* message) {
    for (int i = 0; i < strlen(message); i += 2) {
        decryptPair(message[i], message[i+1]);
    }
    printf("\n");
}

int main() {
    char message[] = "KXJEYUREBEZWEHEWRYTUHEYFS";
    printf("Decrypted message: ");
    decryptMessage(message);
    return 0;
}

