#pragma 
struct node {
	node* next;
	int data;
	node(int d, node* n = 0) {
		data = d;
		next = n;
	}

 };
class stack {
	node* top_p;
public:
	stack();
	~stack();
	stack(stack& o);
	stack& operator=(stack& o);
	void push(int el);
	bool pop();
	bool top(int& el);
	void print() const;
	bool is_empty() const;
	int Size() const;
	void clear();
	bool bottom(int& el) const;
	bool contains(int value) const;
	void duplicateTop();
	void swapTop();
	void reverse();
	int sum();
	double average();
	void removeFristSameElement(int value);
	void removeAllSameElement(int value);
	void printReverse() ;
};