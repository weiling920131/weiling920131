#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

double callback_execution(double* params, double(**callbacks)(double, double), int nums_of_callbacks);
double add(double a, double b);
double substract(double a, double b);
double multiply(double a, double b);
double divide(double a, double b);

int main() {

    int quit;
    typedef double (f_pointer_array)(double, double);
    f_pointer_array** callbacks = (f_pointer_array**)calloc(1000, sizeof(f_pointer_array*));

    while (1) {
        printf("Enter whether to continue or quit(1,0):");
        scanf("%d", &quit);
        if (quit == 1) {
            int i = 0;
            double* num = (double*)calloc(1000, sizeof(double));
            while (1) {
                char ar;
                printf("%d Enter parameter and function code(+,-,*,/): ",i);
                scanf("%lf %c", num + i, &ar);
                if (ar == 'q') break;
                else if (ar == '+') {
                    *(callbacks + i) = add;
                    i++;
                }
                else if (ar == '-') {
                    *(callbacks + i) = substract;
                    i++;
                }
                else if (ar == '*') {
                    *(callbacks + i) = multiply;
                    i++;
                }
                else if (ar == '/') {
                    *(callbacks + i) = divide;
                    i++;
                }
            }
            printf("Final result: %lf\n", callback_execution(num, callbacks, i));
        }
        else break;
    }
    system("pause");
    return 0;
}

double callback_execution(double* params, double(**callbacks)(double, double), int nums_of_callbacks) {
    double ans = *params;
    for (int j = 0; j < nums_of_callbacks; j++) 
        ans = (*(callbacks + j))(ans, *(params + j+1));
    return ans;
}

double add(double a, double b) {
    return a + b;
}

double substract(double a, double b) {
    return a - b;
}

double multiply(double a, double b) {
    return a * b;
}

double divide(double a, double b) {
    return a / b;
}






