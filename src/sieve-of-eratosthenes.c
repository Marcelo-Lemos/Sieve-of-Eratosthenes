////////////////////////////// INCLUDED LIBRARIES //////////////////////////////

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "sieve-of-eratosthenes.h"

////////////////////////////////// FUNCTIONS ///////////////////////////////////

void serial_sieve_of_eratosthenes(int upper_limit, char *output_type) {
    char *numbers;
    int next_multiple;
    int i;

    // Allocate array that flags each number
    numbers = calloc(upper_limit+1, sizeof(char));

    for (i = 2; i < upper_limit+1; i++)
    {
        // Check if number 'i' is marked as nonprime
        if (numbers[i]) {
            continue;
        }

        // Print number depending on output type
        if (!strcmp(output_type, "list") || !strcmp(output_type, "all")) {
            printf("%d ", i);
        }

        // Mark all multiples
        next_multiple = 2 * i;
        while (next_multiple <= upper_limit)
        {
            numbers[next_multiple] = 1;
            next_multiple += i;
        }
    }

    if (!strcmp(output_type, "list") || !strcmp(output_type, "all")) {
        printf("\n");
    }

    free(numbers);
}