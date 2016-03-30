#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

/* checks input string, tests if all letters a-z 
 * are present, aka is it a pangram.
 * returns "pangram" if True, "not pangram" if False
 */
int main() {
    char in_str[1000];
    memset(in_str, -1, 1000);
    fgets(in_str, sizeof(in_str), stdin);
    char alpha[26];
    memset(alpha, 0, 26);
    for (int i=0; i<1000; i++) {
        int ascii = tolower(in_str[i]) - 97;
        if (ascii>=0 && ascii<27) {
            alpha[ascii] = 1;
        }
    }
    int result = 0;
    for (int i=0; i<26; i++) {
        if (alpha[i]==1) {
            result += 1;
        }
    }
    if (result == 26) {
        printf("pangram\n");
    } else {
        printf("not pangram\n");
    }
    return 0;
}
