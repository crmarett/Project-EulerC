#include <stdlib.h>
#include <stdio.h>


int main(int argc, char* argv[]){
    if (argc != 2){
        printf("Correct usage is %s <power>\n", argv[0]);
        exit(0);
    }
    int n = atoi(argv[1]);
    int* powertwo = (int *)malloc(sizeof(int)*30000);
    powertwo[0] = 1;
    int len = 1;
    for (int i = 1; i <= n; i++){
        int carry = 0;
        for (int j = 0; j < len; j++){
            
            powertwo[j] *=2;
            powertwo[j] += carry;
            if (powertwo[j]>=10){
                carry = 1;
                powertwo[j] = powertwo[j]%10;
            } else {
                carry = 0;
            }
        }
        
        if (carry == 1){
            powertwo[len] = carry;
            len+=1;
        }
    }
    long sum = 0;
    for (int f = 0; f < len; f++){
        sum += powertwo[f]; 
    }
    printf("%ld\n", sum);
    free(powertwo);
    return 0;
}