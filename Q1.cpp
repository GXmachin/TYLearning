// c++ standard libraries

#include <iostream>
#include <string> //  c++ string library

// using c++ namespace for cout and cin stream objects
using namespace std;

int main()
{
	// variable declaration
	string firstName;
	string lastName;
	int age;
	string sex;

	cout << "Enter your first name: "; //user prompt
	cin >> firstName;			//get user input
	cout << "Enter your last name: ";  //user prompt
	cin >> lastName			//get user input
	cout << "Enter your age: ";		//user prompt
	cin >> age;				//get user inputr
	cout << "Enter your sex: ";     //user prompt
	cin >> sex;				//get user input
	//print statment
	cout << "Your name is " << f_name << " " << l_name << " and you are "
		<< age << " years old" << " and you are a " << sex;
}
