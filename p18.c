#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define N 15

// Brute force approach this time

int main(){
    FILE* fptr;
    if ((fptr = fopen("./p18.txt", "r")) == NULL){
        printf("Error opening file");
        exit(0);
    }
    int **trgl = malloc(sizeof(int *)*N);;
    for (int i = 0; i < N; i++){
        trgl[i] = malloc((i+1)*sizeof(int));
        int max = 0;
        int index = 0;
        char buf[512];
        fgets(buf, 512, fptr);
        char* token = strtok(buf, " ");
        for (int j = 0; j < i+1; j++){
            trgl[i][j] = atoi(token);
            if (trgl[i][j]>max) {max = trgl[i][j]; index = j;}
            token = strtok(NULL, " ");
        }
    }
    fclose(fptr);

    int max = 0;
    for (int n = 0; n < pow(2,14); n++){
        int sum = trgl[0][0];
        int indx = 0;
        for (int b = 0; b < 14; b++){
            int bin = n >> b & 1;
            indx+=bin;
            sum += trgl[b+1][indx];
        }
        if (sum > max) max = sum;
    }
    printf("Maximum sum is %d", max);

    for (int k = N-1; k >= 0; k--){
        free(trgl[k]);
    }
    free(trgl);
    return 0;
}