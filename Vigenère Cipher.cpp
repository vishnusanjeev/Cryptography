#include <stdio.h>
#include <string.h>

void vigenereCipher(char* text, char* key) {
    int keyLen = strlen(key);
    int keyIndex = 0;

    for (int i = 0; text[i] != '\0'; ++i) {
        char ch = text[i];

        if (ch >= 'a' && ch <= 'z') {
            ch = (ch - 'a' + (key[keyIndex] - 'a')) % 26 + 'a';
            keyIndex = (keyIndex + 1) % keyLen;
        } else if (ch >= 'A' && ch <= 'Z') {
            ch = (ch - 'A' + (key[keyIndex] - 'A')) % 26 + 'A';
            keyIndex = (keyIndex + 1) % keyLen;
        }

        text[i] = ch;
    }
}

int main() {
    char text[100];
    char key[100];

    printf("Enter a string: ");
    gets(text);

    printf("Enter key: ");
    gets(key);

    vigenereCipher(text, key);

    printf("Encrypted text: %s\n", text);

    return 0;
}

