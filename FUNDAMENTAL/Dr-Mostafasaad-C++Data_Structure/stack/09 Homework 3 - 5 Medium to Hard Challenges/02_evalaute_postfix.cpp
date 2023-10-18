#include <iostream>
#include <cassert>
#include <cmath>
using namespace std;

typedef double type;

class Stack {
private:
	// Tip: We can make this struct internally
	struct Node {
		type data { };
		Node* next { };
		Node(type data) :
				data(data) {
		}
	};

	Node *head { };

public:
	~Stack() {
		while (!isEmpty())
			pop();
	}
	void display() {
		for (Node* cur = head; cur; cur = cur->next)
			cout << cur->data << " ";
		cout << "\n";
	}

	void push(type value) {
		Node* item = new Node(value);
		item->next = head;
		head = item;
	}

	type pop() {
		assert(!isEmpty());
		type element = head->data;
		Node* temp = head;
		head = head->next;
		delete temp;
		return element;
	}

	type peek() {
		assert(!isEmpty());
		type element = head->data;
		return element;
	}

	bool isEmpty() {
		return !head;
	}
};

double operation(double a, double b, char oper) {
	if (oper == '+')
		return a + b;
	if (oper == '-')
		return a - b;
	if (oper == '*')
		return a * b;
	if (oper == '/')
		return a / b;
	return pow(a, b);	// ^
}

/*
Assume: no spaces, positive single digits, only + - * /
52/    ==> 2.5
12+3+  ==> 6
123*+  ==> 7
23*4+  ==> 10
135*+72/-   ==> 12.5
23452*-*93/6+*+		==> -160
432^^	==> 262144
5432^^+9-	==>	262140
 */
double evalaute_postfix(string postfix) {
	// Note: This stack is based on numbers and conversion was on characters
	// We can't have both easily in single program. With templates, this is easily solved
	Stack numbers;

	for (int i = 0; i < (int) postfix.size(); ++i) {
		if (isdigit(postfix[i]))
			numbers.push(postfix[i] - '0');
		else {
			double a = numbers.pop();
			double b = numbers.pop();
			// Careful: b, a NOT a, b: consider 8/2 ==> 82/  a = 2, b = 8
			numbers.push(operation(b, a, postfix[i]));
		}
	}
	return numbers.pop();
}

int main() {

	string postfix;
	while(cin >> postfix)
		cout << evalaute_postfix(postfix)<<"\n";
	return 0;
}

