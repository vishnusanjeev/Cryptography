#include <stdio.h>
#include <string.h>

void monoalphabeticCipher(char* text, const char* key) {
    char map[256]; 
    for (int i = 0; i < 26; ++i) {
        map['a' + i] = key[i];              
        map['A' + i] = key[i] - 'a' + 'A';  
    }

    for (int i = 0; text[i] != '\0'; ++i) {
        if (text[i] >= 'a' && text[i] <= 'z') {
            text[i] = map[text[i]];
        } else if (text[i] >= 'A' && text[i] <= 'Z') {
            text[i] = map[text[i]];
        }
    }
}

int main() {
    char text[100];
    const char key[27] = "QWERTYUIOPASDFGHJKLZXCVBNM"; // Example key

    printf("Enter a string: ");
    fgets(text, sizeof(text), stdin);

    // Remove the newline character if present
    text[strcspn(text, "\n")] = '\0';

    monoalphabeticCipher(text, key);

    printf("Encrypted text: %s\n", text);

    return 0;
}

