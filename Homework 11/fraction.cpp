/*
 * Name:	Jeffrey Qiu
 * Class:	CS110B
 * Date:	03/28/2015
 * Instructor:	Professor Harden
 * File Name:	fraction.cpp
 * Description: This is the implementation file for the fraction class.
 */


#include <iostream>
#include "fraction.hpp"












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
fraction::fraction(long numerator, long denominator)
{
	this->numerator = numerator;
	if (denominator != 0L)
		this->denominator = denominator;
	else
		this->denominator = 1L;

	if (denominator < 0L)
	{
		this->numerator = -this->numerator;
		this->denominator = -this->denominator;
	}

	simplify();
}












/*
 * simplify
 *
 * Pre-condition: 	a fraction object with a non-zero denominator
 * Post-condition:	this fraction object in a simplified fraction form
 *
 * Input: 	none
 * Output: 	none
 */
void fraction::simplify()
{
	long nu = numerator;
	long de = denominator;
	long maxDivider = 1L;

	if (nu < 0L)
		nu = -nu;
	if (de < 0L)
		de = -de;

	if (nu > de)
		maxDivider = de;
	else
		maxDivider = nu;

	for (long i = maxDivider; i > 1L; i--)
	{
		while (numerator % i == 0L && denominator % i == 0L)
		{
			numerator /= i;
			denominator /= i;
		}
	}
}












/*
 * print out the string of "numerator/denominator"
 */
void fraction::print() const
{
	std::cout << numerator << "/" << denominator;
}












/*
 * Check whether the object contains the same fraction value as the input object
 * Note: cast the production of two long values to double is to prevent from value overflow
 *
 * Input:	a const reference of fraction object
 * Output:	if the object contains the same value of fraction as the input object's, return true;
 * 		otherwise, return false
 */
bool fraction::isEqualTo(const fraction & f) const
{
	bool isEqual = false;

	if (double(numerator * f.denominator) == double(denominator * f.numerator))
		isEqual = true;

	return isEqual;
}












/*
 * Add the value of input fraction with the value of this fraction object without
 * changing the value of this fraction object. Return the sum of the two fractions.
 *
 * Input:	a const reference of fraction object
 * Output:	the sum of the input fraction and this fraction object
 */
fraction fraction::addedTo(const fraction & f) const
{
	long numerator = this->numerator * f.denominator + f.numerator * this->denominator;
	long denominator = this->denominator * f.denominator;

	fraction temp(numerator, denominator);

	return temp;
}












/*
 * Subtract the value of input fraction from the value of this fraction object without
 * changing the value of this fraction object. Return the subtraction result.
 *
 * Input:	a const reference of fraction object
 * Output:	the subtraction result of the input fraction object from this fraction object
 */
fraction fraction::subtract(const fraction & f) const
{
	long numerator = this->numerator * f.denominator - f.numerator * this->denominator;
	long denominator = this->denominator * f.denominator;

	fraction temp(numerator, denominator);

	return temp;
}












/*
 * Multiply the value of input fraction with the value of this fraction object without
 * changing the value of this fraction object. Return the product result.
 *
 * Input:	a const reference of fraction object
 * Output:	the product of the input fraction object and this fraction object
 */
fraction fraction::multipliedBy(const fraction & f) const
{
	long numerator = this->numerator * f.numerator;
	long denominator = this->denominator * f.denominator;

	fraction temp(numerator, denominator);

	return temp;
}












/*
 * Divide the value of input fraction from the value of this fraction object without
 * changing the value of this fraction object. Return the division result.
 *
 * Input:	a const reference of fraction object
 * Output:	the division of the input fraction object from this fraction object
 */
fraction fraction::dividedBy(const fraction & f) const
{
	long numerator = 0L;
	long denominator = 1L;

	if (f.numerator != 0L)	// execute the division if the denominator does not become zero
	{
		numerator = this->numerator * f.denominator;
		denominator = this->denominator * f.numerator;
	} else	// if the denominator will be zero, return this fraction value instead
	{
		numerator = this->numerator;
		denominator = this->denominator;
	}

	fraction temp(numerator, denominator);

	return temp;
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







