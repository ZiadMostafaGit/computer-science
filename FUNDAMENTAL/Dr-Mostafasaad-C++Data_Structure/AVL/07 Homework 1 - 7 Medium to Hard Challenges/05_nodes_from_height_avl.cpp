#include<iostream>
#include<queue>
#include<cassert>
#include<algorithm>
using namespace std;

int avl_nodes_rec(int height) {
	if (height == 0)
		return 1;
	if (height == 1)
		return 2;

	return 1 + avl_nodes_rec(height - 1) + avl_nodes_rec(height - 2);
}

int avl_nodes_iter(int height) {
	if (height == 0)
		return 1;
	if (height == 1)
		return 2;

	height--;
	int a = 1, b = 2, c;
	while(height--)
		c = a + b + 1, a = b, b = c;

	return c;
}

int main() {
	for (int i = 0; i < 50; ++i) {
		cout << i << " " << avl_nodes_iter(i) << "\n" << flush;
	}

	return 0;
}


// Optional reading about: The worst case height of an AVL tree with n nodes is 		1.44logn
// http://lcm.csa.iisc.ernet.in/dsa/node112.html
// https://oeis.org/A000071
// oeis is a site that can help with sequences. keep in notes for programming competitions

