#include <iostream>
#include <map>
using namespace std; 

int main()
{
	map <string, int > StudentGrade;
	StudentGrade["Mohammad"] = 85;
	StudentGrade["Ahmad"] = 80;
	StudentGrade["Ali"] = 95;

	cout << "Printing all student in the map : \n\n";

	for (const auto& Pair : StudentGrade) {
		cout << "Student Name : " << Pair.first << "\nGrade : " 
			<< Pair.second << "  \n\n";
	}

	cout << "\n\nsearch for Mohammad . . .\n";

	if (StudentGrade.find("Mohammad") != StudentGrade.end()) {
		cout << " Found :-) \n";

	}
	else {
		cout << " Not Found :-( \n";
	}

	cout << "\n\nsearch for Omar . . .\n";

	if (StudentGrade.find("Omar") != StudentGrade.end()) {
		cout << " Found :-) \n";

	}
	else {
		cout << " Not Found :-( \n";
	}




	system("pause>0");
	return 0;
}
