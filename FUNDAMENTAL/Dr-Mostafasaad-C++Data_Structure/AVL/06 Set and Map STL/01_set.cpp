#include<iostream>
#include<set>
#include<algorithm>
using namespace std;

void print(set<int> &v) {
	for (int x : v)
		cout << x << " ";
	cout << "\n";
}

int main() {
	set<int> st;				// Sorted & unique
	st.insert(50);
	st.insert(25);
	st.insert(25);
	st.insert(25);
	st.insert(7);

	print(st);	// 7 25 50

	if (st.count(25))
		cout << "YES\n";

	return 0;
}
