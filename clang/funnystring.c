#define _GNU_SOURCE
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>

/* takes as input an int n--number of strings
 * followed by n strings, each of which will be tested
 * forward and backward to determine distance between chars
 * if forward and backward distance are the same,
 * print 'Funny', else print 'Not Funny'
 * 'acxz' (a-c --> 2, c-x --> 21, x-z --> 2)
 * prints Funny
 */

int main() {
    size_t size;
    int n = 0;
    scanf("%d", &n);
    if (n<1 || n>10) {
        printf("illegal argument\n");
        return 1;
    }
    //skip newline
    getc(stdin);
    char **test_strings = calloc(n, sizeof(char *));
    for (int i=0; i<n; i++) {
        char *line = NULL;
        getline(&line, &size, stdin);
        int len = (int)strlen(line);
        if (line[len-1] == '\n') {
            line[len-1] = '\0';
            test_strings[i] = line;
        } else {
            char *newline = malloc(len+1 * sizeof(char));
            strncpy(newline, line, len);
            newline[len] = '\0';
            test_strings[i] = newline;
        }
    }
    for (int i=0; i<n; i++) {
        int test_len = (int)strlen(test_strings[i]);
        int diffs_len = test_len - 1;
        int diffs[diffs_len];
        //if test_len < 1 not supporting empty strings
        for (int j=1; j<test_len; j++) {
            diffs[j-1] = abs(test_strings[i][j] - test_strings[i][j-1]);
        }
        bool palindrome = true;
        for (int j=0; j<diffs_len/2; j++) {
            int start = diffs[j];
            int end = diffs[diffs_len - j - 1];
            if (start == end) {
                continue;
            } else {
                palindrome = false;
                break;
            }
        }
        if (palindrome == true) {
            printf("Funny\n");
        } else {
            printf("Not Funny\n");
        }
    }   
}
