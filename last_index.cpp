#include<iostream>
using namespace std;

int last_index(int arr[], int size, int x) {
	int ans;

	if (size == 0) {
		return -1;
	}
	ans = last_index(arr + 1, size - 1, x);
	if (ans == -1) {
		if (arr[0] == x) {
			return 0;
		}
		else {
			return -1;
		}
	}
	else {
		return ans + 1;
	}

}

int main() {
	int n;
	cout << " Enter the size of the array:" << endl;
	cin >> n;
	int *arr = new int[n];
	cout << "Enter the elements of the array:" << endl;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	int x;
	cout << "Enter value of an element of which last index is required:" << endl;
	cin >> x;
	int ans = last_index(arr, n, x);

	cout << "The Last Index of the element" << x << "is:" << ans << endl;

}