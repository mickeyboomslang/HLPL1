#include "std_lib_facilities.h"


void print_array10(ostream& os, int* a)
{
	for (int i = 0; i < 10; i++)
		os << a[i] << endl;
	delete[] a;  // task 9

}
//task 6
void print_array11(ostream& os, int* a)
{
	for (int i = 0; i < 11; i++)
		os << a[i] << endl;

	delete[] a; // task 9
}

void print_array(ostream& os, int* a, int n)//task 7
{
	for (int i = 0; i < n; i++)
		os << a[i] << endl;
	delete[] a;  // task 9
}


void printVector(vector<int*> v)//task 10
{

	for (int i = 0; i < v.size(); ++i)
		cout << *v[i] << endl;
	//delete v[i]; task 9


}

vector<int*> VectorAllocate(int n)//task 10
{
	vector<int*> temp;
	int counter = 100;
	for (int i = 0; i < n; ++i)
		temp.push_back(new int{ counter++ });

	return temp;
}


int main()
{

	int* ten_i = new int[10];//task 1
	for (int i = 0; i < 10; i++)
		cout << ten_i[i] << ' ';//task 2
	cout << endl;
	delete[] ten_i;//task 3

	// task 4
	//print_array10(cout, ten_i);



	int* ten_a2 = new int[10]{ 100, 101, 102, 103, 104, 105, 106, 107, 108, 109 };//task 5
	print_array10(cout, ten_a2);
	//delete[] ten_i2 chapter 17, drill 9


	int* eleven_a = new int[11]{ 100, 101, 102, 103, 104, 105, 106, 107, 108, 109, 110 };//task 6
	print_array11(cout, eleven_a);
	//task 9


	int* twenty_a = new int[20]{ 100, 101, 102, 103, 104, 105, 106, 107, 108, 109, 110, 111, 112, 113, 114, 115, 116, 117, 118, 119 };//chapter 17, drill 8
	print_array(cout, twenty_a, 20);
	//delete[] twenty_i ; task 9

	// chapter 17, drill 10
	cout << "with Vector 10" << endl;
	vector<int*> vec_ten_i = VectorAllocate(10);
	printVector(vec_ten_i);

	cout << "with Vector 11" << endl;
	vector<int*> vec_eleven_i = VectorAllocate(11);
	printVector(vec_eleven_i);

	cout << "with Vector 20" << endl;
	vector<int*> vec_twenty_i = VectorAllocate(20);
	printVector(vec_twenty_i);



	return 0;
}
