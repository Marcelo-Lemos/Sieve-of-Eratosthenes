////////////////////////////// INCLUDED LIBRARIES //////////////////////////////

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/time.h>

////////////////////////////////// FUNCTIONS ///////////////////////////////////

char * sieve_of_eratosthenes(int upper_limit) {
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
        next_multiple = i * i;
        while (next_multiple <= upper_limit) {
            composite_numbers[next_multiple] = 1;
            next_multiple += i;
        }
    }

    return composite_numbers;
}

///////////////////////////////////// MAIN /////////////////////////////////////

int main(int argc, char const *argv[]) {
    long upper_limit;
    char output_type[8];

    double time_elapsed;
    struct timeval begin, end;

    char *composite_numbers;
    int i;

    // Check command line arguments
    if (argc != 3) {
        printf("ERROR: Wrong number of arguments, expected 3 command line arguments.");
        exit(1);
    } else {
        upper_limit = atoi(argv[1]);
        strcpy(output_type, argv[2]);
    }

    // Start timer
    gettimeofday(&begin, NULL);

    composite_numbers = sieve_of_eratosthenes(upper_limit);

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
