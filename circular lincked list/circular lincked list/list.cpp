#include"list.h"
#include<iostream>
using namespace std; 
list::list()
{
	tail = 0;
	

}
void list::add_begin(int el) {
	if (tail == 0) {

		tail->next = tail = new node(el);


	}
	else
	tail->next = new node(el, tail->next);

}
void list::print() {
	if (tail != 0) {/*node* t = tail->next;
	for (;t!= tail;t = t->next)
		cout << t->data << " ";
	cout << t->data << endl;*/
		node* t = tail->next;

		do {
			cout << t->data << " ";
			t = t->next;
		} while (t != tail->next);
		cout << endl;
	}
}
bool list::delete_end() {

	if (tail == 0)
		return false;

	if (tail == tail->next)
	{
		delete tail; tail = 0;
	}
	else {
		node* t = tail->next;
		for (;t->next != tail;t = t->next);
		t->next = tail->next;
		delete tail;
		tail = t;
	}return true;
}

