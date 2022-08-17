#include<iostream>
using namespace std;

int main() {


	//in this case initially it will create a temporary mem and it will store the string literal
	// later it will copy to str[] array

	char str[] = "abcde";
	//In this case ptr is directly pointing to a temporary mem.
	//so, sometimes it may give wrong value.
	//Therefore better to "use char array" rather than char pointer for strings

	//char* ptr = "abcde";


	int i[] = {10, 20, 30};
	char p[] = "a,ab,abc";

	//it prints address
	cout << i << endl;
	//it prints array contents
	//since it is a charater array its cout is differently implemented
	cout << p << endl;


	char* c = &p[0];
	//in this case also it will print the contents of array rather than address
	//Bcz, cout for char is implemented like this.
	cout << c << endl;


	char c1 = 'a';
	char* pc = &c1;

	cout << c1 << endl;
	//intresting thing while printing pc
	//it will go to content of c1
	//and it will start scanning from 'a' untill it finds a null
	//and it will print all the grabage till null
	cout << pc << endl;


}