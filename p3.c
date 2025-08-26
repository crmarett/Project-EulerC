#include <stdio.h>
#include <stdint.h>
#include <math.h>

int main(){
    long num, max_fac;
    printf("Enter number to factor: ");
    scanf("%ld", &num);
    printf("sqare root of %ld is %f\n", num, sqrt(num));
    for (int i = 2; i< (int) sqrt(num); i++){
        if (num%i == 0) {
            num /=i;
            max_fac = i;
        }
    }
    printf("%ld or %ld are the largest factor\n", num, max_fac);
    return 0;
}