#include <stdio.h>
#include <stdlib.h>

int main(){
    FILE* nums;
    if ((nums = fopen("./p11.txt", "r")) == NULL) {
        printf("Error opening file");
        exit(0);
    }
    int arr[20][20];
    for (int i = 0; i<20; i++){
        for (int j = 0; j < 20; j++){
            fscanf(nums, "%d", &arr[i][j]);
        }
    }
    int max_prod = 0;
    int prod;
    //Check right and left
    for (int i = 0; i<20; i++){
        for (int j = 0; j < 17; j++){
            prod = arr[i][j]*arr[i][j+1]*arr[i][j+2]*arr[i][j+3];
            if (prod > max_prod) {
                max_prod = prod;
                printf("right Nums were: %d %d %d %d\n", arr[i][j], arr[i][j+1], arr[i][j+2], arr[i][j+3]);
            }
        }
    }

    // Check up and down
    for (int i = 0; i<17; i++){
        for (int j = 0; j < 20; j++){
            prod = arr[i][j]*arr[i+1][j]*arr[i+2][j]*arr[i+3][j];
            if (prod > max_prod) {
                max_prod = prod;
                printf("up Nums were: %d %d %d %d\n", arr[i][j], arr[i+1][j], arr[i+2][j], arr[i+3][j]);
            }
        }
    }

    // Check diagonal right
    for (int i = 0; i<17; i++){
        for (int j = 0; j < 17; j++){
            prod = arr[i][j]*arr[i+1][j+1]*arr[i+2][j+2]*arr[i+3][j+3];
            if (prod > max_prod) {
                max_prod = prod;
                printf("dr Nums were: %d %d %d %d\n", arr[i][j], arr[i+1][j+1], arr[i+2][j+2], arr[i+3][j+3]);
            }
        }
    }

    // Check diagonal left
    for (int i = 0; i<17; i++){
        for (int j = 3; j < 20; j++){
            prod = arr[i][j]*arr[i+1][j-1]*arr[i+2][j-2]*arr[i+3][j-3];
            if (prod > max_prod) {
                max_prod = prod;
                printf("dl Nums were: %d %d %d %d\n", arr[i][j], arr[i+1][j-1], arr[i+2][j-2], arr[i+3][j-3]);
            }
        }
    }

    printf("Largest product is: %d\n", max_prod);
    return 0;
}