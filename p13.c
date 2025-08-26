#include <stdlib.h>
#include <stdio.h>

int main() {

    FILE *nums, *new_file;
    if ((nums = fopen("./p13.txt", "r")) == NULL) {
        printf("Error opening file");
        exit(0);
    }

    if ((new_file = fopen("newp13.txt", "w")) == NULL){
        printf("Error creating file");
        exit(0);
    }

    char num[51];
    for (int i = 0; i<100; i++){
        fscanf(nums, "%s",num);
        for (int j = 0; j<50; j++){
            if (j == 20) {fprintf(new_file, "."); continue;}
            fprintf(new_file, "%c", num[j]);
        }
        fprintf(new_file, "\n");
    }
    fclose(nums);
    fclose(new_file);

    FILE *p13_new;
    if ((p13_new = fopen("newp13.txt", "r")) == NULL){
        printf("Error creating file");
        exit(0);
    }

    double sum = 0, number = 0;
    for (int k = 0; k < 100; k++){
        fscanf(p13_new, "%lf", &number);
        sum+=number;
    }
    printf("Sum is: %lf\n", sum);
    fclose(p13_new);
    return 0;
}