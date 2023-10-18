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

	void print_all_matches(const string &str, int starting_pos = 0) {
		trie* cur = this;

		for (int idx = starting_pos; idx < (int) str.size(); ++idx) {
			int ch = str[idx] - 'a';
			if (!cur->child[ch])
				return;
			cur = cur->child[ch];

			if (cur->isLeaf)
				cout << str.substr(starting_pos, idx - starting_pos + 1) << "\n";
		}
	}
};

/*
 * Reverse thinking using trie.
 *
 * Add the queries themselves to the trie
 *
 * For the string, generate all its suffixes
 * For each suffix, iterave over the trie and print all words you meet.
 * These words are prefixes of this suffix ==> are sub-strings from original string
 */
void list_substrs(const string& str, vector<string> &queries) {
	trie tree;

	// O(QL)
	for (int i = 0; i < (int) queries.size(); ++i)
		tree.insert(queries[i]);

	// O(SL): observe, we won't iterate in the tree MORE than L steps
	for (int i = 0; i < (int) str.size() - 1; ++i)
		tree.print_all_matches(str, i);

	// total: O(QL + SL) vs previsouly O(QL + SS)
}

int main() {
	vector<string> queries { "xy", "ab", "t", "yz" };
	list_substrs("heyabcdtwxyw", queries);

	return 0;
}
