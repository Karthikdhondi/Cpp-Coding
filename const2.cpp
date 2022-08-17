#include<iostream>
using namespace std;

int main()
{
	int i = 10;
	int j = 20;
	int const *p = &i; //This is allowed
	//p is saying i am pointing towards constant, and i wont change the value,
	// therefore, it is allowed

	p = &j;

	int * const p2 = &i;
	(*p2)++;
	//p2 = &j; , we cannnot do this

	int const * const p3 = &i;
	/*
	p3 =&j;
	(*p3)++;

	*/
}