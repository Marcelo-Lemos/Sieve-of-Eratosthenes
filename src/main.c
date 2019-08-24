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

    double time_elapsed;
    struct timeval begin, end;

    char *composite_numbers;
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
        composite_numbers = serial_sieve_of_eratosthenes(upper_limit);
    } else {
        composite_numbers = parallel_sieve_of_eratosthenes(upper_limit, thread_count);
    }

    // End timer
    gettimeofday(&end, NULL);
    time_elapsed = (double) (end.tv_usec - begin.tv_usec) / 1000000 +
                   (double) (end.tv_sec - begin.tv_sec);

    // Print prime numbers depending on output type
    if (!strcmp(output_type, "l") || !strcmp(output_type, "list") ||
        !strcmp(output_type, "a") || !strcmp(output_type, "all")) {
        for (i = 2; i < upper_limit+1; i++) {
            if (!composite_numbers[i]) {
                printf("%d ", i);
            }
        }
        printf("\n");
    }

    // Print time spent depending on output type
    if (!strcmp(output_type, "t") || !strcmp(output_type, "time") ||
        !strcmp(output_type, "a") || !strcmp(output_type, "all")) {
        printf("%lf\n", time_elapsed);
    }

    free(composite_numbers);
    return 0;
}
