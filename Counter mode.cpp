#include <stdio.h>
#include <string.h>

#define BLOCK_SIZE 8 


unsigned char xor_encrypt(unsigned char plaintext, unsigned char key) {
    return plaintext ^ key;
}

void ctr_mode(unsigned char *input, unsigned char *output, unsigned char key, int len, unsigned char start_counter) {
    for (int i = 0; i < len; i++) {
        unsigned char counter = start_counter + i;
        unsigned char keystream = xor_encrypt(counter, key); 
        output[i] = input[i] ^ keystream; 
    }
}

int main() {
    unsigned char plaintext[] = {0x01, 0x10, 0x20};\
    unsigned char key = 0x7D; 
    unsigned char start_counter = 0x00; 

    unsigned char ciphertext[sizeof(plaintext)];
    unsigned char decrypted_text[sizeof(plaintext)];

    
    ctr_mode(plaintext, ciphertext, key, sizeof(plaintext), start_counter);
    
    printf("Ciphertext: ");
    for (int i = 0; i < sizeof(ciphertext); i++) {
        printf("%02X ", ciphertext[i]);
    }
    printf("\n");

   
    ctr_mode(ciphertext, decrypted_text, key, sizeof(ciphertext), start_counter);
    
    printf("Decrypted text: ");
    for (int i = 0; i < sizeof(decrypted_text); i++) {
        printf("%02X ", decrypted_text[i]);
    }
    printf("\n");

    return 0;
}
