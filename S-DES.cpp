#include <stdio.h>
#include <string.h>

#define BLOCK_SIZE 8 

void generate_keys(unsigned char key, unsigned char *key1, unsigned char *key2);
unsigned char sdes_encrypt(unsigned char plaintext, unsigned char key1, unsigned char key2);
unsigned char sdes_decrypt(unsigned char ciphertext, unsigned char key1, unsigned char key2);

unsigned char xor_block(unsigned char block, unsigned char iv) {
    return block ^ iv;
}

void generate_keys(unsigned char key, unsigned char *key1, unsigned char *key2) {

    *key1 = (key & 0xF0) >> 4;
    *key2 = key & 0x0F;       
}


unsigned char sdes_encrypt(unsigned char plaintext, unsigned char key1, unsigned char key2) {
   
    unsigned char temp = plaintext ^ key1; 
    unsigned char ciphertext = temp ^ key2; 
    return ciphertext;
}


unsigned char sdes_decrypt(unsigned char ciphertext, unsigned char key1, unsigned char key2) {
    
    unsigned char temp = ciphertext ^ key2;  
    unsigned char plaintext = temp ^ key1;  
    return plaintext;
}


void cbc_encrypt(unsigned char *plaintext, unsigned char *ciphertext, int len, unsigned char iv, unsigned char key1, unsigned char key2) {
    unsigned char temp_iv = iv; 

    for (int i = 0; i < len; i++) {
        unsigned char block = xor_block(plaintext[i], temp_iv); 
        ciphertext[i] = sdes_encrypt(block, key1, key2);       
        temp_iv = ciphertext[i];                                
    }
}

void cbc_decrypt(unsigned char *ciphertext, unsigned char *decrypted_text, int len, unsigned char iv, unsigned char key1, unsigned char key2) {
    unsigned char temp_iv = iv;  

    for (int i = 0; i < len; i++) {
        unsigned char decrypted_block = sdes_decrypt(ciphertext[i], key1, key2);
        decrypted_text[i] = xor_block(decrypted_block, temp_iv);                
        temp_iv = ciphertext[i];                                                
    }
}

int main() {
    
    unsigned char plaintext[] = {0x01, 0x23};
   
    unsigned char key = 0x7D; 
   
    unsigned char iv = 0xAA;   

  
    unsigned char key1, key2;
    generate_keys(key, &key1, &key2);

   
    unsigned char ciphertext[2], decrypted_text[2];

   
    cbc_encrypt(plaintext, ciphertext, 2, iv, key1, key2);

   
    printf("Ciphertext: ");
    for (int i = 0; i < 2; i++) {
        printf("%02X ", ciphertext[i]);
    }
    printf("\n");

    cbc_decrypt(ciphertext, decrypted_text, 2, iv, key1, key2);


    printf("Decrypted text: ");
    for (int i = 0; i < 2; i++) {
        printf("%02X ", decrypted_text[i]);
    }
    printf("\n");

    return 0;
}
