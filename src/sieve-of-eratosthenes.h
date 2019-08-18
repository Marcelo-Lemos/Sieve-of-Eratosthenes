#ifndef _SIEVE_OF_ERATOSTHENES_H_
#define _SIEVE_OF_ERATOSTHENES_H_

////////////////////////////////// FUNCTIONS ///////////////////////////////////

////////////////////////////////////////////////////////////////////////////////
///
/// Description:
///     Serial execution of the Sieve of Eratosthenes.
///
/// Parameters:
///     upper_limit:    Upper limit for the Sieve of Eratosthenes
///
/// Return:
///     An array of flags that signals if a corresponding number is prime.
///
////////////////////////////////////////////////////////////////////////////////

char * serial_sieve_of_eratosthenes(int upper_limit);

////////////////////////////////////////////////////////////////////////////////
///
/// Description:
///     Parallel execution of the Sieve of Eratosthenes.
///
/// Parameters:
///     upper_limit:    Upper limit for the Sieve of Eratosthenes
///     thread_count:   Number of total threads to be used during execution
///
/// Return:
///     An array of flags that signals if a corresponding number is prime.
///
////////////////////////////////////////////////////////////////////////////////


char * parallel_sieve_of_eratosthenes(int upper_limit, int thread_count);

#endif  /* _SIEVE_OF_ERATOSTHENES_H_ */
