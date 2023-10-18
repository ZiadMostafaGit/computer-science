#include<iostream>
#include<queue>
#include<cassert>
#include<algorithm>
using namespace std;

class AVLTree {
private:
	int data { };
	int height { };
	AVLTree* left { };
	AVLTree* right { };

	int ch_height(AVLTree* node) {	// child height
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

	AVLTree* right_rotation(AVLTree* Q) {
		cout << "right_rotation " << Q->data << "\n";
		AVLTree* P = Q->left;
		Q->left = P->right;
		P->right = Q;
		Q->update_height();
		P->update_height();
		return P;
	}

	AVLTree* left_rotation(AVLTree* P) {
		cout << "left_rotation " << P->data << "\n";
		AVLTree* Q = P->right;
		P->right = Q->left;
		Q->left = P;
		P->update_height();
		Q->update_height();
		return Q;
	}

	AVLTree* min_node() {
		AVLTree* cur = this;
		while (cur && cur->left)
			cur = cur->left;
		return cur;
	}

	void special_delete(AVLTree* child) {
		data = child->data;
		left = child->left;
		right = child->right;
		delete child;
	}

	AVLTree* delete_node(int target, AVLTree* node) {
		if (!node)
			return nullptr;

		if (target < node->data)
			node->left = delete_node(target, node->left);
		else if (target > node->data)
			node->right = delete_node(target, node->right);
		else {
			if (!node->left && !node->right) {
				delete node;
				node = nullptr;
			}
			else if (!node->right) 	// case 2: has left only
				node->special_delete(node->left);		// connect with child
			else if (!node->left)	// case 2: has right only
				node->special_delete(node->right);
			else {
				AVLTree* mn = node->right->min_node();
				node->data = mn->data;
				node->right = delete_node(node->data, node->right);
			}
		}
		if (node) {
			node->update_height();
			node = balance(node);
		}
		return node;
	}

	AVLTree* balance(AVLTree* node) {
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

	/*
	 * Very tricky: this root itself got changed to argument node structure
	 * "This" is now either left or right of this node!
	 * We need carefully swap "This" and "node" data
	 * to maintain same new structure.
	 * If not careful = this will point to itself (recursion)
	 *
	 * Tip: this limitation is due to our structure
	 * Recall we avoided having a separate node structure
	 * This is not AVL issue but appears with AVL due to changing myself
	 */
	void reroot(AVLTree* node) {
		if (node == this)
			return;

		swap(this->data, node->data);
		swap(this->height, node->height);

		if (this == node->left) {
			// Give node my 2 children
			// I take his right child and
			// point to him as my left
			swap(node->right, this->right);
			node->left = this->left;
			this->left = node;
		} else if (this == node->right) {
			swap(node->left, this->left);
			node->right = this->right;
			this->right = node;
		}
	}

public:
	AVLTree(int data) :
			data(data) {
	}

	void level_order_traversal() {
		queue<AVLTree*> nodes_queue;
		nodes_queue.push(this);

		int level = 0;
		while (!nodes_queue.empty()) {
			int sz = nodes_queue.size();

			cout << "Level " << level << ": ";
			while (sz--) {
				AVLTree*cur = nodes_queue.front();
				nodes_queue.pop();

				cout << cur->data << " ";
				if (cur->left)
					nodes_queue.push(cur->left);
				if (cur->right)
					nodes_queue.push(cur->right);
			}
			level++;
			cout << "\n";
		}
		cout << "******************\n";
	}

	void insert(int target) {
		if (target < data) {
			if (!left)
				left = new AVLTree(target);
			else
				left->insert(target);
		} else if (target > data) {
			if (!right)
				right = new AVLTree(target);
			else
				right->insert(target);
		}
		update_height();
		// Can't. Do manual copy!
		//this = balance(this);
		reroot(balance(this));	// copy
	}

	void delete_value(int target) {
		if (target == data && !left && !right)
			return;	// can't remove root in this structure
		reroot(delete_node(target, this));
	}

	bool is_bst() {
		bool left_bst = !left || data > left->data && left->is_bst();

		if (!left_bst)
			return false;

		bool right_bst = !right || data < right->data && right->is_bst();
		return right_bst;
	}

	void verify() {
		assert(abs(balance_factor()) <= 1);
		assert(is_bst());
	}
};

void f1() {
	AVLTree tree(0);

	for (int i = 1; i <= 32; ++i) {	// degenerate
		tree.insert(i);
		tree.verify();
		tree.level_order_traversal();
	}
}

void f2() {	// for instructor test - ignore

	vector<int> v;
	for (int i = 0; i < 10; ++i)
		v.push_back(i);

	do {
		AVLTree tree(100);
		for (int i = 0; i < v.size(); ++i) {
			tree.insert(v[i]);
			tree.verify();
			tree.level_order_traversal();
		}
	} while (next_permutation(v.begin(), v.end()));
}

void f3() {
	AVLTree tree(3);
	vector<int> v { 5, 9, 1, 0, 2, 6, 10, 7, 4, 8 };

	for (int i = 0; i < v.size(); ++i) {
		tree.insert(v[i]);
		tree.verify();
		tree.level_order_traversal();
	}
}

void delete1() {
	AVLTree tree(9);
	vector<int> v {6, 14, 7, 13, 32, 10};

	for (int i = 0; i < v.size(); ++i) {
		tree.insert(v[i]);
	}

	v = {6, 14, 32, 9};

	for (int i = 0; i < v.size(); ++i) {
		tree.delete_value(v[i]);
		tree.verify();
		tree.level_order_traversal();
	}
}

void delete2() {
	AVLTree tree(7);
	vector<int> v {3, 11, 1, 5, 15, 4, 6};

	for (int i = 0; i < v.size(); ++i)
		tree.insert(v[i]);
	tree.level_order_traversal();

	v = {15};

	for (int i = 0; i < v.size(); ++i) {
		tree.delete_value(v[i]);
		tree.verify();
		tree.level_order_traversal();
	}
}



int main() {
	delete1();

	return 0;
}
