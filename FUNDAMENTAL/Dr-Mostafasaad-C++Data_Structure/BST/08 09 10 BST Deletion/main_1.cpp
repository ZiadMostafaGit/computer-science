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

	BinarySearchTree* min_node() {
		BinarySearchTree* cur = this;
		while (cur && cur->left)
			cur = cur->left;
		return cur;
	}

	// Delete the target node in the tree and return updated tree
	// Caller use updated tree to re-link with children!

	BinarySearchTree* delete_node(int target, BinarySearchTree* node) {
		if (!node)
			return nullptr;

		if (target < node->data)
			node->left = delete_node(target, node->left);
		else if (target > node->data)
			node->right = delete_node(target, node->right);
		else {
			// Found the node: Handle deletion
			BinarySearchTree* tmp = node;

			if (!node->left && !node->right)	// case 1: no child
				node = nullptr;
			else if (!node->right) 	// case 2: has left only
				node = node->left;		// connect with child
			else if (!node->left)	// case 2: has right only
				node = node->right;
			else {	// 2 children: Use successor
				BinarySearchTree* mn = node->right->min_node();
				node->data = mn->data;	// copy & go delete
				node->right = delete_node(node->data, node->right);
				tmp = nullptr;	// Don't delete me. Successor will be deleted
			}
			if (tmp)
				delete tmp;
		}
		return node;
	}

public:

	BinarySearchTree(int data) :
			data(data) {
	}

	void get_inorder(vector<int>& values) {
		if (left)
			left->get_inorder(values);
		values.push_back(data);
		if (right)
			right->get_inorder(values);
	}
	////////////////////////////////////////////

	void insert(int target) {
		if (target < data) {
			if (!left) {
				left = new BinarySearchTree(target);
			}
			else
				left->insert(target);
		} else if (target > data) {
			if (!right)
				right = new BinarySearchTree(target);
			else
				right->insert(target);
		} // else: exists already
	}

	void delete_value(int target) {
		if (target == data && !left && !right)
			return;	// can't remove root in this structure
		delete_node(target, this);
	}
};

BinarySearchTree* GetTree1() {
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
	return tree;
}

void test1() {
	BinarySearchTree* tree = GetTree1();

	vector<int> inorder;
	tree->get_inorder(inorder);

	for (int i = 0; i < (int) inorder.size(); ++i) {
		if (inorder[i] == 50)
			continue;	// root

		vector<int> inorder_v2;
		BinarySearchTree* tree = GetTree1();
		tree->delete_value(inorder[i]);
		tree->get_inorder(inorder_v2);

		vector<int> inorder_cpy = inorder;
		inorder_cpy.erase(find(inorder_cpy.begin(), inorder_cpy.end(), inorder[i]));
		assert(inorder_cpy == inorder_v2);
	}
}

void test2() {
	// RTE - next lecture fix it
	BinarySearchTree* tree = new BinarySearchTree(10);
	tree->insert(5);
	tree->delete_value(10);	// this removed = RTE

	for (int i = 0; i < 1000; ++i)
		tree->insert(i);

	vector<int> inorder;
	tree->get_inorder(inorder);
}

int main() {
	test2();

	cout << "bye\n";

	return 0;
}

