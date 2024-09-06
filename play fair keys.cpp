#include <stdio.h>

int main() {
   
    long double keys = 1;
    for (int i = 2; i <= 25; i++) {
        keys *= i;
    }
    printf("Approximate number of Playfair keys: %.0Ld\n", keys);
    return 0;
}

