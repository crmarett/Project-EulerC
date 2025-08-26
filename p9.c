#include <math.h>
#include <stdio.h>
/*
Think Triforce on this implementation. Does not check the middle triangle, but may not have to as
*/
int main(){
    for (int i = 1;i<500;i++){
        for (int j = 1; j<500; j++){
            double ab = pow(i,2) + pow(j,2);
            double c = pow(1000-i-j, 2);
            if (ab == c) printf("Sides are %d %d %d with product %d\n",i, j, 1000-i-j, i*j*(1000-i-j));
        }
    }
    return 0;
}