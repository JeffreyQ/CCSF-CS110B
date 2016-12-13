/*
 * Name:	Jeffrey Qiu
 * Class:	CS110B
 * Date:	04/19/2015
 * Instructor:	Professor Harden
 * File Name:	fraction.cpp
 * Description: This is the implementation file for the fraction class.
 */


#include <iostream>
#include "fraction.h"
#include <stdlib.h>

using namespace std;











// There are two utility functions
// Input parameter: a long integer value
// Output: the sign of the value, if the number is less than 0 return -1L, otherwise return 1L
long l_sign(long lNum)
{
	long ret = 1L;

	if (lNum < 0L)
		ret = -1L;

	return ret;
}












// Input parameter: 2 long integer values
// Output: return the smaller value of the two long integer values
long l_min(long num1, long num2)
{
	if (num1 < num2)
		return num1;

	return num2;
}













/*
 * constructor with initialization values of numerator and denominator
 *
 * Input: two long integers, one for numerator and the other for denominator
 * 		if the value of denominator is 0, the private member denominator will be set to 1
 */
fraction::fraction(long nuParam, long deParam)
{
	numerator = nuParam;
	if (deParam != 0L)
		denominator = deParam;
	else
		denominator = 1L;

	if (deParam < 0L)
	{
		numerator = -numerator;
		denominator = -denominator;
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
	long nu = abs(numerator);
	long de = abs(denominator);
	long loopCtrl = 2L;

	while ( loopCtrl <= l_min(nu, de) )
	{
		if (nu % loopCtrl == 0L && de % loopCtrl == 0L)
		{
			nu /= loopCtrl;
			de /= loopCtrl;
		}
		else
			loopCtrl++;
	}

	if (numerator != 0L)
		numerator = l_sign(numerator) * nu;
	denominator = de;
}












/*
 * Check whether the object contains the same fraction value as the input object
 * Note: cast the production of two long values to double is to prevent from value overflow
 *
 * Input:	a const reference of fraction object
 * Output:	if the object contains the same value of fraction as the input object's, return true;
 * 		otherwise, return false
 */
bool operator==(const fraction & f1, const fraction & f2)
{
	bool twoAreEqual = (f1.numerator * f2.denominator == f2.numerator * f1.denominator);

	return twoAreEqual;
}












/*
 * Check whether the object contains the same fraction value as the input object
 * Note: cast the production of two long values to double is to prevent from value overflow
 *
 * Input:	a const reference of fraction object
 * Output:	if the object contains the same value of fraction as the input object's, return true;
 * 		otherwise, return false
 */
bool operator!=(const fraction & f1, const fraction & f2)
{
	bool twoAreNE = (f1.numerator * f2.denominator != f2.numerator * f1.denominator);

	return twoAreNE;
}












/*
 * Check whether the object contains the same fraction value as the input object
 * Note: cast the production of two long values to double is to prevent from value overflow
 *
 * Input:	a const reference of fraction object
 * Output:	if the object contains the same value of fraction as the input object's, return true;
 * 		otherwise, return false
 */
bool operator<(const fraction & f1, const fraction & f2)
{
	bool isLT = (f1.numerator * f2.denominator < f2.numerator * f1.denominator);

	return isLT;
}












/*
 * Check whether the object contains the same fraction value as the input object
 * Note: cast the production of two long values to double is to prevent from value overflow
 *
 * Input:	a const reference of fraction object
 * Output:	if the object contains the same value of fraction as the input object's, return true;
 * 		otherwise, return false
 */
bool operator<=(const fraction & f1, const fraction & f2)
{
	bool isLE = (f1.numerator * f2.denominator <= f2.numerator * f1.denominator);

	return isLE;
}












/*
 * Check whether the object contains the same fraction value as the input object
 * Note: cast the production of two long values to double is to prevent from value overflow
 *
 * Input:	a const reference of fraction object
 * Output:	if the object contains the same value of fraction as the input object's, return true;
 * 		otherwise, return false
 */
bool operator>(const fraction & f1, const fraction & f2)
{
	bool isGT = (f1.numerator * f2.denominator > f2.numerator * f1.denominator);

	return isGT;
}












/*
 * Check whether the object contains the same fraction value as the input object
 * Note: cast the production of two long values to double is to prevent from value overflow
 *
 * Input:	a const reference of fraction object
 * Output:	if the object contains the same value of fraction as the input object's, return true;
 * 		otherwise, return false
 */
bool operator>=(const fraction & f1, const fraction & f2)
{
	bool isGE = (f1.numerator * f2.denominator >= f2.numerator * f1.denominator);

	return isGE;
}












/*
 * Check whether the object contains the same fraction value as the input object
 * Note: cast the production of two long values to double is to prevent from value overflow
 *
 * Input:	a const reference of fraction object
 * Output:	if the object contains the same value of fraction as the input object's, return true;
 * 		otherwise, return false
 */
fraction& fraction::operator=(const fraction & f)
{
	numerator = f.numerator;
	denominator = f.denominator;

	return *this;
}












/*
 * Check whether the object contains the same fraction value as the input object
 * Note: cast the production of two long values to double is to prevent from value overflow
 *
 * Input:	a const reference of fraction object
 * Output:	if the object contains the same value of fraction as the input object's, return true;
 * 		otherwise, return false
 */
fraction& fraction::operator+=(const fraction & f)
{
	*this = *this + f;

	return *this;
}












/*
 * Check whether the object contains the same fraction value as the input object
 * Note: cast the production of two long values to double is to prevent from value overflow
 *
 * Input:	a const reference of fraction object
 * Output:	if the object contains the same value of fraction as the input object's, return true;
 * 		otherwise, return false
 */
fraction& fraction::operator-=(const fraction & f)
{
	*this = *this - f;

	return *this;
}












/*
 * Check whether the object contains the same fraction value as the input object
 * Note: cast the production of two long values to double is to prevent from value overflow
 *
 * Input:	a const reference of fraction object
 * Output:	if the object contains the same value of fraction as the input object's, return true;
 * 		otherwise, return false
 */
fraction& fraction::operator*=(const fraction & f)
{
	*this = *this * f;

	return *this;
}












/*
 * Check whether the object contains the same fraction value as the input object
 * Note: cast the production of two long values to double is to prevent from value overflow
 *
 * Input:	a const reference of fraction object
 * Output:	if the object contains the same value of fraction as the input object's, return true;
 * 		otherwise, return false
 */
fraction& fraction::operator/=(const fraction & f)
{
	*this = *this / f;

	return *this;
}












/*
 * Add the value of input fraction with the value of this fraction object without
 * changing the value of this fraction object. Return the sum of the two fractions.
 *
 * Input:	a const reference of fraction object
 * Output:	the sum of the input fraction and this fraction object
 */
fraction operator+(const fraction & f1, const fraction & f2)
{
	long numerator = f1.numerator * f2.denominator + f2.numerator * f1.denominator;
	long denominator = f1.denominator * f2.denominator;

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
fraction operator-(const fraction & f1, const fraction & f2)
{
	long numerator = f1.numerator * f2.denominator - f2.numerator * f1.denominator;
	long denominator = f1.denominator * f2.denominator;

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
fraction operator*(const fraction & f1, const fraction & f2)
{
	long numerator = f1.numerator * f2.numerator;
	long denominator = f1.denominator * f2.denominator;

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
fraction operator/(const fraction & f1, const fraction & f2)
{
	long numerator = 0L;
	long denominator = 1L;

	if (f2.numerator != 0L)	// execute the division if the denominator does not become zero
	{
		numerator = f1.numerator * f2.denominator;
		denominator = f1.denominator * f2.numerator;
	} else	// if the denominator will be zero, return this fraction value instead
	{
		numerator = f1.numerator;
		denominator = f1.denominator;
	}

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
fraction& fraction::operator++()
{
	numerator += denominator;

	return *this;
}












/*
 * Divide the value of input fraction from the value of this fraction object without
 * changing the value of this fraction object. Return the division result.
 *
 * Input:	a const reference of fraction object
 * Output:	the division of the input fraction object from this fraction object
 */
fraction fraction::operator++(int unused)
{
	fraction temp(*this);
	numerator += denominator;

	return temp;
}












/*
 * Divide the value of input fraction from the value of this fraction object without
 * changing the value of this fraction object. Return the division result.
 *
 * Input:	a const reference of fraction object
 * Output:	the division of the input fraction object from this fraction object
 */
fraction& fraction::operator--()
{
	numerator -= denominator;

	return *this;
}












/*
 * Divide the value of input fraction from the value of this fraction object without
 * changing the value of this fraction object. Return the division result.
 *
 * Input:	a const reference of fraction object
 * Output:	the division of the input fraction object from this fraction object
 */
fraction fraction::operator--(int unused)
{
	fraction temp(*this);
	numerator -= denominator;

	return temp;
}












ostream& operator<<(ostream & out, const fraction & f)
{
	if (f.denominator == 1L)
		out << f.numerator;
	else if (f.numerator == 0L)
		out << 0;
	else if (abs(f.numerator) < abs(f.denominator))
		out << f.numerator << "/" << f.denominator;
	else
	{
		long wholeNum = f.numerator / f.denominator;
		long numeratorNum = abs(f.numerator) - abs(wholeNum) * f.denominator;
		out << wholeNum << "+" << numeratorNum << "/" << f.denominator;
	}

	return out;
}












istream& operator>>(istream & in, fraction & f)
{
	char c;
	long sign = 1L;
	long temp = 0L;

	if (in.peek() == '-')
	{
		in >> c;
		sign = -1L;
	}

	in >> temp;

	if (in.peek() == ' ' || in.peek() == '\n' || in.peek() == '\t')
	{
		f.numerator = sign * temp;
		f.denominator = 1L;
	}
	else if (in.peek() == '/')
	{
		in >> c;
		f.numerator = sign * temp;
		in >> temp;
		f.denominator = temp;
	}
	else if (in.peek() == '+')
	{
		long wholeNum = temp;
		in >> c;
		in >> temp;
		if (in.peek() == '/')
		{
			in >> c;
			f.numerator = temp;
			in >> temp;
			f.denominator = temp;
			f.numerator = sign * (wholeNum * f.denominator + f.numerator);
		}
	}

	f.simplify();

	return in;
}


