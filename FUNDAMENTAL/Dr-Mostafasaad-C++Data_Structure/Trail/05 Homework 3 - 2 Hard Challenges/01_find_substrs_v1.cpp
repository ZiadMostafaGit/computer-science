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

	void insert(const string &str, int starting_pos = 0) {
		trie* cur = this;

		for (int idx = starting_pos; idx < (int) str.size(); ++idx) {
			int ch = str[idx] - 'a';
			if (!cur->child[ch])
				cur->child[ch] = new trie();
			cur = cur->child[ch];
		}
		cur->isLeaf = true;
	}

	bool prefix_exist(string str) {
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

void list_substrs(const string& str, vector<string> &queries) {
	trie tree;
	// Generate all suffixes and add
	// O(S^2): S string length
	for (int i = 0; i < (int)str.size()-1; ++i)
		tree.insert(str, i);	// suffix starting at i


	// O(QL)	queries x string length
	for (int i = 0; i < (int)queries.size(); ++i) {
		if(tree.prefix_exist(queries[i]))
			cout<<queries[i]<<"\n";
	}
	// Total: O(S^2 + QL)
}


int main() {
	vector<string> queries {"xy", "ab", "t", "yz"};
	list_substrs("heyabcdtwxyw", queries);

	return 0;
}
