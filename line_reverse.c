/**
 * K&R 1.19
 */

#include <stdio.h>
#include <string.h>
#define MAXLENGTH 1000

int reverse (char t[], char s[]);

main ()
{
    char s1[MAXLENGTH], s2[MAXLENGTH];

    while (getline(s1) > 0)
    {
        reverse(s2, s1);
        printf(s2);
    }

}

int getline (char s[])
{
    int i = 0;
    char c;
    c = getchar();
    while ((c != EOF) && (c != '\n')) {
        s[i] = c;
        i++;
        c = getchar();
    }
    if (c == '\n') {
        s[i] = c;
        i++;
    }
    s[i] = '\0';

    return i;
}

int reverse (char t[], char s[])
{
    int i;

    for (i = 0; i < strlen(s); i++)
        t[i] = s[strlen(s)-i-1];

    t[strlen(s)] = '\0'; 

    return i;
}
