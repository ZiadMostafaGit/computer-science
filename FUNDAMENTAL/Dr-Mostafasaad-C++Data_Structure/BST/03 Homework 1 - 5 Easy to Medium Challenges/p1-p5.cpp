#include <iostream>
#include <cassert>
#include <vector>
#include <queue>
#include <climits>
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

	void level_order_traversal2() {
		queue<BinarySearchTree*> nodes_queue;
		nodes_queue.push(this);

		int level = 0;
		while (!nodes_queue.empty()) {
			int sz = nodes_queue.size();

			cout<<"Level "<<level<<": ";
			while(sz--) {
				BinarySearchTree*cur = nodes_queue.front();
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

	bool search_iterative(int target) {
		BinarySearchTree *node = this;

		while (node) {
			if (target == node->data)
				return true;

			if (target < node->data)
				node = node->left;
			else
				node = node->right;
		}
		return false;
	}




























	/*
	 * Code FIX
	 *
	 * Imagine the following tree
	 *          5
	 *    4              6
	 *               3        7
	 *
	 *
	 *   Although 6 is a valid BST, 5 > 3, which is wrong
	 *
	 *   Idea: we need to make sure this value is proper with the parents too not just the child?
	 *   We can maintain the current [mn, mx] valid range per node during recursion
	 */
	bool is_bst1(int mn = INT_MIN, int mx = INT_MAX) {
		bool status = mn < data && data < mx;

		if (!status)
			return false;

		bool left_bst = !left || left->is_bst1(mn, data);

		if(!left_bst)
			return false;

		bool right_bst = !right || right->is_bst1(data, mx);
		return right_bst;
	}

	bool is_bst2() {
		// Check inorder traversal is sorted (and unique)!
		vector<int> values;
		get_inorder(values);

		for (int i = 1; i < (int) values.size(); ++i) {
			if (values[i] < values[i - 1])
				return false;
		}
		return true;
	}
























	// The idea is to keep doing inorder traversal in the tree
	// but maintain &k to know if you find it
	// Order is O(n)
	// The interesting inside idea is doing this partial inorder traversal

	// Another way: If the tree has for each node count for how many nodes in its tree
	// we can get answer in O(h)
	int kth_smallest(int &k) {
		if (k == 0)
			return -1234;

		if (left) {
			int res = left->kth_smallest(k);
			if (k == 0)
				return res;
		}

		--k;	// for current node
		if (k == 0)
			return data;

		if (right)
			return right->kth_smallest(k);

		return -1234;
	}






















	int lca(int x, int y) {
		// if both on left or right subtree, then lca must be in the subtree
		// otherwise this node is lca: x is in a branch and y in another
		if (x < data && y < data)
			return left->lca(x, y);

		if (x > data && y > data)
			return right->lca(x, y);

		return data;
	}
	//Tip: to find the path between any 2 nodes: you get their lca
	//then path (lca, a) + path(lca, b)

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

BinarySearchTree* build_balanced_bst_tree(vector<int> &values, int start = 0, int end = -10) {
	if (end == -10)
		end = (int) values.size() - 1;

	if (start > end)
		return nullptr;

	// The best root for N sorted numbers is their middle number
	// as N/2 numbers before and after. Keep applying recursively
	int mid = (start + end) / 2;
	BinarySearchTree *left = build_balanced_bst_tree(values, start, mid - 1);
	BinarySearchTree *right = build_balanced_bst_tree(values, mid + 1, end);
	BinarySearchTree *root = new BinarySearchTree(values[mid], left, right);

	return root;
}

void build_bst() {
	vector<int> values = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	BinarySearchTree* tree = build_balanced_bst_tree(values);
	values.clear();
	tree->get_inorder(values);
	assert(tree->is_bst1());

	tree->level_order_traversal2();
}

void kth() {
	BinarySearchTree* tree = GetTree();

	for (int k = 1; k <= 15; ++k) {
		int t = k;
		cout << tree->kth_smallest(t) << "\n";
	}
}
void lca() {
	BinarySearchTree* tree = GetTree();

	cout << tree->lca(35, 60) << "\n";
	cout << tree->lca(14, 16) << "\n";
	cout << tree->lca(70, 73) << "\n";
}


int main() {
	build_bst();

	cout << "bye\n";

	return 0;
}

