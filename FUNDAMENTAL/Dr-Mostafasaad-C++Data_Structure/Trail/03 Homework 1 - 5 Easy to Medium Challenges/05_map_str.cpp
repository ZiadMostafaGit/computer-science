#include<iostream>
#include <vector>
#include<map>
using namespace std;

class trie {
private:
	// The major change: instead of letter on edge, it will be a string
	map<string, trie*> child;

	bool isLeaf { };

public:
	trie() {
	}

	void insert(const vector<string> &path) {
		trie* cur = this;

		for (int idx = 0; idx < (int) path.size(); ++idx) {
			if (!cur->child.count(path[idx]))
				cur->child[path[idx]] = new trie();
			cur = cur->child[path[idx]];
		}
		cur->isLeaf = true;
	}

	bool subpath_exist(const vector<string> &path) {
		trie* cur = this;

		for (int idx = 0; idx < (int) path.size(); ++idx) {
			if (!cur->child.count(path[idx]))
				return false;	// such path don't exist
			cur = cur->child[path[idx]];
		}
		return true;
	}
};


int main() {
	trie tree;

	vector<string> path;

	path = {"home", "software", "eclipse"};
	tree.insert(path);

	path = {"home", "software", "eclipse", "bin"};
	tree.insert(path);

	path = {"home", "installed", "gnu"};
	tree.insert(path);

	path = {"user", "mostafa", "tmp"};
	tree.insert(path);

	path = {"user", "mostafa", "tmp"};
	cout << tree.subpath_exist(path) << "\n"; // 1

	path = {"user", "mostafa"};
	cout << tree.subpath_exist(path) << "\n"; // 1

	path = {"user", "mostafa", "private"};
	cout << tree.subpath_exist(path) << "\n"; // 0

	return 0;
}
