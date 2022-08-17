#include<iostream>
using namespace std;

void g(int const &a) {
	// a++; we cant do a++
}

void f(const int *p) {
	// (*p)++; we cant do this, bcz,it is read only mem
}

int main() {
	int const i = 10;
	/*
	int *p = &i;

	i can't do this, becasue if be able read, then i may also able to write.
	therefore it may go wrong. therefore we are taking a promise. that you should not
	be able to write it. if it is the case, i need to do use const in pointer then it will work fine
	*/

	int const *p = &i;// no error

	int j = 23;
	int const *p1 = &j;
	/* initally *p was able read and write on j(i.e without const type)
	Now, it is saying that, i will read only, but i wont write,
	If it is the case, it works fine, No issues.
	*/
	f(p1);
	cout << *p1 << endl;
	j++;
	cout << *p1 << endl;
}