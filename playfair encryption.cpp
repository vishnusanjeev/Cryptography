#include <stdio.h>
#include <string.h>
#include<ctype.h>>
char playfairMatrix[5][5] = {
    {'M', 'F', 'H', 'I', 'K'},
    {'U', 'N', 'O', 'P', 'Q'},
    {'Z', 'V', 'W', 'X', 'Y'},
    {'E', 'L', 'A', 'R', 'G'},
    {'D', 'S', 'T', 'B', 'C'}
};

void findPosition(char letter, int* row, int* col) {
    if (letter == 'J') letter = 'I'; 
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            if (playfairMatrix[i][j] == letter) {
                *row = i;
                *col = j;
                return;
            }
        }
    }
}

void encryptPair(char a, char b) {
    int row1, col1, row2, col2;
    findPosition(a, &row1, &col1);
    findPosition(b, &row2, &col2);

    if (row1 == row2) {
        printf("%c%c", playfairMatrix[row1][(col1 + 1) % 5], playfairMatrix[row2][(col2 + 1) % 5]);
    } else if (col1 == col2) {
        printf("%c%c", playfairMatrix[(row1 + 1) % 5][col1], playfairMatrix[(row2 + 1) % 5][col2]);
    } else {
        printf("%c%c", playfairMatrix[row1][col2], playfairMatrix[row2][col1]);
    }
}

void encryptMessage(char* message) {
    for (int i = 0; i < strlen(message); i += 2) {
        encryptPair(message[i], message[i+1]);
    }
    printf("\n");
}

void preprocessMessage(char* message, char* processedMessage) {
    int j = 0;
    for (int i = 0; i < strlen(message); i++) {
        if (message[i] != ' ') {
            processedMessage[j++] = toupper(message[i]);
            if (message[i] == 'J') processedMessage[j-1] = 'I';
        }
    }
    if (j % 2 != 0) {
        processedMessage[j++] = 'X'; 
    }
    processedMessage[j] = '\0';
}

int main() {
    char message[] = "Must see you over Cadogan West Coming at once";
    char processedMessage[100];
    preprocessMessage(message, processedMessage);
    printf("Encrypted message: ");
    encryptMessage(processedMessage);
    return 0;
}

