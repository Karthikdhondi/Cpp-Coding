#include<iostream>
using namespace std;

inline int max(int a , int b) {
	return (a > b) ? a : b;
}

int main()
{
	int a, b, c;

	cout << "Enter the values for a and b:" << endl;
	cin >> a >> b;

	/* This is naive method to find max
	if (a > b) {
		c = a;
		cout << " max is:" << c << endl;
	}
	else {
		c = b;
		cout << " max is:" << c << endl;
	}
	*/

	// finding max using Ternary operator

	//c = (a > b) ? a : b;

	//if i want to find another max function
	// again i need to write the same above code and need to think about it
	// so, better we are going with Max function which is using ternary operator

	c = max(a, b);

	int x, y;
	x = 35;
	y = 10;

	int z = max(x, y);

// this is better implementation of max
// but we have some issue , i.e, every time function call is required
// so to over come that we are using "inline" key word.
// this "inline" keyword will replace the function by the statements which are in the function call at the time of compilation.
//so, no time is consumed for function call
// "inline" key word is used only for atmost 3 line of code in function call
// if possible then only done by the complier otherwise it gives error.

}