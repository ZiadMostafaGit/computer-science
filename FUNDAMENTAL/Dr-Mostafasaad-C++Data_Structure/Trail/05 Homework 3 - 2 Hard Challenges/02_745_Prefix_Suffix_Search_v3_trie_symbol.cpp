// https://leetcode.com/problems/prefix-and-suffix-search
#include<iostream>
#include<vector>
#include<set>
#include<algorithm>
#include<cstring>	// memset
using namespace std;

class trie {
private:
	static const int MAX_CHAR = 26 + 1;
	trie* child[MAX_CHAR];
	int index {-1};		// If exist, don't override

public:
	trie() {
		memset(child, 0, sizeof(child));
	}

	void insert(const string &str, int word_idx) {
		trie* cur = this;

		for (int idx = 0; idx < (int) str.size(); ++idx) {
			int ch = str[idx] - 'a';
			if (str[idx] == '$')
				ch = MAX_CHAR - 1;
			if (!cur->child[ch])
				cur->child[ch] = new trie();
			if(cur->child[ch]->index == -1)
				cur->child[ch]->index = word_idx;
			cur = cur->child[ch];
		}
	}

	int get_positions(const string &str) {
		trie* cur = this;

		for (int idx = 0; idx < (int) str.size(); ++idx) {
			int ch = str[idx] - 'a';
			if (str[idx] == '$')
				ch = MAX_CHAR - 1;
			if (!cur->child[ch])
				return -1;
			cur = cur->child[ch];
		}
		return cur->index;
	}
};

class WordFilter {
public:
	trie prefix_tree;

	WordFilter(vector<string>& words) {
		set<string> words_set;

		// Generate all pairs of suffix/prefix
		// But, trie already generate all prefixes, so generate suffixes + one prefix
		// Use unique symbol to differentiate suffix from prefix (otherwise a word is unclear)
		// As we create more words (n^2), this solution needs more memory
		// But it queries in faster time!
		for (int i = (int) words.size() - 1; i >= 0; --i) {
			if (words_set.insert(words[i]).second) {

				string suffix;
				for (int j = (int)words[i].size()-1; j >= 0; --j) {
					suffix = words[i][j] + suffix;
					string new_word = suffix + "$" + words[i];
					prefix_tree.insert(new_word, i);
				}
			}
		}
	}

	int f(string prefix, string suffix) {
		string new_word = suffix + "$" + prefix;
		return prefix_tree.get_positions(new_word);
	}
};

int main() {

	vector<string> v { "apple"};
	WordFilter filter(v);
	cout << filter.f("a", "e") << "\n";

	return 0;
}
