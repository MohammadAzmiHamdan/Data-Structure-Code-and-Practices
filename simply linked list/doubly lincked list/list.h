#pragma once
struct node {
	int data; 
	node* next;
	node* prev;
	node(int d, node* p = 0, node* n = 0) {
		data = d; 
		next = n;
		prev = p;
	}



};
class list {
	node* head;
public:
	list();
	bool is_empty();
	void add_begin(int el);
	void print_f();
	void print_b();
	bool add_pos(int el, int pos);
	bool delete_end();
	bool delete_pos(int pos);
	int size();
	void add_end(int el);
	bool delete_begin();


};