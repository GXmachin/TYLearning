// c++ standard libraries

#include <iostream>
#include <sstream> // string stream  standard library
#include <string> //  c++ string library

// using c++ namespace for cout and cin stream objects
using namespace std;

int main() {
	// variable declaration
	string f_name; string l_name; int age; string sex; string str; // the variable str is a used as placeholder for stringstreaming age

	
	cout << "Enter your first name: "; //user prompt
	getline(cin, f_name);			//get user input
	cout << "Enter your last name: ";  //user prompt
	getline(cin, l_name);			//get user input
	cout << "Enter your age: ";		//user prompt
	getline(cin, str);				//get user input
	stringstream(str) >> age;		//stream string input to number
	cout << "Enter your sex: ";     //user prompt
	getline(cin, sex);				//get user input
	
	//print statment
	cout << "Your name is " << f_name << " " << l_name << " and you are "
		<< age << " years old" << " and you are a " << sex;
}