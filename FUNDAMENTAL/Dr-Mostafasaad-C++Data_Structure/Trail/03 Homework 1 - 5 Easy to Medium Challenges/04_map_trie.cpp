#include<iostream>
#include <unordered_map>
#include<map>
using namespace std;

class trie {
private:
	map<int, trie*> child;	// based on self-balancing BST, so keys are sorted (which is logn), which usually not important

	//unordered_map<int, trie*> child;  // This is based on hashing, O(1), but keys are not sorted
	bool isLeaf { };

public:
	trie() {
	}

	void insert(string str) {
		trie* cur = this;

		for (int idx = 0; idx < (int) str.size(); ++idx) {
			int ch = str[idx] - 'a';
			if (!cur->child.count(ch))
				cur->child[ch] = new trie();
			cur = cur->child[ch];
		}
		cur->isLeaf = true;
	}

	bool word_exist(string str) {
		trie* cur = this;

		for (int idx = 0; idx < (int) str.size(); ++idx) {
			int ch = str[idx] - 'a';
			if (!cur->child.count(ch))
				return false;	// such path don't exist
			cur = cur->child[ch];
		}
		return cur->isLeaf;
	}
};


int main() {
	trie root;

	root.insert("abcd");
	root.insert("xyz");
	root.insert("abf");
	root.insert("xn");
	root.insert("ab");
	root.insert("bcd");

	cout << root.word_exist("xyz") << "\n";
	cout << root.word_exist("xy") << "\n";

	return 0;
}
