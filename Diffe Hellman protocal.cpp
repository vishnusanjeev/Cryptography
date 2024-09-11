#include <stdio.h>
#include <math.h>


long long mod_exp(long long a, long long x, long long q) {
    long long result = 1;
    a = a % q;
    while (x > 0) {
        if (x % 2 == 1)
            result = (result * a) % q;
        a = (a * a) % q;
        x /= 2;
    }
    return result;
}

int main() {
    long long a, q, xA, xB, yA, yB, sharedA, sharedB;

    
    printf("Enter the base (a): ");
    scanf("%lld", &a);
    printf("Enter the prime modulus (q): ");
    scanf("%lld", &q);

    
    printf("Enter Alice's secret number: ");
    scanf("%lld", &xA);
    printf("Enter Bob's secret number: ");
    scanf("%lld", &xB);

    
    yA = mod_exp(a, xA, q);
    yB = mod_exp(a, xB, q);
    
   
    printf("Alice sends to Bob: %lld\n", yA);
    printf("Bob sends to Alice: %lld\n", yB);

  
    sharedA = mod_exp(yB, xA, q);  
    sharedB = mod_exp(yA, xB, q);  

    printf("Shared secret for Alice: %lld\n", sharedA);
    printf("Shared secret for Bob: %lld\n", sharedB);
    
    return 0;
}
