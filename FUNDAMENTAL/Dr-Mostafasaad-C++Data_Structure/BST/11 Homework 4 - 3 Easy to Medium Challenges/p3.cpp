#include <iostream>
#include <cassert>
#include <queue>
using namespace std;

/*
 * Rewriting for the binary search tree but based on extra struct for the node
 * Pros: We can easily delete root (or later in AVL rotate the tree)
 * Cons: Duplicate functions with node* for the operation
 */

class BinarySearchTree {
private:
	struct BinaryNode {
		int data { };
		BinaryNode* left { };
		BinaryNode* right { };

		BinaryNode(int data) :
				data(data) {
		}
	};

	BinaryNode *root { };

	///////////////////////////
	bool search(int target, BinaryNode* node) {
		if(!node)
			return false;

		if (target == node->data)
			return true;

		if (target < node->data)
			return search(target, node->left);

		return search(target, node->right);
	}

	void insert_node(int target, BinaryNode* node) {
		if (target < node->data) {
			if (!node->left)
				node->left = new BinaryNode(target);
			else
				insert_node(target, node->left);
		} else if (target > node->data) {
			if (!node->right)
				node->right = new BinaryNode(target);
			else
				insert_node(target, node->right);
		}
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
		return node;
	}

	bool is_bst(BinaryNode* node) {
		bool left_bst = !node->left || node->data > node->left->data && is_bst(node->left);

		if (!left_bst)
			return false;

		bool right_bst = !node->right || node->data < node->right->data && is_bst(node->right);
		return right_bst;
	}

	void print_inorder(BinaryNode* node) {
		if(!node)
			return;

		print_inorder(node->left);
		cout << node->data << " ";
		print_inorder(node->right);
	}


public:
	void insert_value(int target) {
		if (!root)
			root = new BinaryNode(target);
		else
			insert_node(target, root);

		is_bst(root);
	}

	void delete_value(int target) {
		if (root) {
			root = delete_node(target, root);
			is_bst(root);
		}
	}

	bool search(int target) {
		return search(target, root);
	}

	void print_inorder() {
		print_inorder(root);
	}

	void level_order_traversal() {
		if (!root)
			return;

		cout << "******************\n";
		queue<BinaryNode*> nodes_queue;
		nodes_queue.push(root);

		int level = 0;
		while (!nodes_queue.empty()) {
			int sz = nodes_queue.size();

			cout << "Level " << level << ": ";
			while (sz--) {
				BinaryNode*cur = nodes_queue.front();
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
	}
};

BinarySearchTree* GetTree1() {
	BinarySearchTree* tree = new BinarySearchTree;
	tree->insert_value(20);
	tree->insert_value(60);
	tree->insert_value(15);
	tree->insert_value(45);
	tree->insert_value(70);
	tree->insert_value(35);
	tree->insert_value(73);

	tree->insert_value(14);
	tree->insert_value(16);
	tree->insert_value(36);
	tree->insert_value(58);
	return tree;
}

void test1() {
	BinarySearchTree* tree = new BinarySearchTree;
	tree->insert_value(10);
	tree->insert_value(5);

	tree->level_order_traversal();
	tree->delete_value(10);
	tree->level_order_traversal();
	tree->delete_value(5);
	tree->insert_value(7);
	tree->level_order_traversal();
}

void test2() {
	BinarySearchTree* tree = GetTree1();
	tree->level_order_traversal();

	tree->delete_value(20);
	tree->level_order_traversal();

	cout<<tree->search(15)<<"\n";
	tree->delete_value(15);
	cout<<tree->search(15)<<"\n";
	tree->print_inorder();

}

int main() {
	test1();

	cout << "bye\n";

	return 0;
}

