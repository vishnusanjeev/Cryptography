#include <stdio.h>
#include <string.h>
#include <ctype.h>

int key[2][2] = {
    {9, 4},
    {5, 7}
};


int charToNum(char c) {
    return toupper(c) - 'A';
}


char numToChar(int n) {
    return (n % 26) + 'A';
}


void encryptPair(char input[2], char output[2]) {
    int num1 = charToNum(input[0]);
    int num2 = charToNum(input[1]);

    output[0] = numToChar((key[0][0] * num1 + key[0][1] * num2) % 26);
    output[1] = numToChar((key[1][0] * num1 + key[1][1] * num2) % 26);
}

int main() {
    char message[] = "meetmeattheusualplaceattenratherthaneightoclock";
    char encrypted[strlen(message) + 1];
    char pair[2];
    char encryptedPair[2];

    if (strlen(message) % 2 != 0) {
        strcat(message, "X"); 
    }

    printf("Original message: %s\n", message);

  
    for (int i = 0; i < strlen(message); i += 2) {
        pair[0] = message[i];
        pair[1] = message[i + 1];
        encryptPair(pair, encryptedPair);
        encrypted[i] = encryptedPair[0];
        encrypted[i + 1] = encryptedPair[1];
    }
    encrypted[strlen(message)] = '\0';

    printf("Encrypted message: %s\n", encrypted);
    return 0;
}

