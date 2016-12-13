/*
 * Name: 	Jeffrey Qiu
 * Class: 	CS110B
 * Date: 	2/28/2015
 * Instructor:	Professor Harden
 * File name: 	a7_1.cpp
 * Description:
 * This program will perform some basic tasks with pointers.
 */
#include <iostream>

using namespace std;






// step 11
void noNegative(int *x)
{
	if (*x < 0)
		*x = 0;
}






// step 21
void swap(int *x, int *y)
{
	if (x !=  NULL && y != NULL)
	{
		int temp = *x;
		*x = *y;
		*y = temp;
	}
}






int main()
{
	// step 1
	int x, y;

	// step 2
	int *p1;

	// step 3
	p1 = &x;

	// step 4
	*p1 = 99;

	// step 5
	cout << "step 5: " << x << endl;

	// step 6
	cout << "step 6: " << *p1 << endl;	

	// step 7
	p1 = &y;

	// step 8
	*p1 = -300;

	// step 9
	int temp;
	int * p2;

	// step 10
	p2 = &x;
	temp = *p1;
	*p1 = *p2;
	*p2 = temp;

	// step 12
	noNegative(p2);
	noNegative(p1);

	// step 13
	p2 = &x;
	cout << "step 13: " << *p2 << "\t";
	p2 = &y;
	cout << *p2 << endl;

	// step 14
	int a[2];

	// step 15
	p2 = &x;
	a[0] = *p2;

	// step 16
	p2 = &y;
	a[1] = *p2;

	// step 17
	cout << "step 17: " << &(a[0]) << endl;

	// step 18
	cout << "step 18: " << &(a[1]) << endl;

	// step 19
	p1 = &(a[0]);
	p2 = &(a[1]);
	temp = *p1;
	*p1 = *p2;
	*p2 = temp;

	// step 20
	cout << "step 20: " << a[0] << "\t" << a[1] << endl;

	// step 22
	swap(&x, &y);
	cout << "step 22: " << x << "\t" << y << endl;

	// step 23
	swap(&(a[0]), &(a[1]));
	cout << "step 23: " << a[0] << "\t" << a[1] << endl;

	return 0;
}






/*
step 5: 99
step 6: 99
step 13: 0	99
step 17: 0x28ff04
step 18: 0x28ff08
step 20: 99	0
step 22: 99	0
step 23: 0	99
*/

