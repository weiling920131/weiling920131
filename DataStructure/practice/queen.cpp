#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>

void eightqueen(int row,int max);
int* queen;
int check;
int tim = 0;

int main() {
    int n;
    scanf("%d", &n);//row column
    for (int i = 1; i <= n; i++) {
        queen = (int*)calloc(n + 1, sizeof(int));
        queen[1] = i;
        eightqueen(2, n);
        free(queen);
    }

    system("pause");
    return 0;
}

void eightqueen(int row, int max) {//1~8都不行會自動跳出函式執行下一個for(29行)
    if (row <= max) {
        for (int col = 1; col <= max; col++) {
            check = 0;
            for (int y = 1; y < row; y++) {
                if (queen[y] == col || abs(queen[y] - col) == abs(y - row)) {
                    check = 1;
                    break;
                }
            }
            if (check == 0) {
                queen[row] = col;
                eightqueen(row + 1, max);
            }
        }
    }
    else {
        tim++;
        printf("\nsolution of %d:\n", tim);
        int i = 1;
        for (int r = 1; r <= max; r++) {
            for (int c = 1; c <= max; c++) {
                if (i == r && queen[i] == c) {
                    i++;
                    printf(" [Q]");
                    continue;
                }
                printf(" [-]");
            }
            printf("\n");
        }
    }
}


