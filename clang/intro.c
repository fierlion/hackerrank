#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {
    int target;
    int n;
    char *test_string = NULL;
    scanf("%d", &target);
    getc(stdin);
    scanf("%d", &n);
    getc(stdin);
    size_t size;
    getline(&test_string, &size, stdin);
    int ints[n];
    char *pch = strtok(test_string, " ");
    for (int i=0; i<n; i++) {
        ints[i] = atoi(pch);
        pch = strtok(NULL, " ");
    }
    for (int i=0; i<n; i++) {
        if (ints[i] == target) {
            printf("%d\n", i);
            break;
        }
    }
}
