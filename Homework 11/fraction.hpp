/*
 * Name:	Jeffrey Qiu
 * Class:	CS110B
 * Date:	03/28/2015
 * Instructor:	Professor Harden
 * File Name:	fraction.hpp
 * Description: This is the specification file for the fraction class.
 */

#ifndef FRACTION_HPP_
#define FRACTION_HPP_

/*
 * fraction class definition
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
 * There is a print member function. It prints out the string of "numerator/denominator" in this object.
 *
 *	//Pre-condition: None.
 *	void print() const;
 *	//Post-condition: Print the fraction on the console with the format of numerator/denominator.
 *
 * There is an isEqualTo member function which checks whether an input fraction contains the same
 * fraction value as this object's. If they are the same, it returns true; otherwise, it returns false.
 *
 *	//Pre-condition: One fraction object f as input parameter. f cannot be null and f's denominator cannot be zero.
 * 	bool isEqualTo(const fraction & f) const;
 * 	//Post-condition: Compare this->numerator and this->denominator to f.numerator and f.denominator. If they are proportionally
 * 	//same, then return true. Otherwise, return false.
 *
 *
 * There are math member functions, f1 + f2, f1 - f2, f1 * f2, f1 / f2, returns the result in a fraction
 * object without changing either the value of the input fraction object or this object.
 *
 *	//Pre-condition: f is a valid fraction object with a non-zero denominator.
 * 	fraction addedTo(const fraction & f) const;
 * 	//Post-condition: Add f's fraction value with this object's fraction value. Store the result
 * 	//of the operation in the temporary fraction variable and return the temporary fraction.
 *
 * 	//Pre-condition: f is a valid fraction object with a non-zero denominator.
 *  fraction subtract(const fraction & f) const;
 *  //Post-condition: Subtract f's fraction value from this object's fraction value. Store the result
 * 	//of the operation in the temporary fraction variable and return the temporary fraction.
 *
 *  //Pre-condition: f is a valid fraction object with a non-zero denominator.
 *  fraction multipliedBy(const fraction & f) const;
 *  //Post-condition: Multiply f's fraction value with this object's fraction value. Store the result
 * 	//of the operation in the temporary fraction variable and return the temporary fraction.
 *
 *  //Pre-condition: f is a valid fraction object with a non-zero denominator.
 *  fraction dividedBy(const fraction & f) const;
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
	void simplify();
public:
	fraction();
	fraction(long, long);

	void print() const;
	bool isEqualTo(const fraction &) const;
	fraction addedTo(const fraction &) const;
	fraction subtract(const fraction &) const;
	fraction multipliedBy(const fraction &) const;
	fraction dividedBy(const fraction &) const;
};






#endif /* FRACTION_HPP_ */
