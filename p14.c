#include <stdio.h>
#include <stdlib.h>

int rec_collatz(long num, int index){
    if (num == 1) return index;
    if (num%2 == 0){
        return rec_collatz(num/2, index+1);
    } else{
        return rec_collatz(3*num+1, index+1);
    }
    
}

int collatz(){
    int max = 0;
    long num = 1;
    int chain_len = 0;
    while (num<1000000){
        chain_len = rec_collatz(num, 1);
        if (chain_len > max) {max = chain_len; printf("New number max is: %ld\n", num);}
        num+=1;
    }
    return max;
}

int main() {
    int max = collatz();
    printf("Longest chain is length %d\n", max);
    return 0;
}