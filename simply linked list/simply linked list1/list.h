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
	node* head, * tail;
public:
	list();
	~list();
	void operator=(list& o);
	list(list& o);
	bool is_empty();
	void add_begin(int el);
	void add_end(int el);
	bool add_pos(int el, int pos);
	void print();
	void add_sorted(int el);
	bool delete_begin();
	bool delete_end();
	bool delete_pos(int pos);
	bool delete_el(int el);
	int search(int el);
	int size();
	/*=======*/
	bool add_avg_before_first_positive();

	//bool Add_after_maximum_element(int el);
	bool Move_minimum_to_front();
	bool Add_after_first_odd(int el);
	bool Delete_before_last_even();
	void delete_odds();
	bool delete_negative();
	bool delete_befor_max();
		bool delete_after_min();
		bool Add_after_maximum_element(int el);
		bool add_befor_min(int el);

		void print_back(node* t);
		void print_back();

};

