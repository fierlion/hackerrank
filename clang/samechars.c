#define _GNU_SOURCE
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

/* takes as input an int n--number of strings
 * followed by n strings, each of which will be tested
 * for the number of letters a-z which are common to all:
 * 'ade'
 * 'abc'
 * 'acd'
 * only 'a' is common to all, so this returns 1
 */
int main() {
    size_t size;
    int n = 0;
    scanf("%d", &n);
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
    int alpha[26] = {0};
    for (int i=0; i<n; i++) {
        int inner_alpha[26] = {0};
        int str_len = (int)strlen(test_strings[i]);
        for (int j=0; j<str_len; j++) {
            int ascii = tolower(test_strings[i][j]) - 97;
            if (ascii>=0 && ascii <26) {
                if (inner_alpha[ascii] == 0){
                    alpha[ascii] += 1;
                }
                inner_alpha[ascii] += 1;
            }
        }
    }
    int result = 0;
    for (int i=0; i<26; i++) {
        if (alpha[i] == n) {
            result += 1;
        }
    }
    printf("%d\n", result);
    return 0;
}
