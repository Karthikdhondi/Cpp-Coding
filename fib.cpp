#include<iostream>
using namespace std;

int fib(int n)
{
	if (n == 0 || n == 1) {
		return 1;
	}
	else {
		return (fib(n - 1) + fib(n - 2));
	}
}

int main() {
	int n;
	cout << "Enter the value for n:";
	cin >> n;
	int output = fib(n);
	cout << output << endl;
}