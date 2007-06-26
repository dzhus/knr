/**
 * 2.4 K&R
 */

#include <stdio.h>

void squeeze (char s1[], char s2[]);

int main (void) 
{
    /// @attention Declaring s as a character array!
    ///            Using squeeze("blah", "b") is an 'undefined behavior' case.
    ///            WWW: <http://www.linux.org.ru/view-message.jsp?msgid=1735853>.
    char s1[] = "foo bar baz";
    char s2[] = "fxb";
    squeeze(s1, s2);
    return 0;
}

/**
 * Remove from s1 all characters occuring in s2 and print s1.
 */
void squeeze (char s1[], char s2[])
{
    int i, j, k, enc;

    for (i = j = 0; s1[i] != '\0'; i++) {
        enc = 0;
        for (k = 0; s2[k] != '\0' && !enc; k++)
            if (s2[k] == s1[i])
                enc = 1;
        if (!enc)
            s1[j++] = s1[i];
    }

    s1[j] = '\0';
    printf("%s", s1);
}
