/*
 * Name:	Jeffrey Qiu
 * Class:	CS110B
 * Date:	03/21/2015
 * Instructor:	Professor Harden
 * File Name:	a10.cpp
 * Description: This program includes a fraction class that has objects that represent fractions.
 * The member functions include :
 * 	1) A set() operation that takes two long (integer) arguments, the
 * numerator and denominator, and sets the calling object accordingly.
 * 	2) Arithmetic operations that add, subtract, multiply, and divide fractions. These should be
 * implemented as value returning functions return a fraction object. They should be named
 * addedTo, subtract, multipliedBy, and dividedBy. In these functions you will need to declare
 * a local "fraction" variable, assign to it the result of the mathematical operation, and then
 * return it.
 * 	3) A boolean operation named isEqualTo that compares two fraction objects for equality.
 * Since you aren't reducing your fractions, you'll need to do this by cross-multiplying.
 * A little review: if numerator1 * denominator2 equals denominator1 * numerator2, then the
 * fractions are equal.
 * 	4) An output operation named print that displays the value of a fraction object on the
 * screen in the form numerator/denominator.
 *
 * This program does not reduce the fractions or change improper fractions into mixed numbers
 * for printing. It simply prints the improper fraction. Even though I was not required to deal
 * with negative numbers I added extra logic to deal with negative numbers, either in the
 * numerator or the denominator. The sign of the fraction is kept in the numerator.
 */

	
	
	
	
#include <iostream>
#include <stdlib.h>

	
using namespace std;












/*
 * fraction class definition
 *
 * The fraction class has two private members, numerator and denominator, they are of long data type.
 *
 * There are two constructors, one with no input parameter and another with two input parameters of
 * numerator and denominator values for initialization.
 *
 *	//Pre-condition: None.
 *  fraction();
 *  //Post-condition: numerator set to 0 and denominator set to 1.
 *
 *  //Pre-condtion: Two long type parameters nu and de.
 *  fraction(long nu, long de);
 *  //Post-condition: numerator is set to the value of nu. If de is not zero the denominator is set to the value of de.
 *  //If de is zero, then denominator is set to one.
 *
 *
 * There is a destructor which only destroys itself without doing anything else.
 *
 *	//Pre-condition: None.
 * 	~fraction();
 * 	//Post-condition: The object is destroyed.
 *
 *
 * There is a set member function that takes two long values to set the numerator and denominator
 * private members respectively.
 *
 *	//Pre-condition: Two long type parameters nu and de.
 * 	bool set(long, long);
 *	//Post-condition: numerator is set to the value of nu. If de is not zero the denominator is set to the value of de.
 *  //If de is zero, then denominator is set to one.
 *
 * There is a print member function. It prints out the string of "numerator/denominator" in this object.
 *
 *	//Pre-condition: None.
 *	void print();
 *	//Post-condition: Print the fraction on the console with the format of numerator/denominator.
 *
 * There is an isEqualTo member function which checks whether an input fraction contains the same
 * fraction value as this object's. If they are the same, it returns true; otherwise, it returns false.
 *
 *	//Pre-condition: One fraction object f as input parameter. f cannot be null and f's denominator cannot be zero.
 * 	bool isEqualTo(fraction f);
 * 	//Post-condition: Compare this->numerator and this->denominator to f.numerator and f.denominator. If they are proportionally
 * 	//same, then return true. Otherwise, return false.
 *
 *
 * There are math member functions, f1 + f2, f1 - f2, f1 * f2, f1 / f2, returns the result in a fraction
 * object without changing either the value of the input fraction object or this object.
 *
 *	//Pre-condition: f is a valid fraction object with a non-zero denominator.
 * 	fraction addedTo(fraction f);
 * 	//Post-condition: Add f's fraction value with this object's fraction value. Store the result
 * 	//of the operation in the temporary fraction variable and return the temporary fraction.
 *
 * 	//Pre-condition: f is a valid fraction object with a non-zero denominator.
 *  fraction subtract(fraction f);
 *  //Post-condition: Subtract f's fraction value from this object's fraction value. Store the result
 * 	//of the operation in the temporary fraction variable and return the temporary fraction.
 *
 *  //Pre-condition: f is a valid fraction object with a non-zero denominator.
 *  fraction multipliedBy(fraction f);
 *  //Post-condition: Multiply f's fraction value with this object's fraction value. Store the result
 * 	//of the operation in the temporary fraction variable and return the temporary fraction.
 *
 *  //Pre-condition: f is a valid fraction object with a non-zero denominator.
 *  fraction dividedBy(fraction f);
 *	//Post-condition: Divide f's fraction value from this object's fraction value. Store the result
 * 	//of the operation in the temporary fraction variable and return the temporary fraction.
 *
 *
 */
