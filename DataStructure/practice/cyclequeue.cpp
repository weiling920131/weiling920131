#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>



int main() {

    int max;
    printf("size: ");
    scanf("%d", &max);
    int* queue = (int*)calloc(max, sizeof(int));
    int choice = 0;
    int front = -1, rear = -1;
    while (choice != -1) {
        printf("-1:quit 1:add 0:leave\n");
        scanf("%d", &choice);
        if (choice == 1) {
            if (front == rear + 1 || (front == -1 && rear == max - 1)) {
                printf("full\n");
            }
            else {
                int num;
                printf("num: ");
                scanf("%d", &num);
                rear++;
                rear = (rear) % max;
                queue[rear] = num;
            }
        }
        else if (choice == 0) {
            if (front >= rear) {
                printf("empty\n");
            }
            else {
                front++;
                printf("%d leave\n", queue[front]);
            }
        }
    }
    printf("\n");
    while (front != rear) {
        front++;
        front = (front) % max;
        printf("%d\n", queue[front]);
    }


    system("pause");
    return 0;
}




