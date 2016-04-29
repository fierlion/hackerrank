#define _GNU_SOURCE
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <limits.h>

#define MAX(x, y) (((x) > (y)) ? (x) : (y))

int main() {
    int n = 0;
    scanf("%d", &n);
    getc(stdin);
    int sizes[n];
    char **test_strings = malloc(n * sizeof(char *));
    for (int i=0; i<n; i++) {
        scanf("%d", &sizes[i]);
        getc(stdin);
        char *line = NULL;
        size_t size;
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
        //cur_ints will be the array of ints for this test case
        int cur_ints[sizes[i]];
        char *pch = strtok(test_strings[i], " ");
        int current_token = 0;
        while (pch != NULL) {
            cur_ints[current_token] = (int)strtol(pch, (char **)NULL, 10);
            pch = strtok(NULL, " ");
            current_token += 1;
        }
        //using kadane's algorithm
        int total_max = cur_ints[0];
        int max_to_here = cur_ints[0];
        for (int j=1; j<sizes[i]; j++) {
            int totaled = max_to_here + cur_ints[j];
            max_to_here = MAX(cur_ints[j], totaled);
            total_max = MAX(total_max, max_to_here);
        }
        int noncontig_max = INT_MIN;
        for (int j=0; j<sizes[i]; j++) {
            if (cur_ints[j] > 0) {
                if (noncontig_max == INT_MIN) {
                    noncontig_max = cur_ints[j];
                } else {
                    noncontig_max += cur_ints[j];
                }
            }
        }
        if (noncontig_max == INT_MIN) {
            //all the ints were negative... find the largest
            noncontig_max = cur_ints[0];
            for (int j=1; j<sizes[i]; j++) {
                if (cur_ints[j] > noncontig_max) {
                    noncontig_max = cur_ints[j];
                }
            }
        }
        printf("%d %d\n", total_max, noncontig_max);
    }
    for (int i=0; i<n; i++) {
        free(test_strings[i]);
    }
    free(test_strings);
}
