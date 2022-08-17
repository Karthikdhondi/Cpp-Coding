#include<iostream>
using namespace std;

int main() {

	// memory allocated for line 7 is 8 Bytes for *p(i.e for pointer in stack)
	//and 4Bytes for int in heap....totally 12 Bytes of memory created
	int *p = new int ;
	*p = 10 ;
	cout << *p << endl;
	// memory allocated for line 12 is 8Bytes for *p1(i.e for pointer in stack)
	//and 8 Bytes for double in heap ...totally 16Bytes of memory created.
	double *p1 = new double;
	*p1 = 40.23;
	cout << *p1 << endl;

	char *c = new char;
	*c = 68;
	cout << *c << endl;
	/*  intially there was a problem, declaring an array at run time,
		i.e

		int n;
		cin >>n;
		for(i=0; i<n; i++)
		{
			cin >> arr[i];
		}

		if we implement as above, the memory will create at runtime,
		and it will create in stack memory. If our input is very large,
		then it may give an error like "stack overflow"

		so, better to allocate array memory in dynamic alloction,
	*/


	// memory created in heap at complie time
	// 8Bytes in stack, 4*50 = 200Bytes in heap. Total= 208 Bytes of memory allocated. for below line
	int *pa = new int[50];
	int n;
	cin >> n;
	//memory created in heap at run time, but we have no problem,in this case
	int *pa1 = new int[n];

	for (int i = 0; i < n; i++)
	{
		cin >> pa1[i];
	}

	int max = -1;

	for (int i = 0; i < n; i++) {
		if (max < pa1[i])
		{
			max = pa1[i];
		}
	}
	cout << "max element is:";
	cout << max << endl;

}