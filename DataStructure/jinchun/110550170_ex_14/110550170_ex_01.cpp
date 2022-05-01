#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "matrix.h"
#include "vector.h"



int main() {
    
    int ra, ca, rb, cb, numa, numb;
    scanf("%d%d%d%d%d%d", &ra, &ca, &rb, &cb, &numa, &numb);

    matrix2D* Amat = matrix2D_construct(ra, ca);
    matrix2D_fillwith(Amat, numa);

    matrix2D* Bmat = matrix2D_construct(rb, cb);
    matrix2D_fillwith(Bmat, numb);

    matrix2D* ans = matrix2D_multiple(Amat, Bmat);
    if (ans != NULL) {
        for (int i = 0; i < ra; i++) {
            for (int j = 0; j < cb; j++) {
                printf("%d ", *((ans->mat + i)->vec + j));
            }
            printf("\n");
        }
    }
    system("pause");
    return 0;
}




