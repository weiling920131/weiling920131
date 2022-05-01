#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

struct node {
    int id;
    int money;
    node* next = NULL;
}list;

node* end, * h, * t;

void Join(int id, int money);
void Insert(int id, int money, int position);
void Leave(int position);

int main() {

    FILE* input;
    input = fopen("input.txt", "r");

    int n;
    char s[20];
    fscanf(input, "%d", &n);
    for(int i=0;i<4;i++) fscanf(input, "%s", &s);

    for (int i = 0; i < n; i++) {
        int size, id, money, position;
        fscanf(input, "%d", &size);
        switch (size) {
        case 1:
            fscanf(input, "%d", &position);
            Leave(position);
            break;

        case 2:
            fscanf(input, "%d%d", &id, &money);
            Join(id, money);
            if (i == 0) h = end;
            else t->next = end;
            t = end;
            break;
            

        case 3:
            fscanf(input, "%d%d%d", &id, &money, &position);
            Insert(id, money, position);
            break;
        default:
            printf("wrong input\n"); break;
        }
    }
    
    t = h;
    while (t != NULL) {
        printf("ID money : ");
        printf("%d %d\n", t->id, t->money);
        t = t->next;
    }

    fclose(input);
    system("pause");
    return 0;
}


void Join(int id, int money) {
    end = new node;
    end->id = id;
    end->money = money;
}
void Insert(int id, int money, int position) {
    node* left = h, *right = h;
    node* middle = new node;
    for (int i = 0; i < position; i++) {
        if (i < (position - 1)) left = left->next;
        right = right->next;
    }
    middle->id = id;
    middle->money = money;
    middle->next = right;
    left->next = middle;
}
void Leave(int position) {
    node* left = h, * right = h;
    node* middle = new node;
    for (int i = 0; i <= position; i++) {
        if (i < position -1) left = left->next;
        right = right->next;
    }
    left->next = right;
}