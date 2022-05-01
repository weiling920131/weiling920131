#include "role.h"
#include "magician.h"
#include "warrior.h"
#include "archer.h"
#include "staff.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;



int main() {

	// TODO : Read the file
	// 1. Read the input file to get the imformation
	ifstream input("input2.txt");
	vector<Role*> roles;/*
	vector<Warrior> warrior;
	vector<Archer> archer;
	vector<Magician> magician;*/
	int times;
	input >> times;
	for (int i = 0; i < times; i++) {
		char ch;
		string name, role;
		int level, money, hp;
		input >> name >> role >> level >> ch >> money >> ch >> hp;
		name.pop_back();
		role.pop_back();
		switch (role.at(0)) {
		case 'W': 
		{
			Role* w = new Warrior(name, level, money, hp);
			w->printAllInfo();
			w->ShowRole();
			cout << endl;
			roles.push_back(w);
			break;
		}
		case 'A': 
		{
			Role* a = new Archer(name, level, money, hp);
			a->printAllInfo();
			a->ShowRole();
			cout << endl;
			roles.push_back(a);
			break;
		}
		case 'M': 
		{
			Role* m = new Magician(name, level, money, hp);
			m->printAllInfo();
			m->ShowRole();
			cout << endl;
			roles.push_back(m);
			break; 
		}
		default:
			break;
		}
	}
	// TODO : Create the Role according to the input file
	// 1. Create the role
	// 2. Print this role's Infomation
	// 3. Show Role ( refer to spec )
	// Example :
	// -------------------------------------------------------
	// Role* warrior = new Warrior( warrior's Name, warrior's Level, warrior's Money, warrior's HP);
	// warrior->printAllInfo();
	// warrior->ShowRole();
	// cout << endl;
	// 
	// Role* archer = new Archer(archer's Name, archer's Level, archer's Money, archer's HP);
	// archer->printAllInfo();
	// archer->ShowRole();
	// cout << endl;
	// 
	// Role* magician = new Magician(magician's Name, magician's Level, magician's Money, magician's HP);
	// magician->printAllInfo();
	// magician->ShowRole();
	// cout << endl;
	// -------------------------------------------------------
	// HINT : Not necessarily just three roles


	Staff* staff = new Staff("flame");
	cout << "Checking whether the role can equip a staff.." << endl;
	for (int i = 0; i < roles.size(); i++) {
		staff->equipable(roles.at(i));
	}
	/*for (int i = 0; i < warrior.size(); i++) {
		staff->equipable(&warrior.at(i));
	}
	for (int i = 0; i < archer.size(); i++) {
		staff->equipable(&archer.at(i));
	}
	for (int i = 0; i < magician.size(); i++) {
		staff->equipable(&magician.at(i));
	}*/
	//
	// TODO : Check wheather all characters can get staff or not
	// Example :
	// -------------------------------------------------------
	// staff->equipable(warrior);
	// staff->equipable(archer);
	// staff->equipable(magician);
	// -------------------------------------------------------
	// HINT : Not necessarily just three roles
	cout << endl;



	input.close();
	system("PAUSE");
	return 0;
}