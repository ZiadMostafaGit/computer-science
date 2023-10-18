#include<iostream>
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

	void insert(string str) {
		trie* cur = this;

		for (int idx = 0; idx < (int) str.size(); ++idx) {
			int ch = str[idx] - 'a';
			if (!cur->child[ch])
				cur->child[ch] = new trie();
			cur = cur->child[ch];
		}
		cur->isLeaf = true;
	}

	// O(NL) where N number of words and L is word length.
	void get_all_strings(vector<string> &res, string cur_str = "") {
		if (isLeaf)
			res.push_back(cur_str);

		for (int i = 0; i < MAX_CHAR; ++i)
			if (child[i])
				child[i]->get_all_strings(res, cur_str + (char) (i + 'a'));
	}

};

int main() {
	trie tree;

	tree.insert("abcd");
	tree.insert("xyz");
	tree.insert("a");
	tree.insert("ab");
	tree.insert("xyzw");
	tree.insert("bcd");

	vector<string> res;
	tree.get_all_strings(res);
	for (int i = 0; i < (int) res.size(); ++i)
		cout << res[i] << "\n";

	return 0;
}
