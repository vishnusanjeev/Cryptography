#include <stdio.h>

int PC1[56] = {
    57, 49, 41, 33, 25, 17,  9,
     1, 58, 50, 42, 34, 26, 18,
    10,  2, 59, 51, 43, 35, 27,
    19, 11,  3, 60, 52, 44, 36,
    63, 55, 47, 39, 31, 23, 15,
     7, 62, 54, 46, 38, 30, 22,
    14,  6, 61, 53, 45, 37, 29,
    21, 13,  5, 28, 20, 12,  4
};

int PC2[48] = {
    14, 17, 11, 24,  1,  5,  3, 28,
    15,  6, 21, 10, 23, 19, 12,  4,
    26,  8, 16,  7, 27, 20, 13,  2,
    41, 52, 31, 37, 47, 55, 30, 40,
    51, 45, 33, 48, 44, 49, 39, 56,
    34, 53, 46, 42, 50, 36, 29, 32
};


int shifts[16] = {1, 1, 2, 2, 2, 2, 2, 2, 1, 2, 2, 2, 2, 2, 2, 1};


void leftShift(unsigned char *half, int numShifts) {
    unsigned char temp[28];
    
    
    for (int i = 0; i < 28; i++) {
        temp[i] = half[(i + numShifts) % 28];
    }
    
   
    for (int i = 0; i < 28; i++) {
        half[i] = temp[i];
    }
}


void generateSubkeys(unsigned char *key, unsigned char subkeys[16][48]) {
    unsigned char permutedKey[56];  
    unsigned char left[28], right[28]; 
    
   
    for (int i = 0; i < 56; i++) {
        permutedKey[i] = key[PC1[i] - 1];
    }
    
  
    for (int i = 0; i < 28; i++) {
        left[i] = permutedKey[i];
        right[i] = permutedKey[i + 28];
    }
    
   
    for (int round = 0; round < 16; round++) {
        
        leftShift(left, shifts[round]);
        leftShift(right, shifts[round]);
        
        
        unsigned char combined[56];
        for (int i = 0; i < 28; i++) {
            combined[i] = left[i];
            combined[i + 28] = right[i];
        }
        
        
        for (int i = 0; i < 48; i++) {
            subkeys[round][i] = combined[PC2[i] - 1];
        }
    }
}

int main() {
    
    unsigned char key[64] = {
        1,0,1,0,1,0,1,0, 1,0,1,0,1,0,1,0,
        1,0,1,0,1,0,1,0, 1,0,1,0,1,0,1,0,
        1,0,1,0,1,0,1,0, 1,0,1,0,1,0,1,0,
        1,0,1,0,1,0,1,0, 1,0,1,0,1,0,1,0
    };
    
    
    unsigned char subkeys[16][48];

    generateSubkeys(key, subkeys);

    
    for (int round = 0; round < 16; round++) {
        printf("Subkey %2d: ", round + 1);
        for (int i = 0; i < 48; i++) {
            printf("%d", subkeys[round][i]);
        }
        printf("\n");
    }

    return 0;
}

