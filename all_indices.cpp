#include<iostream>
using namespace std;

int all_indices(int arr[], int size, int x, int output[]) {
	int ans;
	if (size == 0) {
		return 0;
	}
	ans = all_indices(arr + 1, size - 1, x, output);

	if (arr[0] == x) {
		for (int j = ans - 1; j >= 0; j--)
		{
			output[j + 1] = output[j] + 1;
		}
		output[0] = 0;
		return (ans + 1);
	}
	else {
		for (int i = ans - 1; i >= 0; i --) {
			output[i] = output[i] + 1;
		}
	}
	return ans;



}



int main() {
	int n, x;
	cout << "Enter the size of the array:" << endl;
	cin >> n;
	cout << "Enter the elements of the array:" << endl;
	int *arr = new int[n];
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	cout << "Enter the value of the element for which we want all the indice:" << endl;
	cin >> x;

	int *output = new int[n];

	int small_ans = all_indices(arr, n, x, output);

	cout << "output is " << endl;
	for (int i = 0; i < small_ans; i++) {
		cout << output[i] << " ";
	}
}