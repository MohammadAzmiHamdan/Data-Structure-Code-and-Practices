#include"BST.h"
#include<iostream>
using namespace std;
int main() {
	tree t;
	t.add(6);
	t.add(8);
	t.add(3);
	t.add(4);
	t.add(2);
	t.add(7);
	t.add(9);

	cout << t.is_empty() << endl;
	t.preorder();
}