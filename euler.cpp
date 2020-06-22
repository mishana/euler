#include <iostream>
#include <vector>


unsigned int gcd(unsigned int u, unsigned int v) {
    unsigned int shift = 0;

    /* GCD(0,v) == v; GCD(u,0) == u, GCD(0,0) == 0 */
    if (u == 0) return v;
    if (v == 0) return u;

    /* Let shift := lg K, where K is the greatest power of 2
        dividing both u and v. */
    while (((u | v) & 1) == 0) {
        shift++;
        u >>= 1;
        v >>= 1;
    }

    while ((u & 1) == 0)
        u >>= 1;

    /* From here on, u is always odd. */
    do {
        /* remove all factors of 2 in v -- they are not common */
        /*   note: v is not zero, so while will terminate */
        while ((v & 1) == 0)
            v >>= 1;

        /* Now u and v are both odd. Swap if necessary so u <= v,
            then set v = v - u (which is even). For bignums, the
             swapping is just pointer movement, and the subtraction
              can be done in-place. */
        if (u > v) {
            unsigned int t = v;
            v = u;
            u = t; // Swap u and v.
        }

        v -= u; // Here v >= u.
    } while (v != 0);

    /* restore common factors of 2 */
    return u << shift;
}


unsigned int phi(unsigned int n) {
    unsigned int result = n; // Initialize result as n

    if (n % 2 == 0) {

        // If yes, then update n and result
        while (n % 2 == 0)
            n /= 2;
        result -= result / 2;
    }
    // Consider all prime factors of n and for every prime
    // factor p, multiply result with (1 - 1/p)
    for (unsigned int p = 3; p * p <= n; p += 2) {
        if (n == 1)
            return result;
        // Check if p is a prime factor.
        if (n % p == 0) {

            // If yes, then update n and result
            while (n % p == 0)
                n /= p;
            result -= result / p;
        }
    }

    // If n has a prime factor greater than sqrt(n)
    // (There can be at-most one such prime factor)
    if (n > 1)
        result -= result / n;

    return result;
}


void phi_1_to_n(unsigned int n) {
    std::vector<unsigned int> phi(n + 1);
    phi[0] = 0;
    phi[1] = 1;

    for (int i = 2; i <= n; i++) {
        if (!phi[i]) {
            phi[i] = i - 1;
            for (int j = i << 1; j <= n; j += i) {
                if (!phi[j]) phi[j] = j;
                phi[j] -= phi[j] / i;
            }
        }
    }

    for (int i = 1; i < n; i++)
        printf("%d ", phi[i]);
    printf("%d", phi[n]);
}


int main(int argc, char *argv[]) {
    unsigned int num = std::stoi(argv[1]);
    phi_1_to_n(num);

    return 0;
}
