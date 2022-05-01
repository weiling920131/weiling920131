#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>

struct node {
    int value, left_thread = 1, right_thread = 1;
    node* right_node = NULL;
    node* left_node = NULL;
};
node* root = NULL;

void build(int);
void trace();

int main() {
    int data[] = { 99999999,10,20,30,100,399,453,43,237,373,655 };
    for (int i = 0; i < 11; i++) {
        build(data[i]);
    }
    trace();

    system("pause");
    return 0;
}


void build(int value) {
    node* ans = new node;
    ans->value = value;
    if (root == NULL) {
        root = ans;
        root->left_node = new node;
        root->right_node = root;
        root->left_thread = 1;
        root->right_thread = 0;
    }
    else {
        node* tmp = root;
        node* precious = root;
        node* next = root;
        while (1) {
            if (tmp->value > value) {
                if (tmp->left_thread == 1) {
                    tmp->left_thread = 0;
                    tmp->left_node = ans;
                    next = tmp;
                    break;
                }
                next = tmp;
                tmp = tmp->left_node;
            }
            else {
                if (tmp->right_thread == 1) {
                    tmp->right_thread = 0;
                    tmp->right_node = ans;
                    precious = tmp;
                    break;
                }
                precious = tmp;
                tmp = tmp->right_node;
            }
        }
        ans->right_node = next;
        ans->left_node = precious;
    }
}

void trace() {
    node* ans = root;
    do {
        if (ans->right_thread == 0) {
            ans = ans->right_node;
            while (ans->left_thread != 1) {
                ans = ans->left_node;
            }
        }
        else ans = ans->right_node;

        if (ans != root) printf("%d\n", ans->value);

    } while (ans != root);
}













