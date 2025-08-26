#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define N 20
int* factor(int n){
    int tmp = n;
    int *fac_pow = (int *)malloc(25*sizeof(int));
    int fac_pow_index = 0;
    // printf("Num is %d", n);
    for (int i = 2; i < sqrt(n)+1; i++){
        if (tmp%i == 0){
            int pow = 1;
            tmp/=i;
            while (tmp%i == 0){
                tmp/=i;
                pow+=1;
            }
            printf("%d^%d is a factor of %d\n", i,pow,n);
            *(fac_pow+fac_pow_index) = pow;
            fac_pow_index+=1;
        }
    }
    return fac_pow;
}

int main(){
    long facs = 1;
    int num = 149;
    int *facs1, *facs2; 
    while (facs < 500){
        facs = 1;
        num+=1;
        if (num%2 == 0){
            // printf("calculating factors");
            facs1 = factor(num/2);
            facs2 = factor(num+1);
        } else {
            // printf("calculating factors");
            facs1 = factor(num);
            facs2 = factor((num+1)/2);
        }
        for (int j = 0; j<N; j++){
            if (facs1[j] == 0) break;
            printf("the %d index is %d\n", j, facs1[j]);
            facs *= facs1[j]+1;
            facs1[j] = 0;
        }
        for (int k = 0; k<N; k++){
            if (facs2[k] == 0) break;
            printf("the %d index is %d\n", k, facs1[k]);
            facs *= facs2[k]+1;
        }
        facs+=2; // To account for 1 and n
        printf("facs is %ld for num %ld\n", facs, (long) num*(num+1/2));
    }
    free(facs1);
    free(facs2);
    printf("num is %d\n", num);
    long long ans = num*(num+1)/2;
    printf("%lld is the lowest answer\n", ans);
    return 0;
}