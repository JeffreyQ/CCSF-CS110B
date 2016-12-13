/*
 * Name:	Jeffrey Qiu
 * Class:	CS110B
 * Date:	04/19/2015
 * Instructor:	Professor Harden
 * File Name:	fraction.h
 * Description: This is the header file for the fraction class.
 */

#ifndef FRACTION_H_
#define FRACTION_H_

/*
 * fraction class definition
 *
 * There is 1 constructor, it can take zero/one/two parameters as input.
 *	//Pre-condition: None.
 *  fraction(long numerator = 0L, long denominator = 1L);
 *  //Post-condition:
 *          if 0 input parameter, numerator sets to 0 and denominator set to 1.
 *          if 1 input parameter, numerator sets to the parameter and denominator sets to 1.
 *          if 2 input parameters, numerator sets to the 1st parameter and denominator sets to the 2nd parameter.
 *
 * There are 6 overloaded logic operators as friend functions of the fraction class:
 *	friend bool operator==(const fraction &, const fraction &);
 *	friend bool operator!=(const fraction &, const fraction &);
 *	friend bool operator<(const fraction &, const fraction &);
 *	friend bool operator<=(const fraction &, const fraction &);
 *	friend bool operator>(const fraction &, const fraction &);
 *	friend bool operator>=(const fraction &, const fraction &);
 * return a boolean value true/false without changing the input fraction objects.
 *
 * There are 5 overloaded assignment and shorthand operators, taking 1 fraction object as the input parameter
 *	fraction& operator=(const fraction &);
 *	fraction& operator+=(const fraction &);
 *	fraction& operator-=(const fraction &);
 *	fraction& operator*=(const fraction &);
 *	fraction& operator/=(const fraction &);
 * return the properly calculated result of corresponding operation in *this reference without changing the input object.
 *
 * There are 4 overloaded math operators as friend functions of the fraction class:
 *	friend fraction operator+(const fraction &, const fraction &);
 *	friend fraction operator-(const fraction &, const fraction &);
 *	friend fraction operator*(const fraction &, const fraction &);
 *	friend fraction operator/(const fraction &, const fraction &);
 * return the result in a fraction object without changing the value of the input fraction objects.
 *
 * There are 4 prefix and postfix incremental and decremental operators.
 * The prefix incremental and decremental operators do not have input parameters:
 * 	fraction& operator++();
 * 	fraction& operator--();
 * return the resulted fraction object and increment or decrement the original object.
 * The postfix incremental and decremental operators take a dummy integer parameter.
 * 	fraction& operator++(int);
 * 	fraction& operator--(int);
 * return the original value of the fraction object and increment or decrement takes place on the original object.
 *
 * There are 2 overloaded stream operators as friend functions of the fraction class:
 * 	friend std::ostream& operator<<(std::ostream &out, const fraction & f);
 * 	The out stream takes one fraction object as an input parameter and writes the formatted fraction value on to
 * 	the o-stream parameter.
 *
 *  friend std::istream& operator>>(std::istream &in, fraction & f);
 *  The in stream reads one fraction object from in and assigns it to the fraction output parameter.
 */






class fraction
{
private:
	long numerator;
	long denominator;
	void simplify();
public:
	fraction(long numerator = 0L, long denominator = 1L);

	friend bool operator==(const fraction &, const fraction &);
	friend bool operator!=(const fraction &, const fraction &);
	friend bool operator<(const fraction &, const fraction &);
	friend bool operator<=(const fraction &, const fraction &);
	friend bool operator>(const fraction &, const fraction &);
	friend bool operator>=(const fraction &, const fraction &);
	fraction& operator=(const fraction &);
	fraction& operator+=(const fraction &);
	fraction& operator-=(const fraction &);
	fraction& operator*=(const fraction &);
	fraction& operator/=(const fraction &);
	friend fraction operator+(const fraction &, const fraction &);
	friend fraction operator-(const fraction &, const fraction &);
	friend fraction operator*(const fraction &, const fraction &);
	friend fraction operator/(const fraction &, const fraction &);
	fraction& operator++();
	fraction operator++(int);
	fraction& operator--();
	fraction operator--(int);
	friend std::ostream& operator<<(std::ostream &out, const fraction & f);
	friend std::istream& operator>>(std::istream &in, fraction & f);
};






