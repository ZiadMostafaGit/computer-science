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

string reversedInfixToPostfix(string infix) {
	Stack operators;
	string postfix;

	for (int i = 0; i < (int) infix.size(); ++i) {
		if (isdigit(infix[i]) || isalpha(infix[i]))
			postfix += infix[i];
		else if (infix[i] == '(')
			operators.push(infix[i]);
		else if (infix[i] == ')') {
			while (operators.peek() != '(')
				postfix += operators.pop();
			operators.pop();	// pop (
		} else {
			// For equality in normal postfix, */+- (LR) should poped but ^ (RL) shouldn't
			// But for reversed infix, then ^ is LR (poped) and */+- are (RL) don't pop
			while(!operators.isEmpty()) {
				if (precedence(operators.peek()) > precedence(infix[i]) ||
					precedence(operators.peek()) == precedence(infix[i]) && infix[i] == '^')
					postfix += operators.pop();
				else
					break;
			}

			operators.push(infix[i]);
		}
	}
	while(!operators.isEmpty())
		postfix += operators.pop();

	return postfix;
}

string infixToPrefix(string infix) {
	/*
	 * The general idea is close to infix to postfix
	 * But consider first reversing the infix
	 * Now code is very similar to postfix conversion
	 * With only one change: LR/RL associativity of operators are reversed now
	 * in our code style
	 *
	 * Overall
	 * 	Reverse
	 * 	Modified Infix to postfix
	 * 	Reverse
	 */
	string reversed_infix;
	for (int i = (int) infix.size() - 1; i >= 0; --i) {
		if (infix[i] == '(')
			reversed_infix += ')';
		else if (infix[i] == ')')
			reversed_infix += '(';
		else
			reversed_infix += infix[i];
	}
	string reversed_postfix = reversedInfixToPostfix(reversed_infix);
	string prefix;
	for (int i = (int) reversed_postfix.size() - 1; i >= 0; --i)
		prefix += reversed_postfix[i];
	return prefix;
}

int main() {

    assert(infixToPrefix("1+2") == "+12");
    assert(infixToPrefix("9-2+3") == "+-923");
    assert(infixToPrefix("2*3+4") == "+*234");
    assert(infixToPrefix("4^3^2") == "^4^32");
    assert(infixToPrefix("1+2") == "+12");
    assert(infixToPrefix("1+2+3") == "++123");
    assert(infixToPrefix("2+4") == "+24");
    assert(infixToPrefix("1+3-8/2") == "-+13/82");
    assert(infixToPrefix("2+3-5+7") == "+-+2357");
    assert(infixToPrefix("2+(3*(4-5)*(9/3+6))") == "+2**3-45+/936");
    assert(infixToPrefix("5+4^3^2-9") == "-+5^4^329");
    assert(infixToPrefix("a+B-c") == "-+aBc");
    assert(infixToPrefix("a+(c^d-e)^(f+g*h)-i") == "-+a^-^cde+f*ghi");
    assert(infixToPrefix("1+2^3^4-6") == "-+1^2^346");
    assert(infixToPrefix("(1+2)^3^(4-6)^2+1") == "+^+12^3^-4621");
    assert(infixToPrefix("2^3^4^5^6") == "^2^3^4^56");

	return 0;


	string equation;
	while (cin >> equation) {
		cout << infixToPrefix(equation) << "\n";
	}
	return 0;
}

