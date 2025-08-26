#include <math.h>
#include <stdio.h>

int main(){
    double sqsum = 0, sumsq = 0;
    sqsum = (100*101*201)/6;
    sumsq = pow(100*101/2,2);
    printf("%f\n", sumsq-sqsum);
    return 0;
}