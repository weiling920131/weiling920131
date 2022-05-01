#include"class.h"

int main() {
	int n;
	char op;
	ifstream input("input1.txt");
	input >> n;

	for (int i = 0; i < n; i++) {
		float con;
		input >> op;
		vector<VECTOR> nums(2);
		VECTOR answer;

		for (int i = 0; i < 2; i++) {
			if (op == '*' && i == 1) {
				input >> con;
				break;
			}
			vector<float> tmp;
			int dim;
			input >> dim;
			for (int i = 0; i < dim; i++) {
				float num;
				input >> num;
				tmp.push_back(num);
			}
			
			VECTOR a(tmp);
			nums.at(i) = a;
		}

		switch (op) {
		case '+':
			answer = nums.at(0) + nums.at(1);
			break;
		case '-':
			answer = nums.at(0) - nums.at(1);
			break;
		case '*':
			answer = nums.at(0) * con;
			break;
		case '^':
			answer = nums.at(0) ^ nums.at(1);
			break;
		default:
			break;
		}
		cout << answer;
	}

	input.close();
	system("pause");
	return 0;
}

