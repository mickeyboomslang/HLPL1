#include "std_lib_facilities.h"

template <typename T> // task 1
struct S

{
private://task 7 (make val private)
	T val;
public:

	S()//task 2 ( constructor added to initialize with T)
	{
		val = 0;
	}
	S(T am)
	{
		val = am;
	}

	T get();// task 5
	/*{
	return val;
	}
	*/
	const T get() const;
	void operator=(const T&);
	/*
	void set(T nat) // task 9
	{
		val = nat;
	}
	*/

};

template<typename T>
T S<T>::get()//task 6
{
	return val;
}

template<typename T>
const T S<T>::get() const // task 11
{
	return val;
}

template <typename T> // task 10
void S<T>:: operator=(const T& nat)
{
	val = nat;
}

template<typename T>
void read_val(T& v) // task 12
{
	cin >> v;
}
int main()
{
	S<int> intS(777);
	S<char> charS('U');
	S<double> doubS(99.999);
	S<string> strS("Itachi");
	S<vector<int>> vecS({ 100, 200, 300 });// task 3
	/*

	cout << intS.val<<endl;
	cout << charS.val << endl;
	cout << doubS.val << endl;
	cout << strS.val << endl;
	for(int i : vecS.val)
	cout << i <<" ";// task 4
	*/

	cout << intS.get() << endl;//task 8
	cout << charS.get() << endl;
	cout << doubS.get() << endl;
	cout << strS.get() << endl;
	for (int i : vecS.get())
		cout << i << " ";
	cout << endl;

	int int1; //task 13
	read_val(int1);
	S<int> int1S(int1);

	double dbl1;
	read_val(dbl1);
	S<double> dbl1S(dbl1);

	char char1;
	read_val(char1);
	S<char> char1S(char1);

	cout << int1S.get() << endl;
	cout << dbl1S.get() << endl;
	cout << char1S.get() << endl;

	return 0;
}
