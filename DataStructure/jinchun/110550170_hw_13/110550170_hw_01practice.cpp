#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

struct node {
    int id;
    int money;
    node* next = NULL;
};

void join(int id, int money);
void insert(int id, int money,int position);
void leave(int position);

int num = 0;
node* end, * h, * t;

int main() {

    FILE* input;
    input = fopen("input.txt", "r");
    int line;
    fscanf(input, "%d", &line);
    char ch[10];
    for (int i = 0; i < 4; i++) {
        fscanf(input, "%s", ch);
    }

    for (int i = 0; i < line; i++) {
        int size, id, money, position;
        fscanf(input, "%d", &size);
        if (size == 2) {
            fscanf(input, "%d%d", &id, &money);
            join(id, money);
        }
        else if (size == 1) {
            fscanf(input, "%d", &position);
            leave(position);
        }
        else {
            fscanf(input, "%d%d%d", &id, &money, &position);
            insert(id, money, position);
        }
    }
    while (h != NULL) {
        printf("ID money : %d %d\n", h->id, h->money);
        h = h->next;
    }


    fclose(input);
    system("pause");
    return 0;
}

void join(int id, int money) {
    end = new node;
    end->id = id;
    end->money = money;

    if (num == 0) {
        h = end;
    }
    else {
        t->next = end;
    }
    t = end;
    num++;
}

void insert(int id, int money, int position) {
    node* left = h, * right = h;
    node* mid = new node;
    mid->id = id;
    mid->money = money;

    if (position == 1) {
        right = h->next;
        h->next = mid;
        mid->next = right;
    }
    else {
        for (int i = 1; i < position; i++) {
            left = left->next;
            right = right->next;
        }
        right = right->next;
        right = right->next;

        left->next = mid;
        mid->next = right;
    }
    num++;
}

void leave(int position) {
    node* left = h, * right = h;

    if (position == 1) {
        h = h->next;
    }
    else {
        for (int i = 1; i < position; i++) {
            left = left->next;
            right = right->next;
        }
        right = right->next;
        right = right->next;

        left->next = right;
    }
    num--;
}
