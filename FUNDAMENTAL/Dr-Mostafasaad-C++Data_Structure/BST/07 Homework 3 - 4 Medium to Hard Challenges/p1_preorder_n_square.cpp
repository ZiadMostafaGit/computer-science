#include <iostream>
#include <cassert>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
using namespace std;

class BinarySearchTree {
private:
	int data { };
	BinarySearchTree* left { };
	BinarySearchTree* right { };

public:

	BinarySearchTree(int data, BinarySearchTree* left = nullptr, BinarySearchTree* right = nullptr) :
			data(data), left(left), right(right) {
	}

	void print_inorder() {
		if (left)
			left->print_inorder();

		cout<<data<<" ";
		if (right)
			right->print_inorder();
	}

	void insert(int target) {
		if (target < data) {
			if (!left) {
				left = new BinarySearchTree(target);
			} else
				left->insert(target);
		} else if (target > data) {
			if (!right)
				right = new BinarySearchTree(target);
			else
				right->insert(target);
		} // else: exists already
	}

	////////////////////////////////////////////

	void build_preorder(deque<int> &preorder_queue) {
		preorder_queue.push_back(data);

		if (left)
			left->build_preorder(preorder_queue);

		if (right)
			right->build_preorder(preorder_queue);
	}

	// First element must be root.
	// Remain of data must be some less than root for left
	// and some > root for right
	// Use start/end to pass the given limit
	// properly handle cases for left only nodes / right only nodes / no children
	BinarySearchTree(deque<int> &preorder, int start = 0, int end = -1) {
		if (end == -1)
			end = (int) preorder.size() - 1;

		// next preorder is the current root
		data = preorder[start];

		// Carefully split the remaining of the preorder
		// Be careful for subrange left only case
		for (int split = start+1; split <= end+1; ++split) {
			if (split == end+1 || preorder[split] > data) {
				if (start+1 <= split-1)	// there is a left tree
					left = new BinarySearchTree(preorder, start+1, split - 1);
				if (split <= end)
					right = new BinarySearchTree(preorder, split, end);
				break;
			}
		}
	}

};


BinarySearchTree* GetTree1() {
	BinarySearchTree* tree = new BinarySearchTree(50);
	return tree;
}

BinarySearchTree* GetTree2() {
	BinarySearchTree* tree = new BinarySearchTree(50);
	tree->insert(20);
	return tree;
}

BinarySearchTree* GetTree3() {
	BinarySearchTree* tree = new BinarySearchTree(50);
	tree->insert(60);
	return tree;
}

BinarySearchTree* GetTree4() {
	BinarySearchTree* tree = new BinarySearchTree(50);
	tree->insert(20);
	tree->insert(60);
	tree->insert(15);
	tree->insert(45);
	tree->insert(70);
	tree->insert(35);
	tree->insert(73);

	// preorder: 50 20 15 45 35 60 70 73
	return tree;
}

BinarySearchTree* GetTree5() {
	BinarySearchTree* tree = new BinarySearchTree(50);
	tree->insert(20);
	tree->insert(60);
	tree->insert(15);
	tree->insert(45);
	tree->insert(70);
	tree->insert(35);
	tree->insert(73);

	tree->insert(14);
	tree->insert(16);
	tree->insert(36);
	tree->insert(58);
	// preorder: 50 20 15 14 16 45 35 36 60 58 70 73
	return tree;
}

void bst_from_preorder() {
	BinarySearchTree* tree = GetTree4();

	deque<int> preorder_queue;

	tree->build_preorder(preorder_queue);

	if(true) {
		for (int i = 0; i < preorder_queue.size(); ++i) {
			cout<<preorder_queue[i]<<" ";
		}
		cout<<"\n";
	}


	BinarySearchTree new_tree(preorder_queue);
	new_tree.print_inorder();	// must be sorted
}

int main() {
	bst_from_preorder();

	cout << "bye\n";

	return 0;
}

