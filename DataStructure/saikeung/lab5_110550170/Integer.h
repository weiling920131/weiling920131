#ifndef INTEGER_H
#define INTEGER_H 

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Integer
{
private:
	vector<int> num;  //store the number
public:
	//constructor
	Integer(string number);	//default constructor
	Integer();
	char check='+';
	//operation overload 
	Integer operator +(const Integer& c);
	Integer operator -(const Integer& c);

	//output overload
	friend ostream& operator << (ostream& out, const Integer& i);
};
#endif