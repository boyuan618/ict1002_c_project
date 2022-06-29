#include <ctype.h>
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_INPUT 10

char input[10];
int inc;
char * inv[10];
const char *delimiters = " ?\t\n";
int len;

int main () {

	inv[1] = NULL;
    do {
        /* read the line */
        fgets(input, MAX_INPUT, stdin);

        /* split it into words */
        inc = 0;
        inv[inc] = strtok(input, delimiters);
        printf("%s",inv[inc]);
        while (inv[inc] != NULL) {

            /* remove trailing punctuation */
            len = strlen(inv[inc]);
            while (len > 0 && ispunct(inv[inc][len - 1])) {
                inv[inc][len - 1] = '\0';
                len--;
            }

            /* go to the next word */
            inc++;
            inv[inc] = strtok(NULL, delimiters);
        }
    } while (inc < 1);

    printf("%s", *inv);

    return 0;
}