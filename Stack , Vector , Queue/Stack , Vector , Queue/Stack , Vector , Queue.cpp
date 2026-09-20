

#include <iostream>
#include <stack> 
#include <vector>
#include <queue>
using namespace std; 
int main()
{
	//stack 

	/*stack < int > stkNumbers;
	for(short i=1;i<6 ;i++)
	stkNumbers.push(10*i);


	stack < int > stkNumbers2;
	for (short i = 6;i < 11;i++)
		stkNumbers2.push(10 * i);


	cout << "After Swaping \n\n\n";
	stkNumbers.swap(stkNumbers2);

	cout << "Stack 1  of Size[" << stkNumbers.size() << "]  : ";

	while (!stkNumbers.empty()) {
		cout << stkNumbers.top() << " ";
		stkNumbers.pop();
	}cout << endl;

	cout << "Stack 2  of Size[" << stkNumbers2.size() << "]  : ";

	while (!stkNumbers2.empty()) {
		cout << stkNumbers2.top() << " ";
		stkNumbers2.pop();
	}cout << endl;*/

	//vector  

	/*stack < vector <int > > KoKoStack;
	vector<int> k1, k2, k3;
	for (short i = 1; i <= 5;i++) {
		k1.push_back ( 1 * i );
		k2.push_back ( 2 * i );
		k3.push_back ( 3 * i );

	}
	KoKoStack.push(k1);
	KoKoStack.push(k2);
	KoKoStack.push(k3);


	short counter = 3;

	while (!KoKoStack.empty()) {
		cout << "\nk" << counter << " : ";

		for (int x : KoKoStack.top()) {
			cout << x << " ";
		}
		counter--;
		KoKoStack.pop();
	}*/

	// queue 

	//queue <int> MyQueue1, MyQueue2;
	//MyQueue1.push(10);
	//MyQueue1.push(20);
	//MyQueue1.push(30);
	//MyQueue1.push(40);
	//MyQueue1.push(50);
	//MyQueue2.push(60);
	//MyQueue2.push(70);
	//MyQueue2.push(80);
	//MyQueue2.push(90);
	//MyQueue2.push(100);
	////swap
	//MyQueue2.swap(MyQueue1);
	//cout << "queue 1 : \n";
	//cout << "size : " << MyQueue1.size() << endl; 
	//cout << "front : " << MyQueue1.front() << endl; 
	//cout << "Back : " << MyQueue1.back() <<"\nitems : "; 
	//while (!MyQueue1.empty()) {
	//	cout << MyQueue1.front() << " ";
	//	MyQueue1.pop();
	//}
	//cout<<"\n\n\n";
	//cout << "queue 2 : \n";
	//cout << "size : " << MyQueue2.size() << endl;
	//cout << "front : " << MyQueue2.front() << endl;
	//cout << "Back : " << MyQueue2.back() << "\nitems : ";
	//while (!MyQueue2.empty()) {
	//	cout << MyQueue2.front() << " ";
	//	MyQueue2.pop();
	//}



		system("pause>0");
	return 0; 

}
