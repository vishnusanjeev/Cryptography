#include <stdio.h>

int modInverse(int a, int m) {
    for (int x = 1; x < m; x++) {
        if ((a * x) % m == 1)
            return x;
    }
    return -1;
}

void affineCipher(char* text, int a, int b) {
    int inverse = modInverse(a, 26);
    if (inverse == -1) {
        printf("Invalid value of 'a', no modular inverse exists.\n");
        return;
    }

    for (int i = 0; text[i] != '\0'; ++i) {
        char ch = text[i];

        if (ch >= 'a' && ch <= 'z') {
            ch = (a * (ch - 'a') + b) % 26 + 'a';
        } else if (ch >= 'A' && ch <= 'Z') {
            ch = (a * (ch - 'A') + b) % 26 + 'A';
        }

        text[i] = ch;
    }
}

int main() {
    char text[100];
    int a, b;

    printf("Enter a string: ");
    gets(text);

    printf("Enter values for a and b: ");
    scanf("%d %d", &a, &b);

    affineCipher(text, a, b);

    printf("Encrypted text: %s\n", text);

    return 0;
}

