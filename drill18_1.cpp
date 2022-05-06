#include "std_lib_facilities.h"

int ga[10] = { 1,2,4,8,16,32,64,128,256,512 };//task 1;  creating a global array

void f(int arr[], int n)//task 2; defining a function
{
	int la[10];//task 3(a); creating a local array
	for (int i = 0; i < 10; i++)//task 3(b)
		la[i] = ga[i];

	for (int i = 0; i < 10; i++)//task(c); printing out the array 'la'
		cout << la[i] << " ";

	int* p = new int[n];//task 3(d); defining a pointer

	for (int i = 0; i < 10; i++)//task 3(e)
		p[i] = arr[i];
	cout << endl;
	for (int i = 0; i < 10; i++)//task 3(f); printing free-store array
		cout << p[i] << " ";
	cout << endl;
	delete[] p;//task 3(g); deallocation of free-store array
}
int main()
{
	f(ga, 10);//task 4(a); 
	int aa[10] = { 1,2,6,24,120,720,5040,40320,362880,3628800 };//task 4(b); defining an array aa
	f(aa, 10);//task 4(c); calling function f() with argument aa 


	return 0;
}