#include <iostream>

//namespace scope for c++ stream object
using namespace std;

// created a power function by recursion
float power(float input, int exp)
{
	if (exp == 0)
		return 1;
	else if (exp > 0)
		input *= power(input, exp - 1); //recursively calculating power
	else if (exp < 0) 
	{
		exp *= -1; // put it all in absolute terms
		input = 1 / input; // represent the number as fraction (2^-2 = 1/2 * 1/2)
		input *= power(input, exp - 1); //recursively calculating power
	}
	return input;
}

int main()
{
	float number;
	int pow;

	//user prompt and input
	cout << "Enter a number: ";
	cin  >> number;
	cout << "Enter an exponent: ";
	cin >> pow;

	// power function call
	cout << power(number, pow);
	return 0;
}
