#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

void quicksort(int* arr, int left, int right) {
	if (left >= 0 && right <= 8 && (right - left) > 0) {
		int i = left, j = right;
		while (i < j) {
			while (arr[i] < arr[left] && i < j) i++;
			while (arr[j] >= arr[left] && i < j) j--;
			
			
			if (i < j) {
				int tmp = arr[i];
				arr[i] = arr[j];
				arr[j] = tmp;
			}
		}
		int tmp = arr[i];
		arr[i] = arr[left];
		arr[left] = tmp;
		for (int i = 0; i < 9; i++) cout << arr[i] << " ";
		cout << endl;
		quicksort(arr, left, i - 1);
		quicksort(arr, i + 1, right);
	}
}

void main() {
	int arr[] = { 2,8,1,4,7,5,3,6,9 };
	quicksort(arr, 0, 8);
	for (int i = 0; i < 9; i++) cout << arr[i] << " ";
	cout << endl;
}




