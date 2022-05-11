#pragma once
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<fstream>

using namespace std;

struct queue {
	int val;
	queue* back = NULL;
};

class QUEUE {
private:
	queue* start;
public:
	QUEUE() {
		start = NULL;
	}
	~QUEUE() {}
	void enqueue(int num);
	void dequeue();
	void print();
};