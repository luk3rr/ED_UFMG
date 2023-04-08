#include "fib.h"

unsigned long long int recursive_fib(int n) {
    if (n < 3)
        return 1;

    else
        return recursive_fib(n - 1) + recursive_fib(n - 2);
}

unsigned long long int interative_fib(int n) {
    int fb1 = 1, fb2 = 1;
	int fb;

    if (n < 3) return 1;

    for (int i = 3; i <= n; i++) { 
        fb = fb2 + fb1;
        fb2 = fb1;
        fb1 = fb;  
    } 
   return fb;
}
