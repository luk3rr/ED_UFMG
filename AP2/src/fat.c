#include "fat.h"

unsigned long long int recursive_fat(int n) {
    if (n == 0)
        return 1;

    else
        return n * recursive_fat(n-1);
}

unsigned long long int interative_fat(int n) {
    unsigned long long int f = 1;
    for (int i = n; i > 0; i--) {
        f = f * n;
        n = n - 1;
    }
    return f;
}
