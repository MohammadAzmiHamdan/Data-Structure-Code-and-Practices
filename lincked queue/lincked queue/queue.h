#pragma once
struct node {
	int data;
	node* next;
	node(int d, node* n=0) {
		data = d;
		next = n;
	}

};
class queue {
	node* front, * rear;
public: 
	queue();
	bool is_empty() const;
	void append(int el);
	bool serve();
	bool retrieve(int& el);
	void clearQueue();
	const queue& operator= (const queue& o);
	queue(queue& o);
	~queue();
};
