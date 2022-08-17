#include<iostream>

using namespace std;
//passing by reference
void increment(int &i) {
	i++;
}
//bad practice
//we are returning by reference
int& f(int n ) {
	int a = n;
	return a;
	//there is a problem bcz scope of variable is within the fuction
}
// bad practice
//it  will run fine i.e we may get warning but it will work fine.
// but not a good practice, sometimes your code will go wrong.
int* f2()
{
	int i = 10;
	return &i;
}

int main() {
	//f2() is returning address of i
	//same problem we don't have access to address of i bcz it was local varible.
	int *p = f2();

	int i;
	i = 20;
	// we are catching by reference
	//we are trying to access the memory which is no more belongs to function f, i.e invalid memory access
	//bcz varibale a's scope is completed.
	int& k1 = f(i);

	increment(i);
	cout << i << endl;
	//Here we are creating a referece variable,
	// j is a reference variable, for j memory is not allocated
	// j is using the same memory for which i is using
	int &j = i;

	//we cannot declare as below, complier will give error.
	//whenever we are using the reference variable we need to initialize it.
	/* int &j;
		j=i;
	*/
	i++;
	cout << j << endl;
	j++;
	cout << i << endl;

	int k = 200;
	j = k;
	cout << i << endl;

}