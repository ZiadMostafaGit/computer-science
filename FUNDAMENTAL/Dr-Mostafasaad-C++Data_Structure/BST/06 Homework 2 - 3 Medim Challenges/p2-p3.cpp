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


	// Simple idea: Just change the original inorder traversal to catch the next successor
	// We can even extend same code to catch all queries, but they must be sorted!
	// Note: traversal here is incomplete inorder traversal. It will have only search visited elements
	void successor_queries(deque<int> & queries, vector<int> &answer, vector<int> &traversal) {
		if (queries.empty())
			return;

		if (left && queries.front() < data) {
			left->successor_queries(queries, answer, traversal);

			if (queries.empty())
				return;
		}

		// If the last element added in the traversal is the requested element
		// Then the current element is its successor! Catch it! That simple!
		if (!traversal.empty() && traversal.back() == queries.front()) {
			answer.push_back(data);
			queries.pop_front();

			if (queries.empty())
				return;
		}
		traversal.push_back(data);

		// Observe the = : If target equal the cur data and we have right, then successor on right
		// Trace the root (e.g. 50)
		if (right && queries.front() >= data)
			right->successor_queries(queries, answer, traversal);
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

void successor() {
	BinarySearchTree* tree = GetTree();

	if (true) {	// one by one
		vector<int> v { 14, 15, 16, 20, 35, 36, 45, 50, 58, 60, 70, 73 };

		for (int i = 0; i < (int) v.size(); ++i) {
			cout << v[i] << " ";
			deque<int> q;
			sort(q.begin(), q.end());
			vector<int> answer;
			vector<int> traversal;

			q.push_back(v[i]);
			tree->successor_queries(q, answer, traversal);

			if (answer.size())
				cout << answer[0] << "\n";
			else
				cout << "*\n";
		}
	} else {
		deque<int> q { 20, 14, 35, 50, 60, 70, 73 };
		sort(q.begin(), q.end());
		deque<int> cpy = q;

		vector<int> answer;
		vector<int> traversal;

		tree->successor_queries(q, answer, traversal);

		if (answer.size() < cpy.size())
			answer.push_back(-1234);	//no successor case

		for (int i = 0; i < (int) cpy.size(); ++i) {
			cout << cpy[i] << " " << answer[i] << "\n";
		}
	}
}


bool is_degenerate(vector<int> &preorder) {
	// We need each child to have 1 node only
	// Assume we have a degenerate of 5 nodes and we want to add another node
	// Then this node must start from root and keep moving tell the leaf node
	// It means at any stage it must respect specific [min, max] range to not create 2 children
	// The idea: for each node, we maintain what is the only valid range
	// Assume the last value is 300 and next value is 700
	// it means 700 on its right side and from now on, any new node must be >= 701 to arrive as a leaf
	
	// The more of solution: if degenerate is branch, we can compute [mn, mx] per node for validation 
	if (preorder.size() <= 2)
		return true;

	int mn = 1, mx = 1000;

	// Validate the generate branch is always fitting with updated range
	for (int i = 1; i < (int) preorder.size(); ++i) {
		if (preorder[i] < mn || preorder[i] > mx)
			return false;

		if (preorder[i] > preorder[i - 1])	// on its right subtree: so I am smaller than all next
			mn = preorder[i - 1] + 1;	// must be smaller than previous mn, we checked for interval
		else
			mx = preorder[i - 1] - 1;
	}
	return true;
	// Other approaches: https://www.geeksforgeeks.org/check-if-each-internal-node-of-a-bst-has-exactly-one-child/
}

void is_degenerate_test() {
	vector<int> a;

	a = {25, 8, 11, 13, 12};
	assert(is_degenerate(a));

	a = {100, 70, 101};
	assert(!is_degenerate(a));

	a = {100, 70, 60, 75};
	assert(!is_degenerate(a));

	a = {100, 70, 60, 65};
	assert(is_degenerate(a));

	a = {1, 2, 3, 4, 5, 6, 7, 8, 9};
	assert(is_degenerate(a));

	a = {9, 8, 7, 6, 5, 4, 3, 2, 1};
	assert(is_degenerate(a));

	a = {500, 400, 300, 200 , 250 , 275, 260};
	assert(is_degenerate(a));

	a = {500, 400, 300, 200 , 250 , 275, 260, 280};
	assert(!is_degenerate(a));
}

int main() {
	is_degenerate_test();

	cout << "bye\n";

	return 0;
}

