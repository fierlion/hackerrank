#include <stdio.h>
#include <stdlib.h>

/* takes as input int num testcases 
 * followed by n '\n' separated ints.  
 * for each n, each odd doubles the value, even adds 1
 * 0->0
 * 1->2 (doubles)
 * 2->3 (adds one to prev value)
 * etc.
 */

int main() {
    int n = 0;
    scanf("%d", &n);
    if (n<1 || n> 10) {
        printf("illegal argument");
        return 1;
    }
    int test_values[n];
    for (int i=0; i<n; i++) {
        // skip newline
        getc(stdin);
        scanf("%d", &test_values[i]);
    };
    for (int i=0; i<n; i++) {
        int current_test = test_values[i];
        int result = 1;
        for (int j=0; j<current_test; j++) {
            result = (j % 2 == 0) ? result * 2 : result + 1;      
        }
        printf("%d\n", result);
    }
}
