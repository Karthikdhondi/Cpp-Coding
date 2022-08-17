#include<iostream>
using namespace std;

int first_index(int arr[], int size, int x) {
	int ans;
	if (size == 0) {
		return -1;
	}
	if (arr[0] == x) {
		return 0;
	}
	else {
		ans = first_index(arr + 1, size - 1, x);
		if (ans == -1) {
			return -1;
		}
		else {
			return ans + 1;
		}
	}
}

int main() {

	int n, x;
	cout << "Enter the size of the array" << endl;
	cin >> n;
	int *arr = new int[n];
	cout << "Enter the elements of the array" << endl;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	cout << " Enter the element of which the first index is required:" << endl;
	cin >> x;
	int ans = first_index(arr, n, x);

	cout << ans << endl;


}