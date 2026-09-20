#include"list.h"
#include<iostream>
using namespace std;
list::list() {
	head = 0;
}
bool list::is_empty() {

	return head == 0;



}
void list::add_begin(int el) {
	if (is_empty())
		head = new node(el);
	else {
		head=head->prev=new node(el, 0, head);


	}


}
void list::print_f() {
	if (head != 0) {/*node* t = head;
	for (;t != 0;t = t->next)
		cout << t->data << " ";
	cout << endl;*/
		for (;head->next != 0;head = head->next)
			cout << head->data << " ";
		cout << head->data << endl;

		for (;head->prev != 0;head = head->prev);
	}
}
void list::print_b() {
	if (head != 0) {
		/*node* t = head;
		for (;t->next != 0;t = t->next);
		for (;t != 0;t = t ->prev)
			cout << t->data << "\t";
		cout << endl;*/
	for (;head->next != 0;head = head->next);
	for(;head->prev!=0;head=head->prev)
	cout<<head->data<<"\t";
	cout<<head->data<<endl;
	
	}



}
int list::size() {
	int count = 0;
	node*t = head;
	for (;t != 0;t = t->next) {
		count++;
	}return count;

}

void list::add_end(int el) {
	if (is_empty())
		add_begin(el);
	if (head->next == 0)
		head->next = new node(el,head);
	else {
		node*t= head;
		for (; t->next != 0;t = t->next);
		t->next=new node(el, t);



	}
}


bool list::add_pos(int el, int pos) {
	if (is_empty())
		return false;
	if (pos<1 || pos>size()+1)
		return false;
	if (pos == 1)
		add_begin(el);
	else 
		if (pos == size() + 1)
		add_end(el);

	else {
		node* t = head;
		for (int i = 1;i < pos - 1;i++) {
			t = t -> next;
		}
		t->next=t->next->prev = new node(el, t, t->next);

	}
	return true;

}

bool list::delete_begin() {
	if (is_empty())return false;
	if (head->next == 0)
	{
		delete head;
		head = 0;
	}
	else {
		node* t = head;
		head->next->prev = 0;
		head = head->next;
		delete t;

	}
	return true;
}

bool list::delete_end() {
	if (is_empty())return false;
	if (head->next == 0)
	{
		delete head;
		head = 0;
	}
	else {
		node* t = head;
		for (;t->next->next != 0;t = t->next);
		delete t->next;
		t->next = 0;
	}
	return true;
}
bool list::delete_pos(int pos) {
	if (is_empty())return false;
	if (pos<1 || pos>size())
		return false;
	if (pos == 1)delete_begin();
	else if (pos == size())delete_end();
	else {
		node* t = head;
		for (int i = 1;i < pos;i++)
			t = t->next;
		t->prev->next = t->next;
		t->next->prev = t->prev;
		delete t;


	}

	return true;
}
