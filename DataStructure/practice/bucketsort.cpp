#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;
void printvector(const vector<int>& v);
void bucketsort(vector<int>& v, int digit);
void insertion(vector<int>& v);
int finddigit(vector<int>& v);

void printvector(const vector<int>& v) {
	for (int j = 0; j < v.size(); j++) cout << v.at(j) << " ";
	cout << endl;
}

void bucketsort(vector<int>& v, int digit) {
	if (v.size() > 1) {
		for (int i = 0; i < digit; i++) {
			int ind = 0;
			vector<vector<int>> tmp(10);
			for (int j = 0; j < v.size(); j++) {
				string num = to_string(v.at(j));
				reverse(num.begin(), num.end());//數字後面要補0所以先倒轉

				if (num.size() > i) tmp.at(num.at(i) - '0').push_back(v.at(j));
				else tmp.at(0).push_back(v.at(j));
			}
			for (int j = 0; j < 10; j++) {
				insertion(tmp.at(j));
				for (int k = 0; k < tmp.at(j).size(); k++) v.at(ind++) = tmp.at(j).at(k);
			}
		}
	}
}

int finddigit(vector<int>& v) {
	int max = 0;
	int maxdigit = 0;
	int i = 0;
	while (i < v.size()) {
		if (max < v.at(i)) max = v.at(i);
		i++;
	}

	string tmp = to_string(max);
	return tmp.size();
}


void insertion(vector<int>& v) {
	for (int i = 1; i < v.size(); i++) {
		for (int j = 0; j < i; j++) {
			if (v[i] < v[j]) {
				int tmp = v[i];
				for (int k = i; k > j; k--) {
				v[k] = v[k - 1];
				}
				v[j] = tmp;
			}
		}
	}
}

int main() {
	
	vector<int> v = { 100,2022,44,85,76,45,16,31,753,9,100 };
	//insertion(v);
	bucketsort(v, finddigit(v));
	printvector(v);
	system("pause");
	return 0;
}




