#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

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
    char **test_strings = (char **)calloc(n, sizeof(char *));
    for (int i=0; i<n; i++){
        char *line = NULL;
        getline(&line, &size, stdin);
        int len = (int)strlen(line);
        if (line[len-1] == '\n') {
            line[len-1] = '\0';
            test_strings[i] = line;
        } else {
            char newline[len+1];
            for (int i=0; i<len; i++) {
                newline[i] = line[i];
            }
            newline[len] = '\0';
            test_strings[i] = newline;
        }
    }
    for (int i=0; i<n; i++) {
        int str_len = (int)strlen(test_strings[i])-1;
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
