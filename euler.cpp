#include <iostream>
#include <vector>

#define MAX 1500000

unsigned int phi[MAX + 1] = {0};


void phi_1_to_n(int n) {
//    std::vector<unsigned int> phi(n + 1);
    phi[0] = 0;
    phi[1] = 1;

    for (int i = 2; i <= n; i++) {
        if (!phi[i]) {
            phi[i] = i - 1;
            for (int j = i << 1; j <= n; j += i) {
//                if (!phi[j]) phi[j] = j;
                phi[j] = (phi[j] == 0) * j + phi[j];

                phi[j] -= phi[j] / i;
            }
        }
    }

    printf("%d", phi[1]);
    int i = 2;
    // "loop-unroll" the printf calls
    for (; i < n - 63; i += 64)
        printf(" %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d"
               " %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d",
               phi[i], phi[i + 1], phi[i + 2], phi[i + 3], phi[i + 4], phi[i + 5], phi[i + 6], phi[i + 7],
               phi[i + 8], phi[i + 9], phi[i + 10], phi[i + 11], phi[i + 12], phi[i + 13], phi[i + 14], phi[i + 15],
               phi[i + 16], phi[i + 17], phi[i + 18], phi[i + 19], phi[i + 20], phi[i + 21], phi[i + 22], phi[i + 23],
               phi[i + 24], phi[i + 25], phi[i + 26], phi[i + 27], phi[i + 28], phi[i + 29], phi[i + 30], phi[i + 31],
               phi[i + 32], phi[i + 33], phi[i + 34], phi[i + 35], phi[i + 36], phi[i + 37], phi[i + 38], phi[i + 39],
               phi[i + 40], phi[i + 41], phi[i + 42], phi[i + 43], phi[i + 44], phi[i + 45], phi[i + 46], phi[i + 47],
               phi[i + 48], phi[i + 49], phi[i + 50], phi[i + 51], phi[i + 52], phi[i + 53], phi[i + 54], phi[i + 55],
               phi[i + 56], phi[i + 57], phi[i + 58], phi[i + 59], phi[i + 60], phi[i + 61], phi[i + 62], phi[i + 63]);
    for (; i < n - 31; i += 32)
        printf(" %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d",
               phi[i], phi[i + 1], phi[i + 2], phi[i + 3], phi[i + 4], phi[i + 5], phi[i + 6], phi[i + 7],
               phi[i + 8], phi[i + 9], phi[i + 10], phi[i + 11], phi[i + 12], phi[i + 13], phi[i + 14], phi[i + 15],
               phi[i + 16], phi[i + 17], phi[i + 18], phi[i + 19], phi[i + 20], phi[i + 21], phi[i + 22], phi[i + 23],
               phi[i + 24], phi[i + 25], phi[i + 26], phi[i + 27], phi[i + 28], phi[i + 29], phi[i + 30], phi[i + 31]);
    for (; i < n - 15; i += 16)
        printf(" %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d",
               phi[i], phi[i + 1], phi[i + 2], phi[i + 3], phi[i + 4], phi[i + 5], phi[i + 6], phi[i + 7],
               phi[i + 8], phi[i + 9], phi[i + 10], phi[i + 11], phi[i + 12], phi[i + 13], phi[i + 14], phi[i + 15]);
    for (; i < n - 7; i += 8)
        printf(" %d %d %d %d %d %d %d %d",
               phi[i], phi[i + 1], phi[i + 2], phi[i + 3], phi[i + 4], phi[i + 5], phi[i + 6], phi[i + 7]);
    for (; i < n + 1; ++i)
        printf(" %d", phi[i]);
}


int main(int argc, char *argv[]) {
    int num = std::stoi(argv[1]);
    phi_1_to_n(num);

    return 0;
}
