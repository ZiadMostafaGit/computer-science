#include <iostream>
#include <cassert>
#include <climits>
using namespace std;

class Stack {
private:
	// Tip: We can make this struct internally
	struct Node {
		int data { };
		Node* next { };
		Node(int data) :
				data(data) {
		}
	};

	Node *head { };		// Points to Top

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

	void push(int value) {
		// By design: always new node = head
		// Great match with stack!
		Node* item = new Node(value);
		item->next = head;
		head = item;

		// Tip: This code works as long as machine has more RAM
		// In industry: You may check if return is null (can't create) or not.
	}

	int pop() {
		assert(!isEmpty());
		int element = head->data;
		Node* temp = head;
		head = head->next;
		delete temp;
		return element;
	}

	int peek() {
		assert(!isEmpty());
		int element = head->data;
		return element;
	}

	int isEmpty() {
		return !head;
	}
};

int main() {

	Stack stk;
	stk.push(10);
	stk.push(20);
	stk.push(30);

	stk.display();	// 30 20 10
	cout << stk.peek() << "\n";	// 30

	while (!stk.isEmpty())
		cout << stk.pop() << " ";
	// 30 20 10

	return 0;
}

