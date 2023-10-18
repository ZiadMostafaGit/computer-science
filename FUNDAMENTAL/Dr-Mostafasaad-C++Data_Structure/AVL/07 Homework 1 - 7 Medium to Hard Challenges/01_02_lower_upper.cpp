#include <iostream>
#include <cassert>
#include <vector>
#include <algorithm>
using namespace std;

class AVLTree {
private:
	struct BinaryNode {
		int data { };
		int height { };
		BinaryNode* left { };
		BinaryNode* right { };

		BinaryNode(int data) :
				data(data) {
		}

		int ch_height(BinaryNode* node) {	// child height
			if (!node)
				return -1;			// -1 for null
			return node->height;	// 0 for leaf
		}
		int update_height() {	// call in end of insert function
			return height = 1 + max(ch_height(left), ch_height(right));
		}
		int balance_factor() {
			return ch_height(left) - ch_height(right);
		}
	};

	BinaryNode *root { };

	///////////////////////////
	bool search(int target, BinaryNode* node) {
		if (!node)
			return false;

		if (target == node->data)
			return true;

		if (target < node->data)
			return search(target, node->left);

		return search(target, node->right);
	}

	BinaryNode* right_rotation(BinaryNode* Q) {
		BinaryNode* P = Q->left;
		Q->left = P->right;
		P->right = Q;
		Q->update_height();
		P->update_height();
		return P;
	}

	BinaryNode* left_rotation(BinaryNode* P) {
		BinaryNode* Q = P->right;
		P->right = Q->left;
		Q->left = P;
		P->update_height();
		Q->update_height();
		return Q;
	}

	BinaryNode* balance(BinaryNode* node) {
		if (node->balance_factor() == 2) { 			// Left
			if (node->left->balance_factor() == -1)	// Left Right?
				node->left = left_rotation(node->left);	// To Left Left

			node = right_rotation(node);	// Balance Left Left
		} else if (node->balance_factor() == -2) {
			if (node->right->balance_factor() == 1)
				node->right = right_rotation(node->right);

			node = left_rotation(node);
		}
		return node;
	}

	BinaryNode* insert_node(int target, BinaryNode* node) {
		if (target < node->data) {
			if (!node->left)
				node->left = new BinaryNode(target);
			else
				// change left. update left as it might be balanced
				node->left = insert_node(target, node->left);
		} else if (target > node->data) {
			if (!node->right)
				node->right = new BinaryNode(target);
			else
				node->right = insert_node(target, node->right);
		}
		node->update_height();
		return balance(node);
	}

	BinaryNode* min_node(BinaryNode* cur) {
		while (cur && cur->left)
			cur = cur->left;
		return cur;
	}

	BinaryNode* delete_node(int target, BinaryNode* node) {
		if (!node)
			return nullptr;

		if (target < node->data)
			node->left = delete_node(target, node->left);
		else if (target > node->data)
			node->right = delete_node(target, node->right);
		else {
			BinaryNode* tmp = node;

			if (!node->left && !node->right)	// case 1: no child
				node = nullptr;
			else if (!node->right) 	// case 2: has left only
				node = node->left;		// connect with child
			else if (!node->left)	// case 2: has right only
				node = node->right;
			else {	// 2 children: Use successor
				BinaryNode* mn = min_node(node->right);
				node->data = mn->data;	// copy & go delete
				node->right = delete_node(node->data, node->right);
				tmp = nullptr;	// Don't delete me. Successor will be deleted
			}
			if (tmp)
				delete tmp;
		}
		if (node) {
			node->update_height();
			node = balance(node);
		}
		return node;
	}

	BinaryNode* lower_bound(int target, BinaryNode* node) {
		if (!node)
			return nullptr;

		if (target <= node->data) {	// I can be a lower bound
			// Can we find tighter answer in the left?
			BinaryNode* ans = lower_bound(target, node->left);
			if (ans)
				return ans;
			return node;
		}
		return lower_bound(target, node->right);
	}

	BinaryNode* upper_bound(int target, BinaryNode* node) {
		if (!node)
			return nullptr;

		if (target < node->data) {	// I can be an upper bound
			// Can we find tighter answer in the left?
			BinaryNode* ans = upper_bound(target, node->left);
			if (ans)
				return ans;
			return node;
		}
		return upper_bound(target, node->right);
	}

public:
	void insert_value(int target) {
		if (!root)
			root = new BinaryNode(target);
		else
			root = insert_node(target, root);
	}

	void delete_value(int target) {
		if (root) {
			root = delete_node(target, root);
		}
	}

	pair<bool, int> lower_bound(int target) {
		if (root) {
			BinaryNode* res = lower_bound(target, root);
			if(!res)
				return make_pair(false, -1);
			return make_pair(true, res->data);
		}
		return make_pair(false, -1);
	}

	pair<bool, int> upper_bound(int target) {
		if (root) {
			BinaryNode* res = upper_bound(target, root);
			if(!res)
				return make_pair(false, -1);
			return make_pair(true, res->data);
		}
		return make_pair(false, -1);
	}
};

void test_lower() {
	AVLTree tree;

	vector<int> v { 10, 5, 20, 15, 50, 70, 2, 13, 40 };
	// 2, 5, 10, 13, 15, 20, 40, 50, 70

	for (int i = 0; i < v.size(); ++i)
		tree.insert_value(v[i]);

	sort(v.begin(), v.end());

	for (int i = 0; i < v.size(); ++i)
		cout << v[i]+1<< " " << tree.lower_bound(v[i]+1 ).second << "\n";
}

void test_upper() {
	AVLTree tree;

	vector<int> v { 10, 5, 20, 15, 50, 70, 2, 13, 40 };

	for (int i = 0; i < v.size(); ++i)
		tree.insert_value(v[i]);

	sort(v.begin(), v.end());
	for (int i = 0; i < v.size(); ++i)
		cout << v[i]<< " " << tree.upper_bound(v[i] ).second << "\n";
}

int main() {
	test_upper();

	cout << "bye\n";

	return 0;
}

