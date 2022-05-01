#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>



int main() {

    int** a = (int**)calloc(3, sizeof(int*));

    *a = (int*)calloc(5, sizeof(int));
    *(a + 1) = (int*)calloc(4, sizeof(int));
    *(a + 2) = (int*)calloc(7, sizeof(int));
    printf("Step 1:\n");
    for (int i = 0; i < 5; i++) printf("%d ", *(*a + i));
    printf("\n");
    for (int i = 0; i < 4; i++) printf("%d ", *(*(a + 1) + i));
    printf("\n");
    for (int i = 0; i < 7; i++) printf("%d ", *(*(a + 2) + i));
    printf("\n");
    
    *(a + 1)=(int *)realloc(*(a + 1), 9*sizeof(int));
    for (int i = 4; i < 9; i++) *(*(a + 1) + i) = 1;
    printf("Step 2:\n");
    for (int i = 0; i < 5; i++) printf("%d ", *(*a + i));
    printf("\n");
    for (int i = 0; i < 9; i++) printf("%d ", *(*(a + 1) + i));
    printf("\n");
    for (int i = 0; i < 7; i++) printf("%d ", *(*(a + 2) + i));
    printf("\n");
    
    a=(int**)realloc(a, 4*sizeof(int *));
    *a = (int*)calloc(5, sizeof(int));
    *(a + 3) = (int*)calloc(2, sizeof(int));
    for (int i = 0; i < 2; i++) *(*(a + 3) + i) = 2;
    printf("Step 3:\n");
    for (int i = 0; i < 5; i++) printf("%d ", *(*a + i));
    printf("\n");
    for (int i = 0; i < 9; i++) printf("%d ", *(*(a + 1) + i));
    printf("\n");
    for (int i = 0; i < 7; i++) printf("%d ", *(*(a + 2) + i));
    printf("\n");
    for (int i = 0; i < 2; i++) printf("%d ", *(*(a + 3) + i));
    printf("\n");
    
    printf("Step 4:\n");
    for (int i = 0; i < 5; i++) printf("%d ", *(*a + i));
    printf("\n");
    for (int i = 0; i < 7; i++) printf("%d ", *(*(a + 2) + i));
    printf("\n");
    for (int i = 0; i < 2; i++) printf("%d ", *(*(a + 3) + i));
    printf("\n");
    
    free(*a);
    free(*(a + 1));
    free(*(a + 2));
    free(*(a + 3));

    system("pause");
    return 0;
}




