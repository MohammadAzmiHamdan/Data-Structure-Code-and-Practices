#include "queue.h"
#include <iostream>
using namespace std;
int main() {
	queue q, tmp;
	int el;
	q.append(1);
	q.append(2);
	q.append(3);
	q.append(4);
	while (!q.is_empty()) {
		q.retrieve(el);
		q.serve();
		if (q.is_empty())
			break;
		tmp.append(el);
	}
	while (!tmp.is_empty()) {
		tmp.retrieve(el);
		tmp.serve();
		q.append(el);



	}



 }