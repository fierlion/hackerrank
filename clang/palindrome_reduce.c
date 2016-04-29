#define _GNU_SOURCE
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

/* takes as input an int n--number of strings
 * followed by n strings, each of which will be tested
 * for its distance from being a palindrome:
 * 'aba' -> 0
 * 'abc' -> 2
 * 'cba' -> 2
 * the return value is the distances separated by newlines.
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
    for (int i=0; i<n; i++){
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
        int str_len = (int)strlen(test_strings[i]);
        int sum = 0;
        for (int j=0; j<str_len/2; j++) {
            int start = test_strings[i][j];
            int end = test_strings[i][str_len-j-1];
            if (start == end) {
                continue;
            } else if (start < end) {
                sum += end-start;
            } else {
                sum += start-end;
            }
        }
        printf("%d\n", sum);
    }
    return 0;
}
