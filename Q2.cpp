// c++ standard libraries
#include <iostream>

// using c++ namespace for cout and cin stream objects
using namespace std;

int main()
{
	// variable declaration
	char user_char;
	int user_int; 
	float user_float;

	//user prompt
	cout << "Please enter a character: ";
	//getline(cin, str);
	cin >> user_char;
	cout << "Please enter an integer: ";
	//getline(cin, str);
	cin >> user_int;
	cout << "Please enter a float: ";
	//getline(cin, str);
	cin >> user_float;

	// type cast
	int user_castInt = (int)user_float;
	int sum;

	//sum
	sum = user_castInt + user_int;

	//print statement
	cout << "sum of int and float: " << sum;

	return 0;
}
