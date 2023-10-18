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
	trie suffix_tree;

	WordFilter(vector<string>& words) {
		set<string> words_set;

		// Many words are duplicate. Let's only keep ones with high index
		// Use set to filter existing ones
		for (int i = (int) words.size() - 1; i >= 0; --i) {
			if (words_set.insert(words[i]).second) {
				// Insert the word (normal prefix)
				prefix_tree.insert(words[i], i);

				// reverse word, then when inserted it act like suffix (1)
				reverse(words[i].begin(), words[i].end());
				suffix_tree.insert(words[i], i);
			}
		}
	}

	int f(string prefix, string suffix) {
		// Find positions of prefix and suffix, then intersect results and return biggest
		vector<int> pre_list = prefix_tree.get_positions(prefix);

		reverse(suffix.begin(), suffix.end());
		vector<int> suf_list = suffix_tree.get_positions(suffix);

		// As indices inserted from big to small, next lines sort and intersect using C++ STL
		reverse(pre_list.begin(), pre_list.end());
		reverse(suf_list.begin(), suf_list.end());

		vector<int> common_data;	// It will contain all intersection between both
		set_intersection(pre_list.begin(), pre_list.end(), suf_list.begin(), suf_list.end(), back_inserter(common_data));

		if (common_data.size() == 0)
			return -1;
		return common_data.back();
	}
};

int main() {

	vector<string> v {"abaa", "ab"};
	WordFilter filter(v);
	cout << filter.f("ab","abaa") << "\n";

	return 0;
}
