#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void bubble_sort(int* a, int size);
void selection_sort(int* a, int size);
void insertion_sort(int* a, int size);

int main() {

    FILE* data1, * data2, * data3;
    data1 = fopen("data1.txt", "r");
    data2 = fopen("data2.txt", "r");
    data3 = fopen("data3.txt", "r");
    int* p1 = (int*)calloc(25000, sizeof(int));
    int* p2 = (int*)calloc(25000, sizeof(int));
    int* p3 = (int*)calloc(25000, sizeof(int));

    for (int i = 0; i < 25000; i++) fscanf(data1, "%d", p1 + i);
    for (int i = 0; i < 25000; i++) fscanf(data2, "%d", p2 + i);
    for (int i = 0; i < 25000; i++) fscanf(data3, "%d", p3 + i);

    bubble_sort(p1, 25000);
    for (int i = 0; i < 25000; i++) fscanf(data1, "%d", p1 + i);
    for (int i = 0; i < 25000; i++) {
        if (i % 10 == 0) printf("\n");
        printf("%d  ", p1[i]);
    }
    printf("\n\n");
    selection_sort(p1, 25000);
    for (int i = 0; i < 25000; i++) fscanf(data1, "%d", p1 + i);
    insertion_sort(p1, 25000);
    

    bubble_sort(p2, 25000);
    for (int i = 0; i < 25000; i++) fscanf(data2, "%d", p2 + i);
    selection_sort(p2, 25000);
    for (int i = 0; i < 25000; i++) fscanf(data2, "%d", p2 + i);
    for (int i = 0; i < 25000; i++) {
        if (i % 10 == 0) printf("\n");
        printf("%d  ", p2[i]);
    }
    printf("\n\n");
    insertion_sort(p2, 25000);
    

    bubble_sort(p3, 25000);
    for (int i = 0; i < 25000; i++) fscanf(data3, "%d", p3 + i);
    selection_sort(p3, 25000);
    for (int i = 0; i < 25000; i++) fscanf(data3, "%d", p3 + i);
    insertion_sort(p3, 25000);
    for (int i = 0; i < 25000; i++) {
        if (i % 10 == 0) printf("\n");
        printf("%d  ", p3[i]);
    }
    printf("\n\n");

    fclose(data1);
    fclose(data2);
    fclose(data3);
    system("pause");
    return 0;
}

void bubble_sort(int* a, int size) {
    clock_t START, END;
    START = clock();

    for (int j = 0; j < size; j++) {
        for (int i = 0; i < size - 1; i++) {
            if (a[i] >= a[i + 1]) {
                int x = a[i];
                a[i] = a[i + 1];
                a[i + 1] = x;
            }
        }
    }
    END = clock();
    printf("bubbleTime:%f\n", (float)(END - START) / CLOCKS_PER_SEC);
}

void selection_sort(int* a, int size) {
    clock_t START, END;
    START = clock();

    for (int i = 0; i < size; i++) {
        int smallest = 10000000000;
        int s;
        int ind;
        for (int j = i; j < size; j++) {
            if (a[j] <= smallest) {
                smallest = a[j];
                ind = j;
            }
        }
        s = a[i];
        a[i] = smallest;
        a[ind] = s;
    }

    END = clock();
    printf("selectionTime:%f\n", (float)(END - START) / CLOCKS_PER_SEC);
}

void insertion_sort(int* a, int size) {
    clock_t START, END;
    START = clock();

    for (int i = 1; i < size; i++) {
        int s;
        for (int j = 0; j < i; j++) {
            if (a[i] <= a[j]) {
                s = a[i];
                for (int k = i; k >= j + 1; k--) {
                    a[k] = a[k - 1];
                }
                a[j] = s;
                break;
            }
        }
    }

    END = clock();
    printf("insertionTime:%f\n", (float)(END - START) / CLOCKS_PER_SEC);

}

