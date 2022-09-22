#include <string>
#include <iostream>
#include <sstream>
#include <fstream>
#include <vector>

using namespace std;

#define StudentDataTxFile "../StudentData.txt"

typedef struct STUDENT_DATA {
	string firstName; 
	string lastName;
};

// reads data from file into vector, if not able to open file returns false, otherwise returns true
bool readStudentDataFromTxtFile(const string fileName, vector<STUDENT_DATA>& v) {
	//iostream that reads data from file
	
	ifstream ifs(fileName);
	if (!ifs.is_open()) //check if file is able to be opened
		return false;
	string line;
	while (getline(ifs, line))
	{
		STUDENT_DATA s; //instantiate STUDENT_DATA object to push to v
		string word;
		istringstream iss(line);
		getline(iss, word, ','); //parsed data to get first word: last name
		s.lastName = word;			
		getline(iss, word, ',');// parsed data to get second word: first name 
		s.firstName = word;
		v.push_back(s); // push STUDENT_DATA object s into v
	}
	return true;
}

#ifdef _DEBUG  // per step 4 functionality only used for printing Data which is Debug Mode
void printVectorOfStudentData(const vector<STUDENT_DATA> v)
{
	for (STUDENT_DATA a : v) {
		cout << "Last Name: " << a.lastName << "\tFirst Name: " << a.firstName << endl;
	}
}
#endif



int main() {
	vector<STUDENT_DATA> v;
	readStudentDataFromTxtFile(StudentDataTxFile, v);

#ifdef _DEBUG  // per Step 4 functionality only used for printing Data which is Debug Mode
	printVectorOfStudentData(v);
#endif


}