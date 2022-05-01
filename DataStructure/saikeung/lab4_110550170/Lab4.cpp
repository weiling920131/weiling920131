#include <iostream>
#include "DateCalculator.h"
using namespace std;


int main() {
	DateCalculator calculator;
	calculator.output.open("output.txt");
	calculator.readFile("input1.txt");
	calculator.readFile("input2.txt");
	calculator.output.close();
	return 0;
}