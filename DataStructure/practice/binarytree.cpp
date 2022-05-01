#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>

void bulidtree(int btree[], int data[], int length);

int main() {

    int length;
    printf("data range: ");
    scanf("%d", &length);
    int* data = (int*)calloc(length, sizeof(int));
    for (int i = 0; i < length; i++) {
        scanf("%d", &data[i]);
    }
    printf("\n");

    int level = 0;
    while (pow(2, level) - 1 < length) level++;//need to be revised
    int* btree = (int*)calloc(pow(2, level), sizeof(int));
    bulidtree(btree, data, length);
    
    printf("tree:\n");
    for (int i = 1; i < 16; i++) {
        printf("%d ", btree[i]);
    }
    printf("\n");

    system("pause");
    return 0;
}
void bulidtree(int btree[], int data[], int length) {
    int ind;
    for (int i = 0; i < length; i++) {
        for (ind = 1; btree[ind] != 0;) {
            if (data[i] > btree[ind]) ind = ind * 2 + 1;
            else ind = ind * 2;
        }
        btree[ind] = data[i];
    }
}






