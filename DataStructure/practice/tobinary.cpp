#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
	int num = 655491;
	while (num / 9>=1) {
		// if (num % 2 == 0) cout << "0";
		// else cout << "1";
		cout<<num%9;
		num /= 9;
	}
	cout<<num%9;
}
	

	



