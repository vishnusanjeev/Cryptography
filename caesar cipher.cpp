#include <stdio.h>

void caesarCipher(char* text, int shift) {
    char ch;
    for (int i = 0; text[i] != '\0'; ++i) {
        ch = text[i];
        
        if (ch >= 'a' && ch <= 'z') {
            ch = (ch - 'a' + shift) % 26 + 'a';
        } else if (ch >= 'A' && ch <= 'Z') {
            ch = (ch - 'A' + shift) % 26 + 'A';
        }
        
        text[i] = ch;
    }
}

int main() {
    char text[100];
    int shift;

    printf("Enter a string: ");
    gets(text);

    printf("Enter shift amount: ");
    scanf("%d", &shift);

    caesarCipher(text, shift);

    printf("Encrypted text: %s\n", text);

    return 0;
}

