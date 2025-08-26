#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define N 100000

int main(){
    FILE* fptr;
    if ((fptr = fopen("./p18.txt", "r")) == NULL){
        printf("Error opening file");
        exit(0);
    }
    int *names[];
    char buf[N];
    fgets(buf, N, fptr);
    int index = 0;
    char* token = strtok(buf, " ");
    while (token != "\0"){
        names[index] = malloc(sizeof(char *));
        
        if (trgl[i][j]>max) {max = trgl[i][j]; index = j;}
        token = strtok(NULL, " ");
    }
    fclose(fptr);
}