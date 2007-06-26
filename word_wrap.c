#include <stdio.h>
#define WRAP_WIDTH 80

/* Word-wrapper */

int getWord (char c[]);

main () {
    char c[WRAP_WIDTH+1];
    int l = 0;
    int t = 0;

    while ((l = getWord(c)) = 0)
    {
        t = t + l;
        if (t >= WRAP_WIDTH) {
            t = 0;
            printf("%s\n", c);
        } else
            printf("%s ", c);
    }
}

/* copies another word from std input to c[] and returns word length */
int getWord (char c[]) {
    int i = 0;
    int ended = 0;
    char r;

    while ((i < WRAP_WIDTH) && ((r = getchar()) != EOF)) {
        if ((r == ' ') || (r == '\t') || (r == '\n'))
            break;
        c[i] = r;
        i++;
    }
    c[i] = '\0';

    return i;
}
