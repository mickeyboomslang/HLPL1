#include "std_lib_facilities.h"

void swap_v(int a, int b)
{
	int temp;
	temp = a;
	a = b;
	b = temp;
}

void swap_r(int& a, int& b)
{
	int temp;
	temp = a;
	a = b;
	b = temp;
}

/* void swap_cr(const int& a, const int& b)
{
 int temp;
 temp = a;
 a = b;
 b = temp;
} */

int main()
{
	int x = 7;
	int y = 9;
	swap_r(x, y); 
	cout << x << ' ' << y << endl; //working cuz arguments r variables

	swap_v(7, 9); //integer numbers do not work
	cout << x << ' ' << y << endl;

	const int cx = 7;
	const int cy = 9;
	swap_v(cx, cy);
	cout << cx << ' ' << cy << endl; //not work (const)

	/*swap_v(7.7,9.9);
	cout << swap_v(7.7,9.9); //will work but only int part */

	double dx = 7.7;
	double dy = 9.9;
	swap_r(dx, dy);
	cout << dx << dy << endl; //argument must be integer

	swap_v(7.7, 9.9); //doubled arguments do not work
	cout << dx << ' ' << dy << endl;

	return 0;
}