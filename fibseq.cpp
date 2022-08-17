#include<iostream>
using namespace std;

int fibseq(int n)
{
	if (n == 0 || n == 1) {
		return 1;
	}
	else {
		return (fibseq(n - 1) + fibseq(n - 2));
	}
}

int main() {
	int n, output;
	cout << "Enter the value for n:";
	cin >> n;
	for (int i = 0; i < n; i++) {
		output = fibseq(i);
		cout << output << " ";
	}
}