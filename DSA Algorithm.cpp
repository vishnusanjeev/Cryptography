#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define P 23  
#define Q 11  
#define G 5   

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
    long long x, k, h = 5, r, s, g_inv, y;

    printf("Enter private key (x): ");
    scanf("%lld", &x);

    y = mod_exp(G, x, P);
    printf("Public key (y): %lld\n", y);

    srand(time(NULL));
    k = rand() % Q;
    
 
    r = mod_exp(G, k, P) % Q;
    

    g_inv = mod_exp(k, Q-2, Q);  
    s = (g_inv * (h + x * r)) % Q;
    
    printf("Signature: (r, s) = (%lld, %lld)\n", r, s);
    return 0;
}
