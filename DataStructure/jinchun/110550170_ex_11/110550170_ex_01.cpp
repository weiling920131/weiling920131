#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int* merge(int* ptr1, int size1, int* ptr2, int size2);

int main() {
    while (1) {
        int yesno;
        printf("enter 1 to compare or 0 to quit: ");
        scanf("%d", &yesno);

        if (yesno == 1) {
            int* ptr1 = (int*)calloc(30, sizeof(int)), * ptr2 = (int*)calloc(30, sizeof(int));
            int e1 = 0, e2 = 0;
            char ch;
            int i = 0;
            int num = 0;
            printf("plz enter your array on the new line: ");
            do {
                scanf("%d", (ptr1 + e1));
                e1++;
            } while (ch = getchar() != '\n');

            printf("plz enter your array on the new line: ");
            do {
                scanf("%d", (ptr2 + e2));
                e2++;
            } while (ch = getchar() != '\n');

            int *answer = merge(ptr1, e1 - 1, ptr2, e2 - 1);
            while (*(answer + i) != -99999999) {
                if (*(answer + i) == *(answer + i - 1)) {
                    i++;
                    continue;
                }
                if (num == 5) {
                    printf("\n");
                    num = 0;
                }
                printf("%5d", *(answer + i));
                i++;
                num++;
            }
            printf("\n");
        }
        else break;
    }
    system("pause");
    return 0;
}

int* merge(int* ptr1, int size1, int* ptr2, int size2) {
    int* ptr = (int*)calloc(60, sizeof(int));
    int n = 0, e1 = 0, e2 = 0;
    while (1) {
        if (e1 > size1 && e2 <= size2) {
            while (e2 <= size2) {
                *(ptr + n) = *(ptr2 + e2);
                n++;
                e2++;
            }
            *(ptr + n) = -99999999;
            return ptr;
        }
        else if (e1 <= size1 && e2 > size2) {
            while (e1 <= size1) {
                *(ptr + n) = *(ptr1 + e1);
                n++;
                e1++;
            }
            *(ptr + n) = -99999999;
            return ptr;
        }
        else if (e1 > size1 && size2 < e2) {
            *(ptr + n) = -99999999;
            return ptr;
        }
        else {
            if (*(ptr1 + e1) < *(ptr2 + e2)) {
                *(ptr + n) = *(ptr1 + e1);
                n++;
                e1++;
            }
            else if (*(ptr1 + e1) > *(ptr2 + e2)) {
                *(ptr + n) = *(ptr2 + e2);
                n++;
                e2++;
            }
            else {
                *(ptr + n) = *(ptr1 + e1);
                n++;
                e1++;
                e2++;
            }
        }
    }
}



