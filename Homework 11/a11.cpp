/*
 * Name:	Jeffrey Qiu
 * Class:	CS110B
 * Date:	03/28/2015
 * Instructor:	Professor Harden
 * File Name:	a11.cpp
 * Description: This program includes a fraction class that has objects that represent fractions.
 * The member functions include :
 *  1) One constructor that takes no argument, which sets the numerator to 0 and denominator to 1.
 * 	2) One constructor that takes two long (integer) arguments, the numerator and denominator, and
 * sets the calling object accordingly.
 * 	3) Arithmetic operations that add, subtract, multiply, and divide fractions. These should be
 * implemented as value returning functions return a fraction object. They should be named
 * addedTo, subtract, multipliedBy, and dividedBy. In these functions you will need to declare
 * a local "fraction" variable, assign to it the result of the mathematical operation, and then
 * return it.
 * 	4) A boolean operation named isEqualTo that compares two fraction objects for equality.
 * Since you aren't reducing your fractions, you'll need to do this by cross-multiplying.
 * A little review: if numerator1 * denominator2 equals denominator1 * numerator2, then the
 * fractions are equal.
 * 	5) An output operation named print that displays the value of a fraction object on the
 * screen in the form numerator/denominator.
 *
 * This program will simplify the fractions. Even though I was not required to deal
 * with negative numbers I added extra logic to deal with negative numbers, either in the
 * numerator or the denominator. The sign of the fraction is kept in the numerator.
 */


#include <iostream>
#include "fraction.hpp"

using namespace std;












/*
 * The client program is to execute test cases.
 */
int main()
{
    fraction f1(9,8);
    fraction f2(2,3);
    fraction result;

    cout << "The result starts off at ";
    result.print();
    cout << endl;

    cout << "The product of ";
    f1.print();
    cout << " and ";
    f2.print();
    cout << " is ";
    result = f1.multipliedBy(f2);
    result.print();
    cout << endl;

    cout << "The quotient of ";
    f1.print();
    cout << " and ";
    f2.print();
    cout << " is ";
    result = f1.dividedBy(f2);
    result.print();
    cout << endl;

    cout << "The sum of ";
    f1.print();
    cout << " and ";
    f2.print();
    cout << " is ";
    result = f1.addedTo(f2);
    result.print();
    cout << endl;

    cout << "The difference of ";
    f1.print();
    cout << " and ";
    f2.print();
    cout << " is ";
    result = f1.subtract(f2);
    result.print();
    cout << endl;

    if (f1.isEqualTo(f2)){
        cout << "The two fractions are equal." << endl;
    } else {
        cout << "The two fractions are not equal." << endl;
    }

    const fraction f3(12, 8);
    const fraction f4(202, 303);
    result = f3.multipliedBy(f4);
    cout << "The product of ";
    f3.print();
    cout << " and ";
    f4.print();
    cout << " is ";
    result.print();
    cout << endl;
}











/*

The result starts off at 0/1
The product of 9/8 and 2/3 is 3/4
The quotient of 9/8 and 2/3 is 27/16
The sum of 9/8 and 2/3 is 43/24
The difference of 9/8 and 2/3 is 11/24
The two fractions are not equal.
The product of 3/2 and 2/3 is 1/1

*/
