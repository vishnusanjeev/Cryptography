// RSA Encryption Program for Alphabetic Characters
#include <stdio.h>
#include <math.h>


long long mod_exp(long long base, long long exp, long long mod) {
    long long result = 1;
    while (exp > 0) {
        if (exp % 2 == 1)
            result = (result * base) % mod;
        base = (base * base) % mod;
        exp /= 2;
    }
    return result;
}

int main() {
    long long n, e;
    char message[100];
    
 
    printf("Enter modulus (n): ");
    scanf("%lld", &n);
    printf("Enter public exponent (e): ");
    scanf("%lld", &e);
    
    printf("Enter the message (A-Z only): ");
    scanf("%s", message);
    

    for (int i = 0; message[i] != '\0'; i++) {
        int m = message[i] - 'A';
        long long encrypted_char = mod_exp(m, e, n);
        printf("Encrypted char %c: %lld\n", message[i], encrypted_char);
    }
    
    return 0;
}
