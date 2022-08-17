#include<iostream>

using namespace std;

int main()
{
	int a = 97;

	char b = a;

	cout << b << endl;

	int *p = &a;
	char *pc = (char *)p;

	cout << p << endl;
	cout << pc << endl;

	cout << *p << endl;
	cout << *pc << endl;

	cout << *(pc + 1) << endl;
	cout << *(pc + 2) << endl;
	cout << *(pc + 3) << endl;

}