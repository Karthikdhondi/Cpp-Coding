#include<iostream>

using namespace std;
// 3D array
// verify the program i think its not correct.
int main()
{
	int l, m, n;
	cout << "Enter the No.of Rows and Coloumns:" << endl;
	cin >> m >> n;

	int **q = new int *[l];

	for (int i = 0; i < l; i++)
	{

		int** p = new int*[m];


		for (int j = 0; j < m; j++) {
			p[j] = new int[j + 1];
			for (int k = 0; k < n; k++) {
				cin >> p[j][k];
			}
		}

		for (int i = 0; i < l; i++) {
			delete [] q[i];
		}

		for (int i = 0 ; i < m; i++)
		{
			delete [] p[i];
		}
		delete [] p;
	}
}