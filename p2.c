#include <stdio.h>
#include <stdint.h>

int main(){
    long sum = 0;
    int a = 1, b = 2;
    while (b < 4000000){
        if (b%2 == 0) sum+=b;
        int tmp = a+b;
        a = b;
        b = tmp;
    }
    printf("%ld\n", sum); 
    return 0;
}