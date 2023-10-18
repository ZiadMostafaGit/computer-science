// https://leetcode.com/problems/prefix-and-suffix-search
#include<iostream>
#include<vector>
#include<set>
#include<algorithm>
#include<cstring>	// memset
using namespace std;

class trie {
private:
	static const int MAX_CHAR = 26;
	trie* child[MAX_CHAR];
	// List of indices of prefixes inserted here
	vector<int> indices;

public:
	trie() {
		memset(child, 0, sizeof(child));
	}

	void insert(const string &str, int word_idx) {
		trie* cur = this;

		for (int idx = 0; idx < (int) str.size(); ++idx) {
			int ch = str[idx] - 'a';
			if (!cur->child[ch])
				cur->child[ch] = new trie();
			cur->child[ch]->indices.push_back(word_idx);
			cur = cur->child[ch];
		}
	}

	vector<int> get_positions(const string &str) {
		vector<int> positions;
		trie* cur = this;

		for (int idx = 0; idx < (int) str.size(); ++idx) {
			int ch = str[idx] - 'a';
			if (!cur->child[ch])
				return vector<int>();
			cur = cur->child[ch];
		}
		return cur->indices;	// always sorted if insertion is sorted indices
	}
};

class WordFilter {
public:
	trie prefix_tree;
	vector<string> words_original;

	WordFilter(vector<string>& words) {
		words_original = words;
		set<string> words_set;

		// Many words are duplicate. Let's only keep ones with high index
		// Use set to filter existing ones
		for (int i = (int) words.size() - 1; i >= 0; --i) {
			if (words_set.insert(words[i]).second) {
				// Insert the word (normal prefix)
				prefix_tree.insert(words[i], i);
			}
		}
	}

	bool is_suffix(string str, string suf) {
		if (suf.size() > str.size())
			return false;

		for (int i = (int) suf.size() - 1, str_i = (int) str.size() - 1; i >= 0; --i, --str_i) {
			if (str[str_i] != suf[i])
				return false;
		}
		return true;
	}

	int f(string prefix, string suffix) {
		// Find all positions that are prefix (larege to small index)
		vector<int> pre_list = prefix_tree.get_positions(prefix);

		for (int i = 0; i < (int) pre_list.size(); ++i) {
			int pos = pre_list[i];
			if (is_suffix(words_original[pos], suffix))
				return pos;
		}
		return -1;
	}
};

int main() {

	vector<string> v { "apple"};
	WordFilter filter(v);
	cout << filter.f("a", "e") << "\n";

	return 0;
}
