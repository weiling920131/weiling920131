#pragma once
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<fstream>

using namespace std;

struct stack {
	int val;
	stack* above = NULL;
};

class STACK {
private:
	stack* bottom;
public:
	STACK() {
		bottom = NULL;
	}
	~STACK(){}
	void push(int num);
	void pop();
	void print();
};