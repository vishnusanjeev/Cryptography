#include <stdio.h>
#include <string.h>

#define MAX_TEXT_SIZE 1000


char englishFreqOrder[] = "ETAOINSHRDLCUMWFGYPBVKJXQZ";


void calculateFrequencies(char* text, int* frequencies) {
    for (int i = 0; i < strlen(text); i++) {
        char c = text[i];
        if (c >= 'A' && c <= 'Z') {
            frequencies[c - 'A']++;
        }
    }
}


void rankFrequencies(int* frequencies, char* rankedLetters) {
    int maxIndex, temp;
    int frequencyCopy[26];
    memcpy(frequencyCopy, frequencies, 26 * sizeof(int));

    for (int i = 0; i < 26; i++) {
        maxIndex = 0;
        for (int j = 1; j < 26; j++) {
            if (frequencyCopy[j] > frequencyCopy[maxIndex]) {
                maxIndex = j;
            }
        }
        rankedLetters[i] = 'A' + maxIndex;
        frequencyCopy[maxIndex] = -1; 
    }
}


void substituteWithFrequencies(char* text, char* rankedLetters) {
    for (int i = 0; i < strlen(text); i++) {
        char c = text[i];
        if (c >= 'A' && c <= 'Z') {
            int letterIndex = c - 'A';
            printf("%c", englishFreqOrder[rankedLetters[letterIndex] - 'A']);
        } else {
            printf("%c", c); 
        }
    }
    printf("\n");
}

int main() {
    char ciphertext[] = "ZEBRASLXWBTXF";  
    int frequencies[26] = {0};
    char rankedLetters[26];

    
    calculateFrequencies(ciphertext, frequencies);

    
    rankFrequencies(frequencies, rankedLetters);

    
    printf("Ranked letters based on frequency: ");
    for (int i = 0; i < 26; i++) {
        printf("%c ", rankedLetters[i]);
    }
    printf("\n");

  
    printf("Possible plaintext: ");
    substituteWithFrequencies(ciphertext, rankedLetters);

    return 0;
}

