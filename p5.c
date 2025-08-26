#include <string.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

int main(){
    int nums[21];
    int num = 1;
    for (int i = 2; i<21; i++){
        int tmp = i;
        for (int j = 0; j<i-2; j++){
            if (tmp%nums[j] == 0){
                tmp = tmp/nums[j];
            }
        }
        printf("%d\n", tmp);
        nums[i-2] = tmp;
        num*=tmp;
    }
    printf("%d\n", num);
    return 0;
}