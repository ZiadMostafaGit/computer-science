#include<iostream>
#include<map>
using namespace std;

void print(const map<string, int> &mp) {
	for (const pair<string, int> &item : mp)
		cout << item.first << "-" << item.second << " | ";
	cout << "\n";
}

int main() {
	// Think like array, but index is object
	map<string, int> mp;
	mp["mostafa"] = 10;
	mp["Saad"] = 20;
	mp["mostafa"] = 30;
	mp["Mostafa"] = 40;

	print(mp);	// Mostafa-40 | Saad-20 | mostafa-30 |

	cout << mp.count("Mostafa") << "\n";	// 1

	cout << mp["mostafa"] << "\n";

	return 0;
}
