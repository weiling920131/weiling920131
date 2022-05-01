#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int Sum(int a[], int n, int sum);

int main() {

	int n;
	char ch;
	int ind = 0;
	int a[11];
	
	printf("Please input an array(size less than 10): ");
	do {
		scanf("%d", &a[ind]);
		ind++;
		scanf("%c", &ch);
	} while (ch != '\n');

	printf("How many elements to sum from head: ");
	scanf("%d", &n);

	if (n > ind) printf("Out of range.\n");
	else printf("The summation is %d.\n", Sum(a, n, 0));
	
	system("pause");
	return 0;
}

int Sum(int a[], int n, int sum) {
	if (n != 0) {
		return Sum(a, n - 1, sum+a[n-1]);
	}
	else return sum;
}
