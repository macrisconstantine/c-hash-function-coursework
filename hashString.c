#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define BASE (256)
#define MULTIPLIER (31)
#define BITS_PER_CHAR (8)       
#define MAX_STRING_SIZE (128)
#define MAX_BITS (BITS_PER_CHAR * MAX_STRING_SIZE)

void hashString(char *s) {
    int i, shift;
    unsigned char c;
    unsigned long x[MAX_BITS];
    unsigned long m = MULTIPLIER;
    unsigned long h;
    unsigned const char *us;
    int n, nTests = 1000;
    clock_t tStart, tEnd;
    double hAvg1, hAvg2, hAvg3;
    
    /* do profiling */
    tStart = clock();
    
    for (n = 0; n < nTests; n++)
    {
        // (DIVISION HASHING METHOD)
        /* cast s to unsigned const char * */
        /* this ensures that elements of s will be treated as having values >= 0 */
        us = (unsigned const char *) s;
    
        h = 0;
        while (*us != '\0') {
            h = (h * BASE + *us) % m;
            us++;
        }
    }
    tEnd = clock();
    /* end profiling */
    
    /* compute average execution time */
    hAvg1 = ((double) (tEnd - tStart)) / CLOCKS_PER_SEC / nTests;
    
    /* print avg execution time in milliseconds */
    printf("\n\n\n_______________________________________________________\n");
    printf("Division hash derived from string --> %lu", h);
    printf("\nAvg. execution time over 1000 trials: %g nanoseconds\n", hAvg1 * 1000000000);
    
    // Same process is repeated for the second and third hash functions
    tStart = clock();
    
    for (n = 0; n < nTests; n++)
    {
        // (MULTIPLICATION HASHING METHOD)
        /* cast s to unsigned const char * */
        /* this ensures that elements of s will be treated as having values >= 0 */
    
        us = (unsigned const char *) s;
       
        h = 0;
        while(*us != '\0') {
            h = h * MULTIPLIER + *us;
            us++;
            } 
    }
    
    tEnd = clock();
    
    hAvg2 = ((double) (tEnd - tStart)) / CLOCKS_PER_SEC / nTests;
    printf("\n\n\n________________________________________________________________________________\n");
    printf("Multiplication hash derived from string --> %lu", h);
    printf("\nAvg. execution time across 1000 trials: %g nanoseconds\n", hAvg2 * 1000000000);
    
    
    // (UNIVERSAL HASHING METHOD)
    // Populating the x[] array with random values
    
    for (int i=0; i<=MAX_BITS;i++){
        x[i]=rand()%10;
    }
    
    // Population of x[] array is not calculated as part of execution time
    tStart = clock();
    
    /* cast s to unsigned const char * */
    /* this ensures that elements of s will be treated as having values >= 0 */
    us = (unsigned const char *) s;
   
    h = 0;
    for(i = 0; *us != 0 && i < MAX_BITS; us++) {
        c = *us;
        for(shift = 0; shift < BITS_PER_CHAR; shift++, i++) {
            /* is low bit of c set? */
            if(c & 0x1) {
                h ^= x[i];
            }
            /* shift c to get new bit in lowest position */
               c >>= 1;
           }
       }
    tEnd = clock();
    
    hAvg3 = ((double) (tEnd - tStart)) / CLOCKS_PER_SEC / nTests;
    printf("\n\n\n________________________________________________________________________________\n");
    printf("Universal hash derived from string --> %lu", h);
    printf("\nAvg. execution time across 1000 trials: %g nanoseconds\n", hAvg3 * 1000000000);
}