#include<iostream>
using namespace std;

/*
METHOD 2

bool is_sorted(int arr[], int size) {
	if (size == 0 || size == 1) {
		return true;
	}
	bool isSmallerSorted = is_sorted(arr + 1, size - 1);
	if (!isSmallerSorted) {
		return false;
	}
	if (arr[0] > arr[1]) {
		return false;
	}
	else {
		return true;
	}
*/
//METHOD 1:

bool is_sorted(int arr[], int size) {
	if (size == 0 || size == 1) {
		return true;
	}
	if (arr[0] > arr[1]) {
		return false;
	}
	bool isSmallerSorted = is_sorted(arr + 1, size - 1);
	return isSmallerSorted;
}

int main() {
	int n;
	cout << "Enter the array size:";
	cin >> n;
	int *arr = new int[n];
	cout << "Array Elements are:";
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	bool val = is_sorted(arr, n);
	if (val == 0) {
		cout << "Array is UNSORTED" << endl;
	}
	else {
		cout << "Array is SORTED" << endl;

	}

}