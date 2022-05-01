#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;

class DateCalculator {
private:
	string fileName;
	int year;
	int month;
	int day;
	int changeDays;
	int times = 1;
	//ofstream output;
	//You can add any variable if you need.
public:
	ofstream output;
	DateCalculator();
	void readFile(const char *filename);
	void add();
	void minus();
	bool isLeapYear(int year_);
	void showDay();
	//You can add any function if you need.
};