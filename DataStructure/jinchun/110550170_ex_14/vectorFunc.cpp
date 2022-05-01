#include "vector.h"
#include <stdlib.h>


vector* vector_construct(int length) {
	vector* a = new vector;
	a->length = length;
	a->vec = (int*)calloc(length, sizeof(int));
	return a;
}