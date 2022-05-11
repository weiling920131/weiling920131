#include"stack.h"


void STACK::push(int num) {
	stack* tmp = new stack;
	tmp->val = num;
	if (!bottom) {
		bottom = tmp;
		return;
	}

	stack* top = bottom;
	while ((top->above)) top = top->above;
	top->above = tmp;
}

void STACK::pop() {
	if (!bottom) return;

	stack* top = bottom, * pre = bottom;
	while ((top->above)) {
		pre = top;
		top = top->above;
	}
	pre->above = NULL;
	delete top;
}

void STACK::print() {
	cout << "The values in the stack :";
	if (!bottom) {
		cout << endl;
		return;
	}
	stack* top = bottom;
	while ((top->above)) {
		cout << ' ' << top->val;
		top = top->above;
	}
	cout << ' ' << top->val << endl;
}