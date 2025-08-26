#include <stdio.h>
#include <math.h>

//This is very poor
int main(){
    long ctr = 4;
    long i = 2;
    long primes[1000000] = {2,3};
    while (ctr < 2000000){
        int prime = 1;
        long tmp = i;
        for (int j = 0; j < tmp; j++){
            if (ctr%primes[j] == 0) {prime = 0; break; }
        }
        if (prime == 1){
            primes[i] = ctr;
            i+=1;
            // printf("%ld is prime\n", ctr);
        }
        ctr+=1;
        // printf("Ctr is: %d", ctr);
    }
    long sum = 0;
    for (int k = 0; k<i; k++) sum+=primes[k];
    printf("Sum: %ld\n", sum);
    return 0;
}