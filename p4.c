#include <string.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

int main(){
    long pal = 0, prod;
    char* p;
    for (int i = 700; i<1000; i++){
        for (int j = 700; j<1000; j++){
            int pal_bool = 1;
            prod = i*j;
            sprintf(p, "%ld", prod);
            int k = strlen(p);
            char* end = p+k;
            for (int l = 0; l < k/2+1; l++){
                if (*(p+l) != *(end-1-l)) {
                    pal_bool = 0;
                    break;
                }
            }
            if (pal_bool && prod > pal){
                pal = prod;
            }
        }
    }
    printf("%ld\n", pal);
    return 0;
}