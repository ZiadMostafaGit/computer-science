#include <iostream>
#include <cassert>
using namespace std;

typedef char type;

class Stack {
private:
	// Tip: We can make this struct internally
	struct Node {
		type data { };
		Node* next { };
		Node(int data) :
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
		int element = head->data;
		Node* temp = head;
		head = head->next;
		delete temp;
		return element;
	}

	type peek() {
		assert(!isEmpty());
		int element = head->data;
		return element;
	}

	int isEmpty() {
		return !head;
	}
};

int precedence(char op) {
	if (op == '+' || op == '-')
		return 1;
	return 2;	// For * /
}

/*
Assume: no spaces, positive single digits, only + - * /
1+2+3   ==>    12+3+
1+2*3   ==>    123*+
2*3+4   ==>    23*4+
1+3*5-8/2   ==>     135*+82/-
2+3*4-5*6+7		==>		234*+56*-7+
*/
string infixToPostfix(string& infix) {
	Stack operators;
	string postfix;

	for (int i = 0; i < (int)infix.size(); ++i){
		if (isdigit(infix[i]))
			postfix += infix[i];
		else {
			while (!operators.isEmpty() &&
					precedence(operators.peek()) >= precedence(infix[i]))
				postfix += operators.pop();
			operators.push(infix[i]);	// higher than any in stack
		}
	}
	while (!operators.isEmpty())	// remaining
		postfix += operators.pop();

	return postfix;
}

int main() {
	string equation;
	cin>>equation;
	cout<<infixToPostfix(equation);

	return 0;
}

