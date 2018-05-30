#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <immintrin.h>
#include <stdint.h>
#include <cpuid.h>
#include <limits.h>

//https://codereview.stackexchange.com/questions/147656/checking-if-cpu-supports-rdrand
_Bool supports_rdrand(){
    const unsigned int flag_RDRAND = (1 << 30);

    unsigned int eax, ebx, ecx, edx;
    __get_cpuid(1, &eax, &ebx, &ecx, &edx);

    return ((ecx & flag_RDRAND) == flag_RDRAND);
}


int collatz(unsigned long long x) {
        printf("%llu\n", x);
        if (x == 1)
                return x;
        if (x%2 == 0)
                return collatz(x/2);
        else
                return collatz(3*x+1);
}

int main() {
        unsigned long long number;

	if (supports_rdrand() == 1) {
	        _rdrand64_step(&number);
	} else {
		srand(time(NULL));
		number = rand()%RAND_MAX;
	}

        collatz(number);

        printf("Original number was %llu\n", number);

        return 0;
}
