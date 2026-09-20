#pragma once
const int Size = 5;
enum error{overflow,out,success,underflow};

template <class t>
class list {

	t l[Size];
	int length;
public:
	list();
	~list();
	bool is_empty();
	bool is_full();
	void print();
	void add_begin(t el);
	bool add_end(t el);
	error add_pos(t el, int pos);//bool ->>enum
	bool add_sorted(t el);
	bool delete_begin();
	bool delete_end();
	error delete_pos(int pos);//bool =>> enum
	error delete_el(t el);
	int search(t el);//bool-->int

	//from me : 
	void add_position(t element, int poition);
};