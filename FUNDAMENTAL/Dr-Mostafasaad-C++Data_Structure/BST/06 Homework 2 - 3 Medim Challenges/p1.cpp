#include <iostream>
#include <cassert>
#include <vector>
#include <queue>
#include <stack>
#include <cmath>
using namespace std;

class BinarySearchTree {
private:
	int data { };
	BinarySearchTree* left { };
	BinarySearchTree* right { };
	BinarySearchTree* parent { };

	BinarySearchTree* find(int target) {
		if (target == data)
			return this;

		if (target < data) {
			if (!left)
				return nullptr;
			return left->find(target);
		}

		if (!right)
			return nullptr;
		return right->find(target);
	}

public:

	BinarySearchTree(int data, BinarySearchTree* parent = nullptr) :
			data(data), parent(parent) {
	}

	void print_inorder() {
		if (left)
			left->print_inorder();
		cout << data << " ";
		if (right)
			right->print_inorder();
	}
	////////////////////////////////////////////

	void insert(int target) {
		if (target < data) {
			if (!left)
				left = new BinarySearchTree(target, this);
			else
				left->insert(target);
		} else if (target > data) {
			if (!right)
				right = new BinarySearchTree(target, this);
			else
				right->insert(target);
		} // else: exists already
	}

	int min_value() {
		BinarySearchTree* cur = this;
		while (cur && cur->left)
			cur = cur->left;
		return cur->data;
	}

	pair<bool, int> successor(int target) {
		BinarySearchTree *child = find(target);

		if (!child)	// not exist
			return make_pair(false, -1);

		if (child->right)	// must have be in min of right
			return make_pair(true, child->right->min_value());

		BinarySearchTree* parent = child->parent;

		while (parent && parent->right == child)
			child = parent, parent = child->parent;

		if (parent)
			return make_pair(true, parent->data);
		return make_pair(false, -1);
	}
};

int main() {
	BinarySearchTree tree(50);
	tree.insert(20);
	tree.insert(45);
	tree.insert(70);
	tree.insert(73);
	tree.insert(35);
	tree.insert(15);
	tree.insert(60);

	//tree.print_inorder();
	vector<int> v { 15, 20, 35, 45, 50, 60, 70, 73, 100 };

	for (int i = 0; i < v.size(); ++i) {
		cout << v[i] << " ";
		pair<bool, int> p = tree.successor(v[i]);

		if (p.first)
			cout << p.second << "\n";
		else
			cout << "NA\n";

	}

	cout << "bye\n";

	return 0;
}

