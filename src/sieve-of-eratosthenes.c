////////////////////////////// INCLUDED LIBRARIES //////////////////////////////

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <omp.h>

#include "sieve-of-eratosthenes.h"

////////////////////////////////// FUNCTIONS ///////////////////////////////////

char * serial_sieve_of_eratosthenes(int upper_limit) {
    char *composite_numbers; // Array of flags for composite numbers
    int max_check; // Maximum number to check in the sieve
    int next_multiple;
    int i;

    // Allocate composite numbers array
    composite_numbers = calloc(upper_limit+1, sizeof(char));

    // Calculate max check value
    max_check = sqrt(upper_limit) + 1;

    for (i = 2; i < max_check; i++) {
        // Check if number 'i' is marked as nonprime
        if (composite_numbers[i]) {
            continue;
        }

        // Mark all multiples
        next_multiple = 2 * i;
        while (next_multiple <= upper_limit) {
            composite_numbers[next_multiple] = 1;
            next_multiple += i;
        }
    }

    return composite_numbers;
}

char * parallel_sieve_of_eratosthenes(int upper_limit, int thread_count) {
    char *composite_numbers; // Array of flags for composite numbers
    int max_check; // Maximum number to check in the sieve
    int next_multiple;
    int i;

    // Allocate composite numbers array
    composite_numbers = calloc(upper_limit+1, sizeof(char));

    // Calculate max check value
    max_check = sqrt(upper_limit) + 1;

    #pragma omp parallel for num_threads(thread_count) \
        default(none) \
        private(i, next_multiple) \
        shared(max_check, upper_limit, composite_numbers) \
        schedule(static, 1)
    for (i = 2; i < max_check; i++) {
        // Check if number 'i' is marked as nonprime
        if (composite_numbers[i]) {
            continue;
        }

        // Mark all multiples
        next_multiple = 2 * i;
        while (next_multiple <= upper_limit) {
            composite_numbers[next_multiple] = 1;
            next_multiple += i;
        }
    }

    return composite_numbers;
}