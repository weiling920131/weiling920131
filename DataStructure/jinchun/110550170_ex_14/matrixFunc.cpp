#include "matrix.h"
#include "vector.h"
#include <stdlib.h>
#include <stdio.h>

// to construct the matrix by given row and column
matrix2D* matrix2D_construct(int m, int n) {
	matrix2D* a = new matrix2D;
	a->row = m;
	a->column = n;
	a->mat = (vector*)malloc(m * sizeof(vector));
	for (int i = 0; i < m; i++) *(a->mat + i) = *vector_construct(n);

	return a;
}

// fill the matrix with specific number
void matrix2D_fillwith(matrix2D* A, int num) {
	for (int i = 0; i < A->row; i++) {
		for (int j = 0; j < A->column; j++) {
			*((A->mat + i)->vec + j) = num;
		}
	}
}

// check 2 matrix with the right shape, if they can multiple together, return the result, or print shape error
matrix2D* matrix2D_multiple(matrix2D* A, matrix2D* B) {
	matrix2D* ans = matrix2D_construct(A->row, B->column);
	if (A->column == B->row) {
		for (int i = 0; i < A->row; i++) {
			for (int j = 0; j < B->column; j++) {
				for (int k = 0; k < B->row; k++) {
					*((ans->mat + i)->vec + j) += *((A->mat + i)->vec + k) * *((B->mat + k)->vec + j);
				}
			}
		}
		return ans;
	}
	else {
		printf("shape error\n");
		return NULL;
	}

}
