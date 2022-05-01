#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>



int main() {

    int m, n;
    int stop = 0;
    char null[] = "(null)";
    printf("set the size of array A and B:");
    scanf("%d%d", &m, &n);
    char** a = (char**)calloc(m, sizeof(char*));
    char** b = (char**)calloc(n, sizeof(char*));
    for (int i = 0; i < m; i++) {
        *(a + i) = (char*)calloc(20, sizeof(char));
        *(a + i) = null;
    }
    for (int i = 0; i < n; i++) {
        *(b + i) = (char*)calloc(20, sizeof(char));
        *(b + i) = null;
    }

    while (1) {
        int p;
        printf("0: add a book, 1: delete a book, 2: exchange the books\n");
        scanf("%d", &p);
        int x, y, s;
        int ind = 0;
        char** mat;
        char str[50];

        switch (p) {
        case 0:
            scanf("%d%d%d", &x, &y, &s);
            if (x == 0) {
                mat = a;
                ind = m;
            }
            else if (x == 1) {
                mat = b;
                ind = n;
            }
            else {
                printf("wrong enter\n");
                break;
            }
            if (y >= 0 && y < ind) {
                if (strcmp(*(mat + y), null) == 0) {
                    scanf("%s", &str);
                    *(mat + y) = str;
                }
                else stop++;
            }
            else stop++;

            break;
        case 1:
            scanf("%d%d", &x, &y);
            if (x == 0) {
                mat = a;
                ind = m;
            }
            else if (x == 1) {
                mat = b;
                ind = n;
            }
            else {
                printf("wrong enter\n");
                break;
            }
            if (y >= 0 && y < ind) *(mat + y) = null;
            else stop++;

            break;
        case 2:
            scanf("%d%d", &x, &y);
            if (y < 0 || y >= n || x<0 || x>=m) stop++; 
            else {
                strcpy(str, *(a + x));
                *(a + x) = *(b + y);
                *(b + y) = str;
            }
            break;
        default:
            break;
        }

        if (stop == 1) break;

        printf("A:\n");
        for (int i = 0; i < m; i++) printf("%s\n", *(a + i));
        printf("B:\n");
        for (int i = 0; i < n; i++) printf("%s\n", *(b + i));
    }
    system("pause");
    return 0;
}




