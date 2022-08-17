#include<iostream>

using namespace std;

int main() {

	//In static memory allocation, memory is released automatically
	// where as in Dynamic memory allocation we need to release memory manually by using key word "delete"

	//single element creation
	int *p = new int;
	//single element deletion
	delete p;
	//creation of array of size 100 in heap
	int *p1 = new int[100];
	// deletion of array from heap
	delete [] p1;


	/*
		//creating memory in stack, is called as static memory allocation
		while(true){
			int i=10;
		}
		// creating memory in heap, is called as dynamic memory alloction
		while(true){
			int *p = new int;

		}

		*/
}