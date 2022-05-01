#include "Integer.h"

Integer::Integer() {

}

Integer::Integer(string number)
{
	//TODO: read the string and construct the huge integer
	for (int i = 0; i < number.size(); i++) {
		char ch = number[i];
		switch (ch) {
		case 'a':
			this->num.push_back(10);
			break;
		case 'b':
			this->num.push_back(11);
			break;
		case 'c':
			this->num.push_back(12);
			break;
		case 'd':
			this->num.push_back(13);
			break;
		case 'e':
			this->num.push_back(14);
			break;
		case 'f':
			this->num.push_back(15);
			break;
		default:
			this->num.push_back((int)(ch-'0'));
			break;
		}
	}
}



Integer Integer::operator +(const Integer& c) {
	//TODO: perform + opearion overloading
	auto a = num, b = c.num;

	vector<int> tmp1;
	for (int i = a.size() - 1; i >= 0; i--) {
		tmp1.push_back(a.at(i));
	}
	a=tmp1;
	vector<int> tmp2(b.size());
	for (int i = b.size() - 1; i >= 0; i--) {
		tmp2.at(b.size() - 1-i)=b.at(i);
	}
	b = tmp2;

	int i;
	Integer tmp;
	int min = a.size() < b.size() ? a.size() : b.size();
	for (i = 0; i < min; i++) {
		tmp.num.push_back(a[i] + b[i]);
	}

	if (min == a.size() && a.size() != b.size()) {
		for (i; i < b.size(); i++) {
			tmp.num.push_back(b.at(i));
		}
	}
	else if(min == b.size() && a.size() != b.size()){
		for (i; i < a.size(); i++) {
			tmp.num.push_back(a.at(i));
		}
	}
	tmp.num.push_back(0);
	for (int i = 0; i < tmp.num.size()-1 ; i++) {
		tmp.num[i + 1] += (tmp.num[i] / 16);
		tmp.num[i] %= 16;
	}
	
	return tmp;
}
Integer Integer::operator -(const Integer& c) {
	//TODO: perform - opearion overloading
	auto a = this->num, b = c.num;

	vector<int> tmp1;
	for (int i = a.size() - 1; i >= 0; i--) {
		tmp1.push_back(a.at(i));
	}
	a = tmp1;
	vector<int> tmp2;
	for (int i = b.size() - 1; i >= 0; i--) {
		tmp2.push_back(b.at(i));
	}
	b = tmp2;

	int i;
	Integer tmp;
	int min = a.size() < b.size() ? a.size() : b.size();
	for (i = 0; i < min; i++) {
		tmp.num.push_back(a.at(i) - b.at(i));
	}

	if (min == a.size() && a.size() != b.size()) {
		for (i; i < b.size(); i++) {
			tmp.num.push_back(-b.at(i));
		}
	}
	else if (min == b.size() && a.size() != b.size()) {
		for (i; i < a.size(); i++) {
			tmp.num.push_back(a.at(i));
		}
	}

	tmp.num.push_back(0);
	for (int i = 0; i < tmp.num.size() - 1; i++) {
		if (tmp.num[i] < 0) {
			tmp.num[i] += 16;
			tmp.num[i + 1] -= 1;
		}
	}
	if (tmp.num.at(tmp.num.size() - 1) == -1) {
		tmp.check = '-';
		for (int i = 0; i < tmp.num.size() - 1; i++) {
			if(i==0) tmp.num.at(i) = 16 - tmp.num.at(i);
			else tmp.num.at(i) = 15 - tmp.num.at(i);
		}
		tmp.num[size(tmp.num) - 1] = 0;
		cout << '-';
	}
	return tmp;
}

ostream& operator << (ostream& out, const Integer& i) {
	//TODO: perform output overloading
	int test = 0;
	for (int j = i.num.size() - 1; j >= 0; j--) {
		if (test == 0 && i.num[j] == 0) continue;
		else {
			test = 1;
			if (i.check == '-') cout << '-';
			if (i.num.at(j) > 9 && i.num.at(j) < 16) {
				cout << (char)(i.num.at(j) - 10 + 'a');
			}
			else if (i.num.at(j) <= 9 && i.num.at(j) >= 0) cout << i.num.at(j);
		}
	}
	if (!test) cout << 0;
	return out;
}



