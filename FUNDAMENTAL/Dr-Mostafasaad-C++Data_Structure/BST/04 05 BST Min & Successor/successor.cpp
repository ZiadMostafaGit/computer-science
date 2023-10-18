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

	// Modified search: Return chain of ancestors from node to target
	bool find_chain(vector<BinarySearchTree*> &ancestors, int target) {
		ancestors.push_back(this);

		if (target == data)
			return true;

		if (target < data)
			return left && left->find_chain(ancestors, target);

		return right && right->find_chain(ancestors, target);
	}

public:

	BinarySearchTree(int data) :
			data(data) {
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
				left = new BinarySearchTree(target);
			else
				left->insert(target);
		} else if (target > data) {
			if (!right)
				right = new BinarySearchTree(target);
			else
				right->insert(target);
		} // else: exists already
	}

	bool search(int target) {	// tail recursion
		if (target == data)
			return true;

		if (target < data)
			return left && left->search(target);

		return right && right->search(target);
	}

	int min_value() {
		BinarySearchTree* cur = this;
		while (cur && cur->left)
			cur = cur->left;
		return cur->data;
	}

	BinarySearchTree* get_next(vector<BinarySearchTree*> &ancestors) {
		if (ancestors.size() == 0)
			return nullptr;
		BinarySearchTree* node = ancestors.back();	// last element
		ancestors.pop_back();
		return node;
	}

	pair<bool, int> successor(int target) {
		vector<BinarySearchTree*> ancestors;

		if (!find_chain(ancestors, target))	// not exist
			return make_pair(false, -1);

		BinarySearchTree* child = get_next(ancestors);

		if (child->right)	// must have be in min of right
			return make_pair(true, child->right->min_value());

		BinarySearchTree* parent = get_next(ancestors);

		// Cancel chain of ancestors I am BIGGER than them
		while (parent && parent->right == child)
			child = parent, parent = get_next(ancestors);

		if (parent)	//
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

