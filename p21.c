#include <math.h>
#include <stdio.h>

// Probably a chain implementation where I start with 2, then 3, then 4, then 7 and so on and the chain ends in an amicable number and I restart.
// I did not implement this though
int divisor_sum(int n){
    int sum = 0;
    for (int i = 2; i < sqrt(n); i++){
        if (n%i == 0){
            sum += i+n/i;
        }
    }
    return sum+1;
}

int not_in(int* nums, int num){
    int i = 1;
    int in = 1;
    while (nums[i]!=0){
        if (nums[i] == num){
            return 0;
        }
        i++;
    }
    return 1;
}

int main(){
    int sum = 0;
    int nums[100];
    int len = 0;
    for (int i = 2; i < 10000; i++){
        int divsum = divisor_sum(i);
        int divsum2 = divisor_sum(divsum);
        if (divsum2 == i && divsum !=i && not_in(nums, divsum)) 
        {sum+= i+divsum; printf("amicable numbers are %d and %d\n", i, divsum); nums[len] = divsum; nums[len+1] = divsum2; len+=2;}
    }
    printf("%d\n", sum);
    return 0;
}