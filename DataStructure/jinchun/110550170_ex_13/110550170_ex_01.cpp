#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct  _grade {
    int Chinese, Math, English, computer_science;
}grade;

struct student {
    char name[10];
    int student_id;
    grade student_grade;
};

int main() {

    FILE* input;
    input = fopen("input.txt", "r");
    int p, a, q;
    fscanf(input, "%d%d%d", &p, &a, &q);
    int* score = (int*)calloc(q, sizeof(int));
    char** subject=(char**)calloc(q,sizeof(char*));
    char s[60];
    int** fail = (int**)calloc(q, sizeof(int*));
    for (int i = 0; i < q; i++) *(fail + i) = (int*)calloc(p, sizeof(int));
    int num0 = 0, num1 = 0, num2 = 0, num3 = 0;
    struct student* students=(student*)calloc(p,sizeof(student));
    
    printf("Input queries score:\n");
    for (int i = 0; i < q; i++) {
        *(subject + i) = (char*)calloc(5, sizeof(char));
        scanf("%s%d", subject + i, score + i);
    }
    
    for (int i = 0; i < a; i++) fscanf(input, "%s", s);
    for (int j = 0; j < p; j++) {
        fscanf(input, "%s%d", &(*(students + j)).name, &(*(students + j)).student_id);
        fscanf(input, "%d%d%d%d", &(*(students + j)).student_grade.Chinese, &(*(students + j)).student_grade.Math, &(*(students + j)).student_grade.English, &(*(students + j)).student_grade.computer_science);
        if (((*(students + j)).student_grade.Chinese) < *(score + 0)) {
            *(*(fail + 0) + num0) = (*(students + j)).student_id;
            num0++;
        }
        if (((*(students + j)).student_grade.Math) < *(score + 1)) {
            *(*(fail + 1) + num1) = (*(students + j)).student_id;
            num1++;
        }
        if (((*(students + j)).student_grade.English) < *(score + 2)) {
            *(*(fail + 2) + num2) = (*(students + j)).student_id;
            num2++;
        }
        if (((*(students + j)).student_grade.computer_science) < *(score + 3)) {
            *(*(fail + 3) + num3) = (*(students + j)).student_id;
            num3++;
        }
    }
    
    printf("Result:\n");
    printf("Chinese :");
    for (int i = 0; i < num0; i++) printf("%d ", *(*(fail + 0) + i));
    printf("\n");
    printf("Math :");
    for (int i = 0; i < num1; i++) printf("%d ", *(*(fail + 1) + i));
    printf("\n");
    printf("English :");
    for (int i = 0; i < num2; i++) printf("%d ", *(*(fail + 2) + i));
    printf("\n");
    printf("Computer_Science :");
    for (int i = 0; i < num3; i++) printf("%d ", *(*(fail + 3) + i));
    printf("\n");

    fclose(input);
    system("pause");
    return 0;
}







