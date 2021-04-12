#include<bits/stdc++.h>
using namespace std;

int sum_of_digits(int n)
{
	if(n==0)
		return 0;
	return((n%10)+sum_of_digits(n/10));
}

int main()
{
	int num= 145546;
	int result = sum_of_digits(num);
	cout<< "sum of digits in" << endl << num << endl <<"is" << endl << result << endl;
	return 0; 
}