#endif /* FRACTION_H_ */

/*
----- Testing basic fraction creation & printing
(fractions should be in reduced form, and as mixed numbers.)
fraction [0] = 1/2
fraction [1] = -5/7
fraction [2] = 10
fraction [3] = -4
fraction [4] = 0
fraction [5] = 4+2/3
fraction [6] = 0

----- Now reading fractions from file
Read fraction = 1/3
Read fraction = 1/2
Read fraction = 3/4
Read fraction = -4/5
Read fraction = 6
Read fraction = 5
Read fraction = -8
Read fraction = 1+2/5
Read fraction = -16+2/3
Read fraction = 1+1/4
Read fraction = 2
Read fraction = -4+1/4
Read fraction = -10+5/6

----- Testing relational operators between fractions
Comparing 1/2 to 1/2
	Is left < right? 0
	Is left <= right? 1
	Is left > right? 0
	Is left >= right? 1
	Does left == right? 1
	Does left != right ? 0
Comparing 1/2 to -1/2
	Is left < right? 0
	Is left <= right? 0
	Is left > right? 1
	Is left >= right? 1
	Does left == right? 0
	Does left != right ? 1
Comparing -1/2 to 1/10
	Is left < right? 1
	Is left <= right? 1
	Is left > right? 0
	Is left >= right? 0
	Does left == right? 0
	Does left != right ? 1
Comparing 1/10 to 0
	Is left < right? 0
	Is left <= right? 0
	Is left > right? 1
	Is left >= right? 1
	Does left == right? 0
	Does left != right ? 1
Comparing 0 to 0
	Is left < right? 0
	Is left <= right? 1
	Is left > right? 0
	Is left >= right? 1
	Does left == right? 1
	Does left != right ? 0

----- Testing relations between fractions and integers
Comparing -1/2 to 2
	Is left < right? 1
	Is left <= right? 1
	Is left > right? 0
	Is left >= right? 0
	Does left == right? 0
	Does left != right ? 1
Comparing -3 to 1/4
	Is left < right? 1
	Is left <= right? 1
	Is left > right? 0
	Is left >= right? 0
	Does left == right? 0
	Does left != right ? 1

----- Testing binary arithmetic between fractions
1/6 + 1/3 = 1/2
1/6 - 1/3 = -1/6
1/6 * 1/3 = 1/18
1/6 / 1/3 = 1/2
1/3 + -2/3 = -1/3
1/3 - -2/3 = 1
1/3 * -2/3 = -2/9
1/3 / -2/3 = -1/2
-2/3 + 5 = 4+1/3
-2/3 - 5 = -5+2/3
-2/3 * 5 = -3+1/3
-2/3 / 5 = -2/15
5 + -1+1/3 = 3+2/3
5 - -1+1/3 = 6+1/3
5 * -1+1/3 = -6+2/3
5 / -1+1/3 = -3+3/4

----- Testing arithmetic between fractions and integers
-1/2 + 4 = 3+1/2
-1/2 - 4 = -4+1/2
-1/2 * 4 = -2
-1/2 / 4 = -1/8
3 + -1/2 = 2+1/2
3 - -1/2 = 3+1/2
3 * -1/2 = -1+1/2
3 / -1/2 = -6

----- Testing shorthand arithmetic assignment on fractions
1/6 += 4 = 4+1/6
4+1/6 -= 4 = 1/6
1/6 *= 4 = 2/3
2/3 /= 4 = 1/6
4 += -1/2 = 3+1/2
3+1/2 -= -1/2 = 4
4 *= -1/2 = -2
-2 /= -1/2 = 4
-1/2 += 5 = 4+1/2
4+1/2 -= 5 = -1/2
-1/2 *= 5 = -2+1/2
-2+1/2 /= 5 = -1/2

----- Testing shorthand arithmetic assignment using integers
-1/3 += 3 = 2+2/3
2+2/3 -= 3 = -1/3
-1/3 *= 3 = -1
-1 /= 3 = -1/3

----- Testing increment/decrement prefix and postfix
Now g = -1/3
g++ = -1/3
Now g = 2/3
++g = 1+2/3
Now g = 1+2/3
g-- = 1+2/3
Now g = 2/3
--g = -1/3
Now g = -1/3
 */

