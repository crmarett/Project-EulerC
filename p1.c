#include <stdio.h>
#include <stdint.h>

int main(){
    long sum = 0;
    for (int i = 0;i <1000; i++){
        if (i%3 ==0 || i%5 == 0) sum+=i;
        
    }
    printf("%ld\n", sum); 
    return 0;
}