#include<iostream>
#include<cassert>
using namespace std;

// simple trick to avoid re-changing the class
typedef char type;

class Stack {
private:
	int size { };
	int top { };
	type* array { };
public:
	Stack(int size) :
			size(size), top(-1) {
		array = new type[size];
	}

	~Stack() {
		delete[] array;
	}

	void push(type x) {
		assert(!isFull());
		array[++top] = x;
	}

	type pop() {
		assert(!isEmpty());
		return array[top--];
	}

	type peek() {
		assert(!isEmpty());
		return array[top];
	}

	int isFull() {
		return top == size - 1;
	}

	int isEmpty() {
		return top == -1;
	}
};

/*
 Note: Code has no relation to infix/prefix/postfix conversions
 It is important to not be trapped in something u know
 Sometimes it is good to think in a very simple way without any complex tools u have

 */
 
char sign(char a, char b) {
	if (a == b)
		return '+';		// ++ or --
	return '-';			// +- or -+
}

/*
 In math, each block () will have a sign depends on parsing from the begin
 We need to maintain what is the current sign for a block
 Then with a new sign and old sign we can decide the block sign
 Image a block inside a block inside a block, etc
 once a block is done, we need to go back to our old status
 stack can help us do that. This is a common pattern with stack
 when u find things wish such recursive nature such as (()(()))
 
 9-(2-3)
 1-(2-3-((4-5)-8+7))
 */
string remove_brackets(string str) {
	// Assume single digits, no unary

	Stack stk(str.size());	// current active sign for this block ()
	stk.push('+');

	string res = "";
	for (int i = 0; i < (int) str.size(); ++i) {
		char c = str[i];
		if (isdigit(c))
			res += c;
		else if (c == '+' || c == '-')
			res += sign(stk.peek(), c);	// use current block sign with c to get new sign
		else if (c == '(' && i) {	// new block needs a new sign: is it -( or +(? Use it with previous block sign
			if (str[i - 1] != '(')	// ((( cases: no change in sign
				stk.push(sign(stk.peek(), str[i - 1]));
			else
				stk.push(stk.peek());
		} else
			stk.pop();	// for ) remove an active sign
	}
	return res;
}

int main() {
	string test;

	test = "1+2-3-4+5-6-7+8";
	cout << test << " => " << remove_brackets(test) << "\n";

	test = "9-(2+3)";
	cout << test << " => " << remove_brackets(test) << "\n";

	test = "9-(2-3)";
	cout << test << " => " << remove_brackets(test) << "\n";

	test = "9+(2-3)";
	cout << test << " => " << remove_brackets(test) << "\n";

	test = "1-(2-3-(4+5))-6-(7-8)";
	cout << test << " => " << remove_brackets(test) << "\n";

	test = "1-(2-3-(4+5)+6-7)";
	cout << test << " => " << remove_brackets(test) << "\n";

	test = "1-(2-3-(4+5-(6-7)))";
	cout << test << " => " << remove_brackets(test) << "\n";

	test = "1-((4+5)-(6-7)))";
	cout << test << " => " << remove_brackets(test) << "\n";

	test = "1-(((4-5)-(6-7))))";
	cout << test << " => " << remove_brackets(test) << "\n";

	test = "1-(2-3-((4+5)-(6-7)))";
	cout << test << " => " << remove_brackets(test) << "\n";

	test = "1-(2-3-((4-5)-(6-7)))";
	cout << test << " => " << remove_brackets(test) << "\n";

	test = "1-(2-3+((4-5)-(6-7)))";
	cout << test << " => " << remove_brackets(test) << "\n";

	/*
		1+2-3-4+5-6-7+8 => 1+2-3-4+5-6-7+8
		9-(2+3) => 9-2-3
		9-(2-3) => 9-2+3
		9+(2-3) => 9+2-3
		1-(2-3-(4+5))-6-(7-8) => 1-2+3+4+5-6-7+8
		1-(2-3-(4+5)+6-7) => 1-2+3+4+5-6+7
		1-(2-3-(4+5-(6-7))) => 1-2+3+4+5-6+7
		1-((4+5)-(6-7))) => 1-4-5+6-7
		1-(((4-5)-(6-7)))) => 1-4+5+6-7
		1-(2-3-((4+5)-(6-7))) => 1-2+3+4+5-6+7
		1-(2-3-((4-5)-(6-7))) => 1-2+3+4-5-6+7
		1-(2-3+((4-5)-(6-7))) => 1-2+3-4+5+6-7
	 */
	return 0;
}
