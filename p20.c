#include <stdlib.h>
#include <stdio.h>

// n is the input, will calculate the sum of digits of n!
int main(int argc, char* argv[]){
    if (argc != 2){
        printf("Correct usage is %s <factorial>\n", argv[0]);
        exit(0);
    }
    int n = atoi(argv[1]);
    int* nfactorial = (int *)malloc(sizeof(int)*1000);
    nfactorial[0] = 1;
    int len = 1;
    for (int i = 1; i <= n; i++){
        int carry = 0;
        for (int j = 0; j < len; j++){
            
            nfactorial[j] *= i;
            nfactorial[j] += carry;
            if (nfactorial[j]>=10){
                // printf("index %d is greater than 10\n", j);
                carry = (nfactorial[j]-nfactorial[j]%10)/10;
                nfactorial[j] = nfactorial[j]%10;
            } else {
                carry = 0;
            }
        }
        if (carry > 0){
            int tmp = carry;
            int carlen = 0;
            while (tmp >0){
                nfactorial[len+carlen] = tmp%10;
                tmp /=10;
                carlen++;
            }
            len+=carlen;
        }
    }
    long sum = 0;
    for (int f = len-1; f >= 0; f--){
        sum += nfactorial[f]; 
    }
    printf("%ld\n", sum);
    free(nfactorial);
    return 0;
}