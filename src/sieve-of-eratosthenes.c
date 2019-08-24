////////////////////////////// INCLUDED LIBRARIES //////////////////////////////

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <omp.h>

#include "sieve-of-eratosthenes.h"

////////////////////////////////// FUNCTIONS ///////////////////////////////////

char * serial_sieve_of_eratosthenes(int upper_limit) {
    char *primes; // Array of flags for prime numbers
    int next_multiple;
    int i;

    // Allocate primes array
    primes = calloc(upper_limit+1, sizeof(char));

    for (i = 2; i < upper_limit+1; i++) {
        // Check if number 'i' is marked as nonprime
        if (primes[i]) {
            continue;
        }

        // Mark all multiples
        next_multiple = 2 * i;
        while (next_multiple <= upper_limit) {
            primes[next_multiple] = 1;
            next_multiple += i;
        }
    }

    return primes;
}

char * parallel_sieve_of_eratosthenes(int upper_limit, int thread_count) {
    char *primes; // Array of flags for prime numbers
    int next_multiple;
    int i;

    // Allocate primes array
    primes = calloc(upper_limit+1, sizeof(char));

    #pragma omp parallel for num_threads(thread_count) \
        default(none) \
        private(i, next_multiple) \
        shared(upper_limit, primes) \
        schedule(static, 1)
    for (i = 2; i < upper_limit; i++) {
        // Check if number 'i' is marked as nonprime
        if (primes[i]) {
            continue;
        }

        // Mark all multiples
        next_multiple = 2 * i;
        while (next_multiple <= upper_limit) {
            primes[next_multiple] = 1;
            next_multiple += i;
        }
    }

    return primes;
}