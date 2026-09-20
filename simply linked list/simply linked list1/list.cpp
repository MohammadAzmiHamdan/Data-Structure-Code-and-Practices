#include "list.h"
#include <iostream>
using namespace std;
list::list() {
	head = tail = 0;

}
bool list::is_empty() {
	return head == 0;
}
void list::add_begin(int el) {
	if (is_empty()) {
		head = tail = new node(el);
	}
	else {
		head = new node(el, head);
	}

}
void list::add_end(int el) {
	if (is_empty())
		head = tail = new node(el);
	else {
		tail = tail->next = new node(el);

	}
}
void list::print() {


	for (node* temp = head;temp != 0;temp = temp->next)
		cout << temp->data << "\t"<<temp->next <<endl;



}
int list::size() {
	int c = 0;
	for (node* temp = head;temp != 0;temp = temp->next) {
		c++;

	}
	return c;
}


bool list::delete_begin() {
	if (is_empty())
		return false;
	if (head->next == 0)//or if(size()==1 )//if( or head==tail )
	{
		delete head;
		
		head = tail = 0;
	}
	else {
		node* tmp = head;//store the head 
		head=head->next;//move the head 
		delete tmp;//delete the old head or place



	}
	return true;

}


bool list::delete_end() {
	if (is_empty())
		return false;
	if (head->next == 0)
	{
		delete_begin();
	}
	else {
		node* tmp ;
		for (tmp = head;tmp->next != tail; tmp = tmp->next);
		delete tail;
		tail = tmp;
		tail->next = 0;
		/*
		tail=tmp;
		delete tail->next;
		tail->next=0;
		
		*/

	}
	return true;

}

bool list::add_pos(int el, int pos) {
	if (pos<1 || pos>size() + 1)
		return false;
	if (pos == 1)
		add_begin(el);
	else if (pos == size() + 1)
		add_end(el);
	else {
		node* t1;
		t1 = head;
		for (int i = 1;i < pos - 1;i++, t1 = t1->next);
		t1->next = new node(el, t1->next);
	}
	return true;
}

bool list::delete_pos(int pos) {
	if (is_empty())
		return false;
	if (pos<1 || pos>size())
		return false;
	if (pos == 1)
	{
		delete_begin();
		return true;

	}
	else if (pos == size())
	{
		delete_end();return true;

	}
	else {
		node* t1, *t2;
		t1 = head;
		for (int i = 1  ;i< pos - 1;  i++, t1 = t1->next);
		t2 = t1->next;
		t1->next = t2->next;
		delete t2;
		/*node* t1, * t3;
		t1 = head;
		for (int i = 1;i < pos - 1;i++, t1 = t1->next);
		t3 = t1->next->next;
		delete t1->next;
		t1->next = t3;*/


		/*node* t1, * t2, * t3;
		t1 = head;
		for (int i = 1;i < pos - 1;i++, t1 = t1->next);
		t2 = t1->next;
		t3 = t2->next;
		t1->next = t3; 
		delete t2;*/
	}
	return true;
}

int list::search(int el) {
	node* tmp = head;
	int count = 1;
	for (; tmp != nullptr; tmp = tmp->next) {
		if (el == tmp->data)
			return count;
		count++;
	}
	return -1;
}


bool list::delete_el(int el) {
	if (is_empty())
		return false;
	int position = search(el);
	if (position == -1)
		return false;

	return delete_pos(position);
}

void list::add_sorted(int el) {
	if (is_empty()) {
		add_begin(el);
	}
	else if (head->data > el) {
		add_begin(el);
	}
	else if (tail->data < el) {
		add_end(el);
	}
	else {
		


		node* tmp = head;
		int count = 1;
		for (; tmp !=nullptr; tmp = tmp->next) {
			
			if (el < tmp->data) {
				add_pos(el, count);
				break;
			}
			count++;
		}


		/*node* t = head;
		int i = 1;
		for ( ; ( (t != 0) && ( t->data < el) ) ; t = t->next,i++);
		add_pos(el, i);*/

		/*node* t = head;
        int i = 1;
       while (t != nullptr && t->data < el) { 
             t = t->next;
                 i++;
            }
        add_pos(el, i);*/

	}
}


list::~list() {
	
		while (!is_empty())
			delete_begin();

		cout << "\ndestructor worked\n";
}
void list::operator=(list & o){
	while (!is_empty())
		delete_begin();
	if (!o.is_empty())
	{
		node* t1, * t2;
		t1 = o.head;
		t2 = head = new node(t1->data);
		while (t1->next != 0) {
			t1 = t1->next;
			t2->next = new node(t1->data);
			t2 = t2->next;
		}tail = t2;


	}
	else tail = head = 0;

}
list::list(list &o) {

	if (!o.is_empty())
	{
		node* t1, * t2;
		t1 = o.head;
		t2 = head = new node(t1->data);
		while (t1->next != 0) {
			t1 = t1->next;
			t2->next = new node(t1->data);
			t2 = t2->next;
		}tail = t2;


	}
	else tail = head = 0;

}

bool list::add_avg_before_first_positive() {
	if (head == 0)
		return false;
	node* tmp = head; int count = 0, sum = 0;double avg = 0;
	while (tmp != nullptr) {
		count++;
		sum += tmp->data;
		tmp = tmp->next;

	}avg = (double)sum / count;
	tmp = head;
	node* pre = nullptr;
	if (tmp->data >= 0) {
		add_begin(avg);
		return true;
	}
	while (tmp->next != nullptr && tmp->data < 0) {
		pre = tmp;
		tmp = tmp->next;
	}
	if (tmp == nullptr)
		return false;
	
	pre->next = new node(avg, tmp);
	
	return true;



}

bool list::Add_after_maximum_element(int el)
{
	if (head == 0)return false;

	int max = head->data; node* tmp = head;
	node* max_node = head;
	for (; tmp != 0;tmp = tmp->next) {
		if (max < tmp->data) {
			max = tmp->data;
			max_node = tmp;
		}
	}
	max_node->next = new node(el, max_node->next);

	if (max_node == tail)
		tail = max_node->next;

	return true;
}

//bool list::Move_minimum_to_front() {
//	if(head==0||head->next==0)
//		return false;
//
//	node* tmp = head;
//	node* min = head;
//	node* min_prev = nullptr;
//	while (tmp->next!=nullptr) {
//		if (min->data > tmp->next->data) {
//			min = tmp->next;
//			min_prev = tmp;
//
//		}
//		tmp = tmp->next;
//	}
//	if (min == head)return true;
//	min_prev->next = min->next;
//	min->next = head;
//	head = min;
//	return true;
//
//	//if (!head || !head->next) return false; // ÞÇÆãÉ ÝÇÑÛÉ Ãæ ÚäÕÑ æÇÍÏ
//
//	//node* min_prev = nullptr;
//	//node* min_node = head;
//	//node* tmp = head;
//
//	//while (tmp->next) {
//	//	if (tmp->next->data < min_node->data) {
//	//		min_node = tmp->next;
//	//		min_prev = tmp;
//	//	}
//	//	tmp = tmp->next;
//	//}
//
//	//if (!min_prev) return true; // ÇáÚÞÏÉ ÇáÕÛÑì åí head
//
//	//// ÝÕá ÇáÚÞÏÉ ÇáÕÛÑì ãä ãßÇäåÇ
//	//min_prev->next = min_node->next;
//
//	//// äÞá ÇáÚÞÏÉ Åáì ÇáÃãÇã
//	//min_node->next = head;
//	//head = min_node;
//
//	//return true;
//}
// 
//bool list::Add_after_first_odd(int el)
//{
//	if(head==0)
//	return false;
//	if (head->data % 2 != 0)
//	{
//		head->next = new node(el, head->next);
//		return true;
//
//	}
//	node* F_ood = head;
//	node* tmp = head;
//	while (tmp != nullptr) {
//		if (tmp->data % 2 != 0) {
//			F_ood = tmp;
//			break;
//
//		}
//
//		tmp = tmp->next;
//	}
//	if (F_ood == head && head->data % 2 == 0)
//		return false;
//	F_ood->next = new node(el, F_ood->next);
//	if (F_ood == tail)
//	{
//		tail = F_ood->next;
//	}
//	return true;
//
//}
//
//bool list::Delete_before_last_even()
//{
//	if (head == 0 || head->next == 0)
//		return false;
//	node* tmp = head;
//	node* prev = nullptr;
//	node* before_last_even = nullptr;
//	while (tmp != nullptr) {
//		if (tmp->data % 2 == 0) {
//			before_last_even = prev;
//
//		}
//		prev = tmp;
//		tmp = tmp->next;
//	}
//	if (before_last_even == nullptr)
//		return false;
//
//	if (before_last_even == head) {
//		head = head->next;
//		delete before_last_even;
//	}
//	else {
//		node* t = before_last_even;
//		t->next = before_last_even->next;
//		delete before_last_even;
//
//
//	}
//	return true;
//}
//bool list::Move_minimum_to_front() {
//	if (head == 0)
//		return false;
//	if (head->next == 0)return false;
//	node* min = head;
//	node* tmp = head;
//	node* prev = nullptr;
//	while (tmp->next != nullptr) {
//		if (tmp->next->data < min->data) {
//			min = tmp->next;
//			prev = tmp;
//
//		}
//		
//		tmp = tmp->next;
//	}
//	if (prev == nullptr)return true;
//	prev->next = min->next;
//	if (min == head)return true;
//
//	min->next = head;
//	head = min;
//	return true;
//
//
//
//
//
//
//
//}


void list::delete_odds() {

	// ÍÐÝ ÇáÚäÇÕÑ ÇáÝÑÏíÉ ãä ÇáÈÏÇíÉ
	while (head && head->data % 2 != 0) {
		node* t = head;
		head = head->next;
		delete t;
	}

	// ÅÐÇ ÇáÞÇÆãÉ ÕÇÑÊ ÝÇÖíÉ
	if (!head) return;

	node* p = head;

	// ÍÐÝ ÈÇÞí ÇáÚäÇÕÑ ÇáÝÑÏíÉ
	while (p->next) {
		if (p->next->data % 2 != 0) {
			node* t = p->next;
			p->next = p->next->next;
			delete t;
		}
		else {
			p = p->next;
		}
	}
}
bool list::delete_negative() {

	if (!head) return false;

	// ÍÐÝ ÇáÚÞÏ ÇáÓÇáÈÉ ãä ÇáÈÏÇíÉ
	while (head && head->data < 0) {
		node* t = head;
		head = head->next;
		delete t;
	}

	if (!head) return true;

	node* t = head;

	// ÍÐÝ ÇáÓÇáÈÉ ãä ÈÇÞí ÇáÞÇÆãÉ
	while (t->next) {
		if (t->next->data < 0) {
			node* del = t->next;
			t->next = del->next;
			delete del;
		}
		else {
			t = t->next;
		}
	}

	return true;
}
bool list::delete_befor_max() {
	if (!head || !head->next)
		return false;    
	int mx = head->data;
	node* t = head->next;
	while (t) {
		if (t->data > mx)
			mx = t->data;
		t = t->next;
	}
	if (head->data == mx)
		return false;
	if (head->next->data == mx) {
		node* tmp = head;
		head = head->next;
		delete tmp;
		return true;
	}
	node* p = head;
	while (p->next->next) {
		if (p->next->next->data == mx) {
			node* tmp = p->next;
			p->next = tmp->next;
			delete tmp;
			return true;
		}
		p = p->next;
	}

	return false;
}
bool list::delete_after_min() {
	if (!head || !head->next)
		return false;
	int min = head->data;
	node* t = head->next;
	while (t) {
		if (t->data < min)
			min = t->data;
		t = t->next;
	}
	node* p = head;
	while (p->next) {
		if (p->data == min) {
			if (p->next) {
				node* t = p->next;
				p->next = t->next;
				delete t;
				return true;
			} 
		}p=p->next;
	}
	return false;

}

/*bool list::Add_after_maximum_element(int el) {
	if (!head)
		return false;
	
	int max = head->data;
	node* t = head -> next;
	while (t) {
		if (t->data > max) {


			max = t->data;


		}t = t->next;
	}
	t = head;
	while (t) {
		if (t->data == max) {
			t->next=new node(el, t->next);
			return true;

		}
		t = t->next;



	}

	return true;


}*/
bool list::add_befor_min(int el) {
	if (!head)
		return false; // ÇáÞÇÆãÉ ÝÇÑÛÉ ? áÇ íãßä ÇáÅÖÇÝÉ ÞÈá min

	// 1) ÅíÌÇÏ ÞíãÉ min
	int min = head->data;
	node* t = head->next;
	while (t) {
		if (t->data < min)
			min = t->data;
		t = t->next;
	}

	// 2) ÅÐÇ ÇáÑÃÓ åæ min ? äÖíÝ ÞÈá ÇáÑÃÓ
	if (head->data == min) {
		node* n = new node(el, head);
		head = n;
		return true;
	}

	// 3) ÇáÈÍË Úä ÇáÚÞÏÉ ÞÈá min
	t = head;
	while (t->next) {
		if (t->next->data == min) {
			node* n = new node(el, t->next);
			t->next = n;
			return true;
		}
		t = t->next;
	}

	return false; // ÛíÑ ãÊæÞÚ
}
void list::print_back(node* t) {
	if (t != 0) {
		print_back(t->next);
		cout << t->data << " ";
	}


}
void list::print_back() {
	print_back(head);
}