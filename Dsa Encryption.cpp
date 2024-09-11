#include <stdio.h>
#include <string.h>

void simple_encrypt_decrypt(const char *input, const char *key, char *output) {
    int key_len = strlen(key);
    for (int i = 0; i < 8; i++) {
        output[i] = input[i] ^ key[i % key_len];  
    }
    output[8] = '\0';  
}

int main() {
    char plaintext[9] = "ABCDEFGH";  
    char key[9] = "12345678";  
    char ciphertext[9];
    char decrypted[9];

    simple_encrypt_decrypt(plaintext, key, ciphertext);
    printf("Encrypted text: %s\n", ciphertext);

    simple_encrypt_decrypt(ciphertext, key, decrypted);
    printf("Decrypted text: %s\n", decrypted);

    return 0;
}
