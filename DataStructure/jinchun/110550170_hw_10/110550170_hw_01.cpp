#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void movement(int num, char A, char B, char C);


int main() {
	while (1) {
		int num;
		printf("Input the number of disks: \n");
		scanf("%d", &num);

		if (num == 0) printf("No movement.\n");
		else movement(num, 'A', 'B', 'C');

		printf("\n");
	}

	system("pause");
	return 0;
}

void movement(int num, char A, char B, char C) {
	if (num >= 1) {
		movement(num - 1, A, C, B);
		printf("Move disk %d from %c to %c\n", num, A, C);
		movement(num - 1, B, A, C);
	}
}







