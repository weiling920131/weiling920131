#pragma once
#ifndef ROLE_H
#include <string>
using namespace std;
class Role {
public:
	Role(string, int, int, int);
	string getID();
	void printAllInfo();
	void virtual ShowRole() = 0;

private:
	string ID;
	int level;
	int money;
	int hp;

};
#endif