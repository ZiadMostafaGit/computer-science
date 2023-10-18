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
			} else
				left->insert(target);
		} else if (target > data) {
			if (!right)
				right = new BinarySearchTree(target);
			else
				right->insert(target);
		} // else: exists already
	}

	BinarySearchTree* max_node() {
		BinarySearchTree* cur = this;
		while (cur && cur->right)
			cur = cur->right;
		return cur;
	}

	void special_delete(BinarySearchTree* child) {
		data = child->data;
		left = child->left;
		right = child->right;
		delete child;
	}

	BinarySearchTree* delete_node_p(int target, BinarySearchTree* node) {
		if (!node)
			return nullptr;

		if (target < node->data)
			node->left = delete_node_p(target, node->left);
		else if (target > node->data)
			node->right = delete_node_p(target, node->right);
		else {
			if (!node->left && !node->right) {
				delete node;
				node = nullptr;
			}
			else if (!node->right) 	// case 2: has left only
				node->special_delete(node->left);		// connect with child
			else if (!node->left)	// case 2: has right only
				node->special_delete(node->right);

			else {	// 2 children: Use predecessor
				BinarySearchTree* mx = node->left->max_node();
				node->data = mx->data;	// copy & go delete
				node->left = delete_node_p(node->data, node->left);
			}
		}
		return node;
	}

	void delete_value(int target) {
		if (target == data && !left && !right)
			return;	// can't remove root in this structure
		delete_node_p(target, this);
	}
};

BinarySearchTree* GetTree() {
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


int main() {

	BinarySearchTree* tree = GetTree();
	tree->delete_value(20);

	cout << "bye\n";

	return 0;
}

