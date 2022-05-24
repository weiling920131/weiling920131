#include<iostream>
#include<vector>
#include<algorithm>
#include<fstream>

using namespace std;

void HeapSort(vector<int>& array);
void QuickSort(vector<int>& array);

void Swap(int& a, int& b) {
    int tmp = a;
    a = b;
    b = tmp;
}

void PrintArray(std::vector<int>& array) {
    for (int i = 0; i < array.size(); i++) {
        std::cout << array[i] << " ";
    }
    std::cout << std::endl;
}

int main() {
    std::fstream file;
    file.open("input1.txt");

    int times = 0;
    file >> times;

    for (int t = 0; t < times; t++) {
        int size = 0;
        file >> size;

        std::vector<int> array1;
        std::vector<int> array2;

        for (int i = 0; i < size; i++) {
            int x;
            file >> x;
            array1.push_back(x);
            array2.push_back(x);
        }

        HeapSort(array1);
        cout << "Max Heap Sort : ";
        PrintArray(array1);

        QuickSort(array2);
        cout << "Quick Sort : ";
        PrintArray(array2);
    }
    system("pause");
    return 0;
}

void HeapSort(vector<int>& array) {
    if (array.size() <= 1) return;
    for (int i = 0; i < array.size(); i++) {
        if (array[i] > array[i / 2]) {
            int ind = i;
            while (ind != 0) {
                if (array[ind] > array[ind / 2]) Swap(array[ind], array[ind / 2]);
                else break;
                ind /= 2;
            }
        }
    }
    int Max = array[0];
    vector<int>tmp;
    tmp.assign(array.begin() + 1, array.end());
    HeapSort(tmp);
    for (int i = 0; i < array.size() - 1; i++) array[i] = tmp[i];
    array[array.size() - 1] = Max;
}

void QuickSort(vector<int>& array) {
    if (array.size() <= 1) return;
    int num = array.at(0);
    int i = 0, j = array.size()-1;
    while (i < j) {
        for (j; i < j; j--) if (array[j] < num) break;
        for (i; i < j; i++) if (array[i] > num) break;
        
        if (i < j) Swap(array[i], array[j]);
    }
    if (array[0] > array[i]) Swap(array[0], array[i]);

    vector<int>tmp1,tmp2;
    if (i>1) {
        tmp1.assign(array.begin(), array.begin() + i);
        QuickSort(tmp1);
        for (int k = 0; k < i; k++) array[k] = tmp1[k];
    }
    if (i<array.size()-1) {
        tmp2.assign(array.begin() + i + 1, array.end());
        QuickSort(tmp2);
        for (int k = i + 1; k < array.size(); k++) array[k] = tmp2[k - i - 1];
    }
}



