#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void merge_sort(int a[], int left, int right);
void merge(int a[], int left, int right);
int ans[25000];


int main() {
    int time = 0;
    int a123[10] = { 9,8,7,6,5,4,3,2,1,0 };
    merge_sort(a123, 0, 9);
    for (int i = 0; i < 10; i++) {
        if (time % 10 == 0) printf("\n");
        printf("%4d", a123[i]);
        time++;
    }
    printf("\n");
    system("pause");
    return 0;
}


void merge_sort(int a[], int left, int right) {
    if (left < right) {
        merge_sort(a, left, (right + left) / 2);
        merge_sort(a, (right + left) / 2 + 1, right);
        merge(a, left, right);
    }
}


void merge(int a[], int left, int right) {
    int mid = (left + right) / 2;
    int l = left, r = mid + 1;
    int i = 0;
    while (l <= mid && r <= right) {
        if (a[l] <= a[r]) {
            ans[left + i] = a[l];
            l++;
        }
        else {
            ans[left + i] = a[r];
            r++;
        }
        i++;
    }

    if (l > mid) {
        for (r; r <= right; r++) {
            ans[left + i] = a[r];
            i++;
        }
    }
    else {
        for (l; l <= mid; l++) {
            ans[left + i] = a[l];
            i++;
        }
    }

    for (int j = 0; j < i; j++) {
        a[left + j] = ans[left + j];
        printf("%d ", a[left + j]);
    }
    printf("\n");
}