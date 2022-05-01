#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

class PrimeFactorization {
private:
	int num1,n1,n2, num2, n, max = 1;
	vector<int> num1_factor, num2_factor;
	vector<int> prime;

public:
	PrimeFactorization() {
		//TO_DO: initial constructor
	}
	PrimeFactorization(int _a, int _b) {
		//TO_DO: _a means the first integer and _b means the second integer
		this->num1 = _a;
		n1 = _a;
		this->num2 = _b;
		n2 = _b;
	}
	void Get_Prime_Factorization() {
		//TO_DO: Prime factorization num1 and num2, push result to the num1_factor and num2_factor.
		n = num1 > num2 ? num1 : num2;
		prime.push_back(2);
		//num1
		int cnt = 0;
		int i = 2;
		while (num1 != 1) {
			if (num1 % prime[cnt] == 0) {
				num1_factor.push_back(prime[cnt]);
				num1 = num1 / prime[cnt];
				continue;
			}
			cnt++;
			while (1) {
				int check = 1;
				for (int j = 0; j < prime.size(); j++) {
					if (i % prime[j] == 0) {
						check = 0;
						break;
					}
				}
				if (check) {
					prime.push_back(i);
					break;
				}
				i++;
			}
		}
		//num2
		cnt = 0;
		while (num2 != 1 ) {
			if (num2 % prime[cnt] == 0) {
				num2_factor.push_back(prime[cnt]);
				num2 = num2 / prime[cnt];
				continue;
			}
			cnt++;
			while (1) {
				int check = 1;
				for (int j = 0; j < prime.size(); j++) {
					if (i % prime[j] == 0) {
						check = 0;
						break;
					}
				}
				if (check) {
					prime.push_back(i);
					break;
				}
				i++;
			}
		}
	}

	void Print_Prime_Factorization() {
		//TO_DO: Print num1_factor and num2_factor.
		cout << "num1_Prime_factor:\" ";
		for (int i = 0; i < num1_factor.size(); i++) {
			cout << num1_factor[i] << " ";
		}
		cout <<"\""<< endl;
		cout << "num2_Prime_factor:\" ";
		for (int i = 0; i < num2_factor.size(); i++) {
			cout << num2_factor[i] << " ";
		}
		cout <<"\""<< endl;
	}

	void Print_GCD() {
		//TO_DO: Use num1_factor and num2_factor to find GCD and print the result.
		cout << "GCD:";
		int cnt1 = 0, cnt2 = 0;
		while (cnt1 < num1_factor.size() && cnt2 < num2_factor.size()) {
			if (num1_factor[cnt1] == num2_factor[cnt2]) {
				max *= num1_factor[cnt1];
				cnt1++;
				cnt2++;
			}
			else if (num1_factor[cnt1] < num2_factor[cnt2]) cnt1++;
			else cnt2++;
		}
		cout << max << endl;
	}

	void Print_LCM() {
		//TO_DO: Use num1, num2, and GCD to find LCM and print the result.
		cout << "LCM:"<<(long long)n1/max*n2<<endl;
	}

};

int main() {
	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		int a, b;
		cin >> a >> b;

		cout << "num1 = " << a << endl;
		cout << "num2 = " << b << endl;

		PrimeFactorization PF(a, b);

		PF.Get_Prime_Factorization();
		PF.Print_Prime_Factorization();
		PF.Print_GCD();
		PF.Print_LCM();

		cout << endl;

	}

	system("PAUSE");
	return 0;
}