class fraction
{
private:
	long numerator;
	long denominator;
public:
	fraction();
	fraction(long, long);
	~fraction();

	bool set(long, long);

	void print();
	bool isEqualTo(fraction);
	fraction addedTo(fraction);
	fraction subtract(fraction);
	fraction multipliedBy(fraction);
	fraction dividedBy(fraction);
};












/*
 * constructor
 */
fraction::fraction()
{
	numerator = 0L;
	denominator = 1L;
}












/*
 * constructor with initialization values of numerator and denominator
 *
 * Input: two long integers, one for numerator and the other for denominator
 * 		if the value of denominator is 0, the private member denominator will be set to 1
 */
fraction::fraction(long nu, long de)
{
	numerator = nu;
	if (de != 0L)
		denominator = de;
	else
		denominator = 1L;

	if (denominator < 0)
	{
		numerator = -numerator;
		denominator = -denominator;
	}
}












/*
 * destructor
 *
 * since there is no extra memory to free, it actually just destroys the object itself
 */
fraction::~fraction()
{
}












/*
 * Set the numerator and denominator of the fraction object
 *
 * Input: 	two long integers, one for numerator and the other for denominator
 * Output:	if the denominator is 0, return false; otherwise, return true
 */
bool fraction::set(long nu, long de)
{
	bool isDeNot0 = true;

	numerator = nu;
	if (de != 0L)
		denominator = de;
	else 
		isDeNot0 = false;

	if (denominator < 0)
	{
		numerator = -numerator;
		denominator = -denominator;
	}

	return isDeNot0;
}












/*
 * print out the string of "numerator/denominator"
 */
void fraction::print()
{
	cout << numerator << "/" << denominator;
}












/*
 * Check whether the object contains the same fraction value as the input object
 *
 * Input:	a fraction object
 * Output:	if the object contains the same value of fraction as the input object's, return true;
 * 		otherwise, return false
 */
bool fraction::isEqualTo(fraction f)
{
	bool isEqual = false;

	if (double(numerator) * double(f.denominator) == double(denominator) * double(f.numerator))
		isEqual = true;

	return isEqual;
}












/*
 * Add the value of input fraction with the value of this fraction object without
 * changing the value of this fraction object. Return the sum of the two fractions.
 *
 * Input:	a fraction object
 * Output:	the sum of the input fraction and this fraction object
 */
fraction fraction::addedTo(fraction f)
{
	long nu = numerator * f.denominator + f.numerator * denominator;
	long de = denominator * f.denominator;
	
	fraction temp(nu, de);

	return temp;
}












/*
 * Subtract the value of input fraction from the value of this fraction object without
 * changing the value of this fraction object. Return the subtraction result.
 *
 * Input:	a fraction object
 * Output:	the subtraction result of the input fraction object from this fraction object
 */
fraction fraction::subtract(fraction f)
{
	long nu = numerator * f.denominator - f.numerator * denominator;
	long de = denominator * f.denominator;
	
	fraction temp(nu, de);

	return temp;
}












/*
 * Multiply the value of input fraction with the value of this fraction object without
 * changing the value of this fraction object. Return the product result.
 *
 * Input:	a fraction object
 * Output:	the product of the input fraction object and this fraction object
 */
fraction fraction::multipliedBy(fraction f)
{
	long nu = numerator * f.numerator;
	long de = denominator * f.denominator;
	
	fraction temp(nu, de);

	return temp;
}












/*
 * Divide the value of input fraction from the value of this fraction object without
 * changing the value of this fraction object. Return the division result.
 *
 * Input:	a fraction object
 * Output:	the division of the input fraction object from this fraction object
 */
fraction fraction::dividedBy(fraction f)
{
	fraction temp;

	if (f.numerator != 0L)	// execute the division if the denominator does not become zero
	{
		long nu = numerator * f.denominator;
		long de = denominator * f.numerator;
	
		temp.set(nu, de);
	} else	// if the denominator will be zero, return this fraction value instead
	{
		temp.set(numerator, denominator);
	}

	return temp;
}












/*
 * The client program is to execute test cases.
 */
int main()
{
	fraction f1;
	fraction f2;
	fraction result;

	f1.set(9, 8);  
	f2.set(2, 3);   

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

	if (f1.isEqualTo(f2))
	{
		cout << "The two fractions are equal." << endl;
	} else 
	{
		cout << "The two fractions are not equal." << endl;
	}

	return 0;
}










/*

The product of 9/8 and 2/3 is 18/24
The quotient of 9/8 and 2/3 is 27/16
The sum of 9/8 and 2/3 is 43/24
The difference of 9/8 and 2/3 is 11/24
The two fractions are not equal.

 */
