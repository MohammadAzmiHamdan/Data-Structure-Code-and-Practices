#include <iostream>
#include"queue.h"
using namespace std;

int main() {
	queue q;

	
	q.append(1);
	
	q.append(2);


	q.append(3);
	

	q.append(4);
	

	q.append(5);
	
	cout << "before shift : ";
	q.print2();
	q.moveLastToFront();
	cout << "\n after sheft : ";
	q.print();
 q.search(5) ;
 q.search(1);
	cout << "\nstart my smart code :\n";
	  // Remove elements until the last one is reached.
     // Store all elements except the last in a temporary queue.
    // Reinsert the last element first, then restore the remaining elements.

	queue tmp;
	int el;
	while (!q.is_empty())
	{
		q.retrieve(el);
		q.serve();
		if (q.is_empty() ) {
			break;

		}
		else {
			tmp.append(el);
		}



	}
	q.append(el);
	while (!tmp.is_empty()) {
		tmp.retrieve(el);
		tmp.serve();
		q.append(el);
	}
	cout << "after moving ";
	q.print();

	q.search(1);


}