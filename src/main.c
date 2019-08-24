////////////////////////////// INCLUDED LIBRARIES //////////////////////////////

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/time.h>

#include "sieve-of-eratosthenes.h"

///////////////////////////////////// MAIN /////////////////////////////////////

int main(int argc, char const *argv[]) {
    long upper_limit;
    char output_type[8];
    int thread_count;

    long seconds, micros;
    struct timeval begin, end;

    char *primes;
    int i;

    // Check command line arguments
    if (argc != 4) {
        printf("ERROR: Wrong number of arguments, expected 3 command line arguments.");
        exit(1);
    } else {
        upper_limit = atoi(argv[1]);
        strcpy(output_type, argv[2]);
        thread_count = atoi(argv[3]);
    }

    // Start timer
    gettimeofday(&begin, NULL);

    if (thread_count <= 1) {
        primes = serial_sieve_of_eratosthenes(upper_limit);
    } else {
        primes = parallel_sieve_of_eratosthenes(upper_limit, thread_count);
    }

    // End timer
    gettimeofday(&end, NULL);
    seconds = end.tv_sec - begin.tv_sec;
    micros = ((seconds * 1000000) + end.tv_usec) - (begin.tv_usec);

    // Print prime numbers depending on output type
    if (!strcmp(output_type, "list") || !strcmp(output_type, "all")) {
        for (i = 2; i < upper_limit+1; i++) {
            if (!primes[i]) {
                printf("%d ", i);
            }
        }
        printf("\n");
    }

    // Print time spent depending on output type
    if (!strcmp(output_type, "time") || !strcmp(output_type, "all")) {
        printf("%ld,%lds\n", seconds, micros);
    }

    free(primes);
    return 0;
}
