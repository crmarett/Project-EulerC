#include <stdio.h>
#include <stdlib.h>

int main(){
    int yr = 1901;
    int day = 2;
    int sunday_count = 0;
    while (yr < 2001){
        int leap = (yr%4 == 0) ? 1 : 0;
        int months[12];
        months[0] = 31;
        months[1] = leap ? 29 : 28;
        months[2] = 31;
        months[3] = 30;
        months[4] = 31;
        months[5] = 30;
        months[6] = 31;
        months[7] = 31;
        months[8] = 30;
        months[9] = 31;
        months[10] = 30;
        months[11] = 31;
        for (int i = 0; i < 12; i++){
            day +=months[i]%7;
            if (day%7 == 0) sunday_count++;
        }
        yr++;
    }
    printf("Sunday count is: %d\n", sunday_count);
    return 0;
}