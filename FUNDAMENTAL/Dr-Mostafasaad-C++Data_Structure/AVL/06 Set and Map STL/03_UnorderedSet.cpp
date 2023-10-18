#include<iostream>
#include<unordered_set>
#include<set>
#include<algorithm>		// find
using namespace std;

int main() {
	unordered_set<int> s1 {20, 10, 20, 5, 30};

	s1.insert(7);
	s1.insert(0);

	for (auto v : s1)
		cout << v << " ";
	cout << "\n";	// 0 7 20 10 5 30 : removed duplicates

	// If container has a method use it,
	// 		as it considers the internal representation
	auto it1 = s1.find(20);	// FAST
	cout << *it1 << "\n";
	//*it = 20;		// CAN'T change

	// generic algorithms iterate in generic/same way.
	// 		No idea about internal representation
	auto it2 = find(s1.begin(), s1.end(), 20);	// SLOW
	cout << *it2 << "\n";

	cout<<s1.size()<<"\n";	// 6
	s1.erase(s1.begin());
	cout<<s1.size()<<"\n";	// 5
	////////////////////////////////////////////

	int arr[] {20, 10, 20, 5, 30, 7, 0};
	unordered_set<int> s2(arr, arr+3);

	s1.swap(s2); // swapping operation: 0 7 30 5 10 20

	set<int> sorteds(s1.begin(), s1.end());	// 5 7 10 20 30
	////////////////////////////////////////////
	// No reverse iterator
	// unordered_multiset: same but allows duplicates
	// In general most operations are fast
	// Based on HashTable.
	// In datastructures course you learn how to use efficiently



	return 0;
}
