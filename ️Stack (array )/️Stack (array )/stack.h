#pragma once
const int size = 5;
class stack {
	int s[::size];
	int length;
public:
	stack();
	bool is_empty() const;
	bool is_full() const;
	bool push(int el);
	bool pop();
	bool top(int& el) const;
	void print_fromBottom() const;
	void print_fromTop() const;
	void clear();
	int stack_length();
	int search(int el);
	void copy(stack& a, stack& b);
	void deleteGreaterThan(int el);
	void deleteUsingPop();
	void keepEventOnly();
	void deleteSmallest_All();
	void deleteFirstSmallest();
	void moveTopToBottom();
	void reverseStack_useTmpStack();
	void reverseStack_NoTmpStack();//Recursion
	void swapTopBottom();
};