#include "class.h"

//VECTOR::VECTOR() {}



VECTOR::VECTOR(vector<float> nums) {
	this->num = nums;
}

VECTOR VECTOR::operator + (VECTOR& b) {
	VECTOR answer;
	auto a = num, c = b.num;
	for (int i = 0; i < a.size(); i++) answer.num.push_back(a.at(i) + c.at(i));
	return answer;
}

VECTOR VECTOR::operator - (VECTOR& b) {
	VECTOR answer;
	auto a = num, c = b.num;
	for (int i = 0; i < a.size(); i++) answer.num.push_back(a.at(i) - c.at(i));
	return answer;
}

VECTOR VECTOR::operator * (float b) {
	VECTOR answer;
	auto a = num;
	for (int i = 0; i < a.size(); i++) answer.num.push_back(a.at(i) * b);
	return answer;
}

VECTOR VECTOR::operator ^ (VECTOR& b) {
	VECTOR answer;
	auto a = num, c = b.num;
	for (int i = 0; i < a.size(); i++) answer.num.push_back(a.at(i) * c.at(i));
	return answer;
}

ostream& operator<<(ostream& out, VECTOR& b) {
	cout << '(';
	for (int i = 0; i < b.num.size(); i++) {
		cout << b.num.at(i);
		if (i != b.num.size() - 1) cout << ',';
	}
	cout << ')' << endl;
	return out;
}

istream& operator>>(istream& in, VECTOR& b) {
	float tmp;
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> tmp;
		b.num.push_back(tmp);
	}
	return in;
}
