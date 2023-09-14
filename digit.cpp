#include <stdio.h>
int gcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}
int mod_inverse(int a, int m) {
    int m0 = m, t, q;
    int x0 = 0, x1 = 1;
    if (m == 1) return 0; 
    while (a > 1) {
        q = a / m;
        t = m;
        m = a % m;
        a = t;
        t = x0;
        x0 = x1 - q * x0;
        x1 = t;
    }   
    if (x1 < 0) x1 += m0;
    return x1;
}
int main() {
    int p = 61; 
    int q = 31;  
    int alpha = 6;  
    int private_key;
    printf("Enter your private key: ");
    scanf("%d", &private_key);
    int public_key = 1;
    int i;
    for (i = 0; i < private_key; i++) {
        public_key = (public_key * alpha) % p;
    }
    printf("Public Key: %d\n", public_key);
    int message;
    printf("Enter the message to be signed: ");
    scanf("%d", &message);
    int k;
    printf("Enter a random value k: ");
    scanf("%d", &k);
    int r = 1;
    for (i = 0; i < k; i++) {
        r = (r * alpha) % p;
    }
    r = r % q;
    int s = (mod_inverse(k, q) * (message + private_key * r)) % q;
    printf("Signature (r, s): (%d, %d)\n", r, s);
    return 0;
}
