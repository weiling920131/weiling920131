#include "DateCalculator.h"

using namespace std;

DateCalculator::DateCalculator():year(2000),month(1),day(1), changeDays(0){}


void DateCalculator::readFile(const char *fileName) {
	//TODO:
	//Read the data from the txt file.
	//The file is in the Lab4_template/Lab4.
	// 
	//Hint: You can use get() to get a character in ifstream.
	//      You can use getline() to get one line in the txt file.
	//      You can use atoi() or stoi() to change variable type from string to int
	times = 1;
	this->fileName = fileName;
	ifstream input(fileName);
	while (!input.eof()) {
		char op, slash;
		input >> op >> this->year >> slash >> this->month >> slash >> this->day >> this->changeDays;
		if (op == '+') {
			add();
		}
		else minus();
	}
	output << endl;
	input.close();
}

void DateCalculator::add() {//建表
	//TODO:
	//Calculate the date add the changeDays.
	//int month = this->month, year = this->year, day = this->day, 
	int change = this->changeDays;
	change += day;
	while (1) {
		if (month >= 13) {
			year += 1;
			month = 1;
		}
		if (month >= 8) {
			if (!(month % 2)) {
				if (change > 31) {
					month += 1;
					change -= 31;
				}
				else {
					day = change;
					break;
				}
			}
			else {
				if (change > 30) {
					month += 1;
					change -= 30;
				}
				else {
					day = change;
					break;
				}
			}
		}
		else {
			if (month == 2) {
				if (change > (this->isLeapYear(year)?29:28)) {
					month += 1;
					change -= (this->isLeapYear(year) ? 29 : 28);
				}
				else {
					day = change;
					break;
				}
			}
			else if (!(month % 2)) {
				if (change > 30) {
					month += 1;
					change -= 30;
				}
				else {
					day = change;
					break;
				}
			}
			else {
				if (change > 31) {
					month += 1;
					change -= 31;
				}
				else {
					day = change;
					break;
				}
			}
		}
	}
	this->day = day;
	this->month = month;
	this->year = year;
	this->showDay();
}

void DateCalculator::minus() {
	//TODO:
	//Calculate the date minus the changeDays.
	int month = this->month, year = this->year, day = this->day, change = this->changeDays;
	if (day > change) {
		day -= change;
		if (day == 0) {
			month -= 1;
			if (!month) {
				year--;
				month = 12;
			}
		}
	}
	else {
		change -= day;
		month -= 1;
		while (1) {
			if (month <= 0) {
				year -= 1;
				month = 12;
			}
			if (month >= 8) {
				if (!(month % 2)) {
					if (change >= 31) {
						month -= 1;
						change -= 31;
					}
					else {
						day = 31 - change;
						break;
					}
				}
				else {
					if (change >= 30) {
						month -= 1;
						change -= 30;
					}
					else {
						day = 30 - change;
						break;
					}
				}
			}
			else {
				if (month == 2) {
					if (change > (this->isLeapYear(year) ? 29 : 28)) {
						month -= 1;
						change -= (this->isLeapYear(year) ? 29 : 28);
					}
					else {
						day = (this->isLeapYear(year) ? 29 : 28) - change;
						break;
					}
				}
				else if (!(month % 2)) {
					if (change >= 30) {
						month -= 1;
						change -= 30;
					}
					else {
						day = 30 - change;
						break;
					}
				}
				else {
					if (change >= 31) {
						month -= 1;
						change -= 31;
					}
					else {
						day = 31 - change;
						break;
					}
				}
			}
		}
	}
	this->day = day;
	this->month = month;
	this->year = year;
	this->showDay();
}

bool DateCalculator::isLeapYear(int year_) {
	//TODO: 
	//Determine whether year_ is a leap year.
	bool check = false;
	if (year_ % 4 == 0) check = true;
	if (year_ % 100 == 0) check = false;
	if (year_ % 400 == 0) check = true;

	return check;
}

void DateCalculator::showDay() {
	//TODO: 
	//The function output the date on the screen.
	//Hint: You can use setw() to set the length of the number.
	//      You can use setfill('c') to fill 'c' to the empty space.
	//      Two functions of above is in iomanip header file.
	if (times == 1) output << "output of " << this->fileName << endl; 
	times++;
	output << year << '/' << setfill('0') << setw(2) << month << '/' << setfill('0') << setw(2) << day << endl;

}



