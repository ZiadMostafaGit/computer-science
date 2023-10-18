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
	if (op == '*' || op == '/')
		return 2;
	if (op == '^')
		return 3;
	return 0;
}

/*
Assume: no spaces, positive single digits, only + - * /
1+2+3   ==>    12+3+
1+2*3   ==>    123*+
2*3+4   ==>    23*4+
1+3*5-8/2   ==>     135*+82/-
2+3*4-5*6+7		==>		234*+56*-7+
2+(3*(4-5*2)*(9/3+6)) ==>  23452*-*93/6+*+
4^3^2 ==> 432^^
5+4^3^2-9   ==> 5432^^+9-
a+B*2-c   ==>    aB2*+c-
a+b*(c^d-e)^(f+g*h)-i  ==> abcd^e-fgh*+^*+i-
1+2^3^4*5-6  ==> 1234^^5*+6-
(1+2)^3^(4*5-6)^2+1		==> 12+345*6-2^^^1+
 */

string infixToPostfix(string infix) {
	// Consider digits, small and upper letters
	string to_post = "";
	for (int i = 0; i < 26; ++i) {
		to_post += (char)(i+'a');
		to_post += (char)(i+'A');
		if(i < 10)
			to_post += (char)(i+'0');
	}
	// aA0bB1cC2dD3eE4fF5gG6hH7iI8jJ9kKlLmMnNoOpPqQrRsStTuUvVwWxXyYzZ

	Stack operators;
	string postfix;

	infix += '-';			// Whatever lowest priority: force stack got empty
	operators.push('#');	// Remove IsEmpty

	for (int i = 0; i < (int) infix.size(); ++i) {
		if (to_post.find(infix[i]) != string::npos)
			postfix += infix[i];
		else if (infix[i] == '(')
			operators.push(infix[i]);
		else if (infix[i] == ')') {
			while (operators.peek() != '(')
				postfix += operators.pop();
			operators.pop();	// pop (
		} else {
			// Now we have to split > from ==
			// Now in case == The ^ is right to left and shouldn't be pushed!
			// Think 2^3^4: output is 23 and stack [^]: we poped it, output is 23^4^
			// But the correct output is 234^^ where 34^ is applied first!
			while (precedence(operators.peek()) > precedence(infix[i]) ||
				   precedence(operators.peek()) == precedence(infix[i]) && infix[i] != '^')
				postfix += operators.pop();
			operators.push(infix[i]);
		}
	}

	return postfix;
}

int main() {


	string equation;
	cin >> equation;
	cout << infixToPostfix(equation);
	return 0;
}

