#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
    char time[] = "12:45:54PM";
    char hour_str[3];
    hour_str[0] = time[0];
    hour_str[1] = time[1];
    hour_str[2] = '\0';
    int hour = atoi(hour_str);
    if (time[8] == 'P') {
        hour += 12;
    }
    if (hour == 24) {
        hour = 12;
    }
    hour_str[0] = (hour / 10) + '0';
    hour_str[0] = (hour % 10) + '0';
    if (time[8] == 'A') {
        if (hour == 12) {
            hour_str[0] = '0';
            hour_str[1] = '0';
        }
    }
    char res_str[9];
    for (int i=2; i<8; i++){
        res_str[i] = time[i];
    }
    res_str[8] = '\0';
    res_str[0] = hour_str[0];
    res_str[1] = hour_str[1];
    printf("%s\n", res_str);
    return 0;
}
