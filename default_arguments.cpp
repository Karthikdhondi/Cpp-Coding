#include<iosream>
using namespace std;

int sum(int a[], int size, int si = 0)
//here "si" is default argument
// we can assign default arguments, first to right most element, next to next rightmost ....like wise, atlast to leftmost element
// but we cannot assign randomly
{
	itn ans = 0 ;

	for (int i = si; i < size; i++) {
		ans + = a[i];
	}

	return ans;
}

int sum1(int a, int b, int c = 0, int d = 0) {
	return a + b + c + d;
}

int main() {

	int a[20];

	cout << sum(a, 20) << endl;

}