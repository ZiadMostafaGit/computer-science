#include<iostream>
#include<algorithm>		// reverse
#include<vector>
#include<cstring>	// memset
using namespace std;

class trie {
private:
	static const int MAX_CHAR = 26;
	trie* child[MAX_CHAR];
	bool isLeaf { };

public:
	trie() {
		// set an array to 0s. Here pointers to null
		memset(child, 0, sizeof(child));
	}

	// by reversing a string, we can trivially check for suffixes!

	void insert(string str) {
		reverse(str.begin(), str.end());

		trie* cur = this;

		for (int idx = 0; idx < (int) str.size(); ++idx) {
			int ch = str[idx] - 'a';
			if (!cur->child[ch])
				cur->child[ch] = new trie();
			cur = cur->child[ch];
		}
		cur->isLeaf = true;
	}

	bool suffix_exist(string str) {
		reverse(str.begin(), str.end());
		trie* cur = this;

		for (int idx = 0; idx < (int) str.size(); ++idx) {
			int ch = str[idx] - 'a';
			if (!cur->child[ch])
				return false;	// such path don't exist
			cur = cur->child[ch];
		}
		return true;
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

	cout << root.suffix_exist("cd") << "\n";
	cout << root.suffix_exist("cc") << "\n";

	return 0;
}
