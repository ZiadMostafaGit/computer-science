// https://leetcode.com/problems/replace-words/
#include<iostream>
#include<vector>
#include<cstring>	// memset
#include<sstream>
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

	void insert(string str, int idx = 0) {
		if (idx == (int) str.size())
			isLeaf = 1;
		else {
			int cur = str[idx] - 'a';
			if (child[cur] == 0)
				child[cur] = new trie();
			child[cur]->insert(str, idx + 1);
		}
	}

	string first_word_prefix(const string &str) {
		trie* cur = this;

		for (int idx = 0; idx < (int) str.size(); ++idx) {
			int ch = str[idx] - 'a';
			if (!cur->child[ch])
				break;

			// Does this child marked as word? we forund a prefix that is a word
			if (cur->child[ch]->isLeaf)
				return str.substr(0, idx+1);
			cur = cur->child[ch];
		}
		return str;
	}
};

class Solution {
public:
	trie tree;

	// Given a string, split to vector of strings
	vector<string> split(string str) {
		vector<string> ret;
		string word;
		istringstream iss(str);

		while (iss >> word)
			ret.push_back(word);
		return ret;
	}

    string replaceWords(vector<string>& dictionary, string sentence) {
    	for (int i = 0; i < (int)dictionary.size(); ++i)
			tree.insert(dictionary[i]);

    	// Split, map each word, and concatenate
    	vector<string> words = split(sentence);
    	string result;

    	for (int i = 0; i < (int)words.size(); ++i) {
			if(i)
				result += " ";
			result += tree.first_word_prefix(words[i]);
		}

    	return result;
    }
};

int main() {
	trie root;

	root.insert("xyz");
	root.insert("xyzwfe");



	cout << root.first_word_prefix("xyeee") << "\n";

	return 0;
}
