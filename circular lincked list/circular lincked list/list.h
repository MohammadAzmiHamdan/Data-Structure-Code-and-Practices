#pragma once
struct node {
	int data;
	node* next;
	node(int d, node* n = 0) {
		data = d;
		next = n;
	}
};
class list {
	node* tail;
public:
	list();
	void add_begin(int el);
	void print();
	bool delete_end();





};