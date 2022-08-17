#include<iostream>
using namespace std;

int main() {
	//for a const type variable we need to intialize it where it is defined
	/*we can do like below
	const int a;
	a=10;
	this will give error
	*/
	const int i = 10;// right way to implement const type
	int const a = 22;// both are same.
	int j = 20;
	const int &k = j;
	// k++;// this line will give error, since it is const type.
	j++;
	cout << k << endl;

	// constant reference from a constant int
	int const b = 30;
	int const &k1 = b;
	/*	k1++;
		b++;
		we can't do any one since both are constant.it will give error.
	*/

	//referecnce from a const int
	int const a1 = 45;
	/*int &k2 = a1;
	we can't do the above line, bcz we are trying read the const type variable, if we are able read
	const type variable without const type, then we can also able to write to the const type varibale,therefore
	below line will also give the error.
	k2++;
	*/
}