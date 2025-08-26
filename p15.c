#include <stdio.h>
#include <stdlib.h>

#define N 20

// Just calculating (2n!)/(2*n!) and I think very poorly

int main(){
    unsigned long long num = 1, den = 1;
    for (int i = N*2; i>=N+1; i--){
        if (i%(i-N) == 0 && (i-N)!=1){
            num*=i/(i-N);
        } else {
            num*=i;
            den*=(i-N);
        }
        if (num%den == 0) {num = num/den; den = 1;}
        // printf("num is %llu\t\tden is %llu\n", num, den);
    }
    printf("Total paths: %llu\n", num/den);
    return 0;
}