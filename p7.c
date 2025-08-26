#include <stdio.h>
#include <math.h>

int main(){
    int ctr = 4;
    int i = 2;
    int primes[10001] = {2,3};
    while (i != 10001){
        int prime = 1;
        int tmp = i;
        for (int j = 0; j < tmp; j++){
            if (ctr%primes[j] == 0) {prime = 0; break; }
        }
        if (prime == 1){
            primes[i] = ctr;
            i+=1;
        }
        ctr+=1;
    }
    printf("%d\n", primes[10000]);
    return 0;
}