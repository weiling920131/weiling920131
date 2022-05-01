#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int* merge(int* a, int* b, int size_a, int size_b);

int main() {

    int* a = (int*)calloc(30, sizeof(int));
    int* b = (int*)calloc(30, sizeof(int));
    int num_a = 0;
    int num_b = 0;
    char ch;
    int num = 0;

    do {
        scanf("%d", a + num_a);
        num_a++;
        scanf("%c", &ch);
    } while (ch != '\n');

    do {
        scanf("%d", b + num_b);
        num_b++;
        scanf("%c", &ch);
    } while (ch != '\n');

    int* ans = merge(a, b, num_a, num_b);
    int i = 0;
    while (*(ans + num) != 99999999) {
        printf(" %4d", *(ans + num));
        num++;
        i++;
        if (i == 5) {
            printf("\n");
            i = 1;
        }
    }
    printf("\n");

    system("pause");
    return 0;
}

int* merge(int* a, int* b, int size_a, int size_b) {
    int* ans = (int*)calloc(size_a + size_b + 1, sizeof(int));
    int num_a = 0, num_b = 0;
    int num = 0;
    int end, from;
    int* last;
    while (num_a < size_a && num_b < size_b) {
        while (*(a + num_a) == *(a + num_a + 1)) num_a++;
        while (*(b + num_b) == *(b + num_b + 1)) num_b++;
        if (*(a + num_a) < *(b + num_b)) {
            *(ans + num) = *(a + num_a);
            num_a++;
        }
        else if (*(b + num_b) < *(a + num_a)) {
            *(ans + num) = *(b + num_b);
            num_b++;
        }
        else {
            *(ans + num) = *(a + num_a);
            num_a++;
            num_b++;
        }
        num++;
    }
    if (num_a == size_a && num_b == size_b) {
        *(ans + num) = 99999999;
        return ans;
    }
    else if (num_b == size_b) {
        end = size_a;
        from = num_a;
        last = a;
    }
    else {
        end = size_b;
        from = num_b;
        last = b;
    }

    for (from; from < end; num++, from++) {//結束之後會加
        *(ans + num) = *(last + from);
    }
    
    *(ans + num) = 99999999;

    return ans;
}
