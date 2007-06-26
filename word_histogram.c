/**
 * K&R 1.13
 * Show a histogram with bars indicating the count of occurencies of words of different length.
 * Bars are vertical!
 */

#include <stdio.h>
#include <string.h>
#define IN 1
#define OUT 0
#define MAX_LENGTH 100

main ()
{
    int state = OUT, len = 0, i = 0, j = 0;
    char *c;
    char *delims = "\t\n .,;!?()[]{}";

    int count[MAX_LENGTH];
    int maxcount = 0;
    for (i=0; i<MAX_LENGTH; i++)
        count[i] = 0;

    while (EOF != (*c = getchar()))
    {
        /// End of word?
        if ( state == IN )
            if (strpbrk(c, delims) != NULL) {
                count[len]++;
                maxcount = (count[len] > maxcount) ? count[len] : maxcount;
                state = OUT;
                len = 0;
            }
            else
                len++;
        else
            if (strpbrk(c, delims) == NULL) {
                state = IN;
                len++;
            }
            
    }

    /// Show histogram bars
    for (i=maxcount; i>0; i--) {
        for (j=0; j<MAX_LENGTH; j++) {
            if (count[j] > 0)
                if (count[j] >= i)
                    printf("  #");
                else
                    printf("   ");
        }
        printf("\n");
    }

    /// Display bar labels
    for (j=0; j<MAX_LENGTH; j++) {
        if (count[j] > 0)
            printf("%3d", j);
    }

}
