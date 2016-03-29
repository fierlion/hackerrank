#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

int main() {
    size_t size;
    int n = 0;
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
        test_strings[i] = line;
    }
    for (int i=0; i<n; i++) {
    
    }
    return 0;
}
