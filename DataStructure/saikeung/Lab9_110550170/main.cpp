#include"queue.h"
#include"stack.h"

int main() {
	ifstream input("input1.txt");
	int times;
	input >> times;
	for (int i = 0; i < times; i++) {
		char c;
		input >> c;
		if (c == 'S' || c == 's') {
			STACK stack;
			string func;
			char ch;
			int n;
			input >> n;
			for (int j = 0; j < n; j++) {
				input >> func;
				switch (func.at(func.size() - 1)) {
				case'h':
					int num;
					input >> num;
					stack.push(num);
					break;
				case'p':
					stack.pop();
					break;
				case't':
					stack.print();
					break;
				default:
					break;
				}
			}
		}
		else if (c == 'Q' || c == 'q') {
			QUEUE queue;
			string func;
			char ch;
			int n;
			input >> n;
			for (int j = 0; j < n; j++) {
				input >> func;
				switch (func.at(0)) {
				case'e':
					int num;
					input >> num;
					queue.enqueue(num);
					break;
				case'd':
					queue.dequeue();
					break;
				case'p':
					queue.print();
					break;
				default:
					break;
				}
			}
		}
	}
	input.close();
	return 0;
}