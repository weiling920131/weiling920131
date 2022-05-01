#include<iostream>
#include<string>
#include<vector>
#include<stdlib.h>
#include<stdio.h>
#include<fstream>

using namespace std;

class VECTOR {
private:
	vector<float>num;
public:
	VECTOR(){}
	VECTOR(vector<float> nums);
	VECTOR operator+(VECTOR& b);
	VECTOR operator-(VECTOR& b);
	VECTOR operator*(float b);
	VECTOR operator^(VECTOR& b);
	friend ostream& operator << (ostream& out,VECTOR& a);
	friend istream& operator >> (istream& in, VECTOR& a);
};


