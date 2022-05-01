#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int** matrix_multiplication(int** mat1, int row1, int col1, int** mat2, int row2, int col2);

int main() {

    FILE* input;
    char s[10];

    while (1) {
        printf("Please enter input file: ");
        scanf("%s", &s);
        input = fopen(s, "r");
        int m1 = 0, n1 = 0, m2 = 0, n2 = 0;

        fscanf(input, "%dX%d", &m1, &n1);
        int** a = (int**)calloc(m1, sizeof(int*));
        for (int l = 0; l < m1; l++) {
            *(a + l) = (int*)calloc(n1, sizeof(int));
        }
        for (int i = 0; i < m1; i++) {
            for (int j = 0; j < n1; j++) {
                fscanf(input, "%d", *(a + i) + j);
            }
        }

        fscanf(input, "%dX%d", &m2, &n2);
        int** b = (int**)calloc(m2, sizeof(int*));
        for (int l = 0; l < m2; l++) {
            *(b + l) = (int*)calloc(n2, sizeof(int));
        }
        for (int i = 0; i < m2; i++) {
            for (int j = 0; j < n2; j++) {
                fscanf(input, "%d", *(b + i) + j);
            }
        }

        int** ans = matrix_multiplication(a, m1, n1, b, m2, n2);
        for (int i = 0; i < m1; i++) {
            for (int j = 0; j < n2; j++) {
                printf("%5d", *(*(ans + i) + j));
            }
            printf("\n");
        }
        fclose(input);
    }
    system("pause");
    return 0;
}

int** matrix_multiplication(int** mat1, int row1, int col1, int** mat2, int row2, int col2) {
    int** ans = (int**)calloc(row1, sizeof(int*));
    for (int i = 0; i < row1; i++) {
        *(ans + i) = (int*)calloc(col2, sizeof(int));
    }

    for (int i = 0; i < row1; i++) {
        for (int k = 0; k < col2; k++) {
            int sum = 0;
            for (int p = 0; p < col1; p++) {
                sum += (*(*(mat1 + i) + p)) * (*(*(mat2 + p) + k));
            }
            *(*(ans + i) + k) = sum;
            }
    }
    return ans;
}


