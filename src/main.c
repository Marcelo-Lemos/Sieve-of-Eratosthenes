////////////////////////////// INCLUDED LIBRARIES //////////////////////////////

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "sieve-of-eratosthenes.h"

///////////////////////////////////// MAIN /////////////////////////////////////

int main(int argc, char const *argv[]) {
    unsigned long long int upper_limit;
    char output_type[6];
    int num_threads;

    double time_spent;
    clock_t begin, end;

    // Check command line arguments
    if (argc < 4) {
        printf("ERROR: Wrong number of arguments, expected 3 command line arguments.");
        exit(1);
    } else {
        upper_limit = atoi(argv[1]);
        strcpy(output_type, argv[2]);
        num_threads = atoi(argv[3]);
    }

    // Start timer
    begin = clock();

    if (num_threads <= 1) {
        serial_sieve_of_eratosthenes(upper_limit, output_type);
    } else {
        /* parallel code */
    }

    // End timer
    end = clock();
    time_spent = (double)(end - begin) / CLOCKS_PER_SEC;

    // Print time spent depending on output type
    if (!strcmp(output_type, "time") || !strcmp(output_type, "all")) {
        printf("%lf\n", time_spent);
    }

    return 0;
}
