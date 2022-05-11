#include"queue.h"

void QUEUE::enqueue(int num) {
	queue* tmp = new queue;
	tmp->val = num;
	if (!start) {
		start = tmp;
		return;
	}

	queue* last = start;
	while (last->back) last = last->back;
	last->back = tmp;
}

void QUEUE::dequeue() {
	if (!start) return;
	
	queue* tmp = start->back;
	delete start;
	start = tmp;
}

void QUEUE::print() {
	cout << "The values in the queue :";
	if (!start) {
		cout << endl;
		return;
	}
	queue* top = start;
	vector<int> num;
	while ((top->back)) {
		num.push_back(top->val);
		top = top->back;
	}
	num.push_back(top->val);
	reverse(num.begin(), num.end());
	for (int i = 0; i < num.size(); i++) cout << ' ' << num.at(i);
	cout << endl;
}