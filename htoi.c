/**
 * K&R 2.3
 */
#include <stdio.h>
#include <ctype.h>
#include <limits.h>

int htoi (char []);

int main ()
{
    printf("%d", htoi("0xa5bF"));
    putchar('\n');
    printf("%d", 0xA5bF);
}

/**
 * htoi() function converts hexadecimal string to decimal integer
 */
int htoi (char s[])
{
    int i, n = 0;

    for (i=0; s[i] != '\0'; i++) {
        if (!( i == 0 && s[i] == '0' || i == 1 && (s[i] == 'x' || s[i] == 'X'))) {
            if isdigit(s[i])
                n = n * 16 + s[i] - '0';
            else if (s[i] >= 'a' && s[i] <= 'f')
                n = n * 16 + s[i] - 'a' + 10;
            else if (s[i] >= 'A' && s[i] <= 'F')
                n = n * 16 + s[i] - 'A' + 10;
        }
    }

    return n;
}
