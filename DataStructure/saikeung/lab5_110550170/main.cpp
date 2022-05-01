#include <iostream>
#include <fstream>
#include "Integer.h"

using namespace std;

//read the data from the file
void readFile(const char* fileName);
//void adjust(vector<int>& a, vector<int>& b);

int main()
{
	readFile("input2.txt");
	return 0;
}

void readFile(const char* fileName) {
	ifstream inputFile(fileName);

	//TODO: Read the input file here.
	char lines,tmp;
	inputFile >> lines;
	inputFile.get(tmp);

	for (size_t i = 0; i < (lines-'0'); i++)
	{
		cout << i + 1 << endl;
		char op='+';
		char check='+';
		vector<Integer> nums(2);
		for (int i = 0; i < 2; i++) {
			string num="";
			char ch;
			char first='+';
			inputFile.get(ch);
			if (i == 0 && ch == '-') {
				check = ch;
				first = ch;
			}
			else num += ch;
			while (1) {
				inputFile.get(ch);
				if (ch == '\n'||inputFile.eof()||ch==' ') {
					break;
				}
				if (ch == '+' || ch == '-') {
					op = ch;
					break;
				}
				else num += ch;
			}
			Integer tmp(num); //check
			nums.at(i) = tmp;//check
			cout << "num" << i + 1 << ": ";
			if (first == '-') cout << '-';
			cout << num << endl;
		}
		Integer answer("123");
		//TODO: Implement your add or minus

		//answer = a + b;
		//answer = a - b;
		cout << "result: ";
		if (op == '+') {
			if (check == '-') {
				answer = nums.at(1) - nums.at(0);
			}
			else {
				answer = nums.at(0) + nums.at(1);
			}
			cout << answer << endl << endl;
		}
		else {
			if (check == '-') {
				cout << "-";
				answer = nums.at(0) + nums.at(1);
			}
			else {
				answer = nums.at(0) - nums.at(1);
			}
			cout << answer << endl << endl;
		}
	}
	inputFile.close();
}