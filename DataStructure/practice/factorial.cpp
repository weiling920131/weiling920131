#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int factorial(int);

int main() {
    while (1) {
        int n;
        printf("input a number: ");
        scanf("%d", &n);

        if (n >= 1) printf("ans: %d\n", factorial(n));
        else if (n == 0) printf("ans: 1\n");
        else printf("wrong input\n");
    }
    system("pause");
    return 0;
}

int factorial(int n) {
    if (n == 1) return 1;
    else return n * factorial(n - 1);
}



