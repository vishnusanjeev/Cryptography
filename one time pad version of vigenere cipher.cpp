#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <ctype.h>

void generateKeyStream(int *keyStream, int length) {
    for (int i = 0; i < length; i++) {
        keyStream[i] = rand() % 26;
    }
}


void encryptMessage(char *message, int *keyStream, char *encrypted) {
    for (int i = 0; i < strlen(message); i++) {
        if (isalpha(message[i])) {
            int shift = keyStream[i];
            char base = isupper(message[i]) ? 'A' : 'a';
            encrypted[i] = ((message[i] - base + shift) % 26) + base;
        } else {
            encrypted[i] = message[i]; 
        }
    }
    encrypted[strlen(message)] = '\0';
}

int main() {
    srand(time(NULL));
    char message[] = "meet me at the usual place at ten rather than eight oclock";
    int keyStream[strlen(message)];
    char encrypted[strlen(message) + 1];

    generateKeyStream(keyStream, strlen(message));
    encryptMessage(message, keyStream, encrypted);

    printf("Original message: %s\n", message);
    printf("Encrypted message: %s\n", encrypted);
    return 0;
}

