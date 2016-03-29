#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

int main() {
    // input:
    // int
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
    for (int i=0; i<n; i++) {
        char *line = NULL;
        getline(&line, &size, stdin);
        test_strings[i] = line;
    }
    
    for (int i=0; i<n; i++) {
        int sum = 0;
        char str_start = test_strings[i][0];
        int iter = 1;
        while (test_strings[i][iter] != '\0') {
            if (test_strings[i][iter] == str_start) {
                sum += 1;
            } else {
                str_start = test_strings[i][iter];
            }
            iter += 1;
        }
        printf("sum is: %d\n", sum);
    }
 
    for (int i=0; i<n; i++) {
        free(test_strings[i]);
    }
    free(test_strings);
}
