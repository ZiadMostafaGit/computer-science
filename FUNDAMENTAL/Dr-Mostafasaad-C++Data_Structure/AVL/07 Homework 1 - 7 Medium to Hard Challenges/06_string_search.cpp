#include <iostream>
#include <cassert>
#include <queue>
using namespace std;


class AVLTree {
private:
	struct BinaryNode {
		string data { };
		bool is_full_word {};
		int height { };
		BinaryNode* left { };
		BinaryNode* right { };

		BinaryNode(string data, bool is_full_word) :
				data(data), is_full_word(is_full_word) {
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

	// -1 (not exist), 0 exist as prefix, 1 exist as full word
	int search(string target, BinaryNode* node) {
		if(!node)
			return -1;

		if (target == node->data)
			return node->is_full_word;

		if (target < node->data)
			return search(target, node->left);

		return search(target, node->right);
	}

	BinaryNode* insert_node(string target, bool is_full_word, BinaryNode* node) {
		if (target < node->data) {
			if (!node->left)
				node->left = new BinaryNode(target, is_full_word);
			else	// change left. update left as it might be balanced
				node->left = insert_node(target, is_full_word, node->left);
		} else if (target > node->data) {
			if (!node->right)
				node->right = new BinaryNode(target, is_full_word);
			else
				node->right = insert_node(target, is_full_word, node->right);
		}
		else if (is_full_word)	// if existed before but this is full_word, mark it
			node->is_full_word = 1;
		node->update_height();
		return balance(node);
	}

	void insert_value(string target, int is_full_word) {
		if (!root)
			root = new BinaryNode(target, is_full_word);
		else
			root = insert_node(target, is_full_word, root);
	}

public:
	void insert_string(string target) {	// O(nlogn)
		// Idea is to insert all the possible prefixes and add to AVL
		// Mark which is prefix and which is full word
		if(target == "")
			return;

		string cur;
		for (int i = 0; i < (int)target.size(); ++i) {
			cur += target[i];
			// If it is last index, then this is the original full word
			insert_value(cur, i == (int)target.size() - 1);
		}
	}

	bool word_exist(string target) {
		return search(target, root) == 1;
	}

	bool prefix_exist(string target) {
		// if exists as full or prefix
		return search(target, root) != -1;
	}
};

int main() {
	AVLTree tree;

	tree.insert_string("abcd");
	tree.insert_string("xyz");

	cout<<tree.word_exist("abcd")<<"\n";	// 1
	cout<<tree.word_exist("ab")<<"\n";		// 0
	cout<<tree.prefix_exist("ab")<<"\n";	// 1

	tree.insert_string("ab");

	cout<<tree.word_exist("ab")<<"\n";		// 1
	cout<<tree.word_exist("cd")<<"\n";		// 0
	cout<<tree.word_exist("abcde")<<"\n";	// 0



	return 0;
}

