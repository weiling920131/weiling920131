#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

class CALCULATE {
public:
	void add(vector<vector<int>>& complex, int i) {

		if (complex[i][0] + complex[i][2] == 0 && complex[i][1] + complex[i][3] == 0) {
			cout << 0 << endl;
		}
		else if (complex[i][0] + complex[i][2] == 0) {
			if (complex[i][1] + complex[i][3] == 1) {
				cout << 'i' << endl;
			}
			else if (complex[i][1] + complex[i][3] == -1) {
				cout << "-i" << endl;
			}
			else {
				cout << complex[i][1] + complex[i][3] << 'i' << endl;
			}
		}
		else if (complex[i][1] + complex[i][3] == 0) {
			cout << complex[i][0] + complex[i][2] << endl;
		}
		else {
			if (complex[i][1] + complex[i][3] > 0) {
				if (complex[i][1] + complex[i][3] != 1) {
					cout << complex[i][0] + complex[i][2] << '+' << complex[i][1] + complex[i][3] << 'i' << endl;
				}
				else {
					cout << complex[i][0] + complex[i][2] <<'+' << 'i' << endl;
				}
			}
			else {
				if (complex[i][1] + complex[i][3] != 1) {
					cout << complex[i][0] + complex[i][2] << complex[i][1] + complex[i][3] << 'i' << endl;
				}
				else {
					cout << complex[i][0] + complex[i][2] << "-i" << endl;
				}
			}
		}
	}

	void multi(vector<vector<int>>& complex, int i) {
		int a=0, b=0;
		a += complex[i][0] * complex[i][2] - complex[i][1] * complex[i][3];
		b += complex[i][0] * complex[i][3] + complex[i][1] * complex[i][2];
		if (a == 0 && b == 0) {
			cout << 0;
		}
		else if (a == 0) {
			if (b > 0) {
				if (b == 1) {
					cout << 'i' << endl;
				}
				else cout << b << 'i' << endl;
			}
			else {
				if (b == -1) cout << "-i" << endl;
				else cout << b << 'i' << endl;
			}
		}
		else {
			if (b > 0) {
				if (b == 1) {
					cout <<a<<'+' << 'i' << endl;
				}
				else cout <<a<<'+' << b << 'i' << endl;
			}
			else {
				if (b == -1) cout <<a<< "-i" << endl;
				else cout <<a << b << 'i' << endl;
			}
		}
	}

	void print(vector<vector<int>>& complex, int i) {
		if (complex[i][0] == 0 && complex[i][1] == 0) {
			cout << 0 << endl;
		}
		else if (complex[i][0] == 0) {
			if (complex[i][1] > 0) {
				if (complex[i][1] == 1) {
					cout << 'i' << endl;
				}
				else cout << complex[i][1] << 'i' << endl;
			}
			else {
				if (complex[i][1] == -1) {
					cout << '-' << 'i' << endl;
				}
				else cout << complex[i][1] << 'i' << endl;
			}
		}
		else if (complex[i][1] == 0) {
			cout << complex[i][0] << endl;
		}
		else {
			if (complex[i][1] > 0) {
				if (complex[i][1] != 1) {
					cout << complex[i][0] << '+' << complex[i][1] << endl;
				}
				else cout << complex[i][0] << '+' << 'i' << endl;
			}
			else {
				if (complex[i][1] != -1) {
					cout << complex[i][0] << complex[i][1] << endl;
				}
				else cout << complex[i][0] << "-i" << endl;
			}
		}
	}
};

void main() {

	CALCULATE* ops = new CALCULATE;
	int test;
	cin >> test;
	string imple;
	vector<vector<int>> complex;
	for (int i = 0; i < test; i++) {
		char ch;
		cin >> ch;
		imple = imple + ch;
		if (ch != 'p') {
			int a, b, c, d;
			cin >> a >> b >> c >> d;
			complex.push_back(vector<int>{a, b, c, d});//0,1,2,3
		}
		else {
			int a, b;
			cin >> a>>b;
			complex.push_back(vector<int>{a, b});
		}
	}
	
	for (int i = 0; i < test; i++) {
		switch (imple[i]) {
		case '*':
			ops->multi(complex, i);
			break;
		case '+':
			ops->add(complex, i);
			break;
		case 'p':
			ops->print(complex, i);
			break;
		default:
			cout << "wrong input" << endl;
		}
	}

	system("pause");
}


