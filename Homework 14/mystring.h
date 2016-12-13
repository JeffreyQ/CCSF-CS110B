/*
 * Name:	Jeffrey Qiu
 * Class:	CS110B
 * Date:	05/3/2015
 * Instructor:	Professor Harden
 * File Name:	mystring.h
 * Description: This is the header file for the myString class.
 */

#ifndef MYSTRING_H_
#define MYSTRING_H_

#include <iostream>
#include <cassert>

using namespace std;





/*
 * myString class definition
 *
 * myString has a private member str which is a (char *) pointing to a c-style string.
 * Pointer str will have been allocated at least 1 char space by the constructors.
 * Therefore, pointer str will never be a NULL pointer.
 *
 * There are three constructors:
 * 	myString():
 * 		Takes no input parameter, allocates 1 char to str pointer and puts the NULL terminator there.
 * 	myString(const char *):
 * 		Takes 1 c-style string as input parameter, allocates strlen(c-style string)+1 bytes to str and copy the s-style string to there.
 * 	myString(const MyString &):
 * 		Takes 1 myString object source as input parameter, allocates strlen(source.str)+1 bytes to str and copy source.str to there.
 *
 * There is one destructor:
 *  ~myString():
 *  	It deletes the memory allocated for str and then destroy itself.
 *
 * There is a member function length().
 * 	int length() const:
 * 		It takes no input parameter and returns length of the string stored in str member variable.
 *
 * There are two [] operator overloading functions. One returns the value and the other returns reference.
 * 	char operator[](int index) const:
 * 		It takes one input parameter index and returns the value stored in str[index]. Index must be >= 0 and < strlen(str).
 * 	char& operator[](int index):
 * 		It takes one input parameter index and returns the reference to str[index]. Index must be >= 0 and < strlen(str).
 *
 * There is an assignment operator overloading member function.
 *  myString & operator=(const myString & source):
 *  	It takes one input myString object as the input parameter. If the target object is the same as the input parameter,
 *  	it returns the reference to itself. Otherwise, it allocates length(source.str)+1 bytes for str and copies the
 *  	content of source.str to str.
 *
 * There is a shorthand += overloading member function.
 *  myString & operator+=(const myString & source):
 *  	It takes a myString object source as input parameter. It concatenates str and source.str, and allocates the length of
 *  	the combined string plus 1 bytes to str, and copies the concatenated string to str. Before the copy operation, the
 *  	original memory allocated to str is deleted.
 *
 * There is a friend + overloading function.
 *  friend myString operator+(const myString &, const myString &);
 *  	It takes two myString objects as input parameters s1 and s2. It concatenates s1.str and s2.str, then constructs a
 *  	temporary myString object tmp as return value.
 *
 * There is an insertion overloading function.
 *  friend ostream & operator<<(ostream & out, const myString & source);
 *  	It takes two input parameters, ostream & out and myString & source. It prints out the c-style string stored in
 *  	the source.str.
 *
 * There is an extraction overloading function.
 *  friend istream & operator>>(istream & in, myString & target);
 *  	It takes two input parameters, istream & in and myString & target. It reads one word at a time from the input stream
 *  	and puts the word inside the target myString object.
 *
 * There is an read member function.
 * 	void read(istream & in, char stopChar);
 * 		It takes two input parameters, istream & in and char stopChar. It reads the characters from input stream until it hits
 * 		a stopChar or up to 127 characters. Then, it puts the inputed string into the private member str.
 *
 * There are six logical comparison friend functions.
 * 	friend bool operator==(const myString & s1, const myString & s2);
 *	friend bool operator!=(const myString & s1, const myString & s2);
 *	friend bool operator<(const myString & s1, const myString & s2);
 *	friend bool operator<=(const myString & s1, const myString & s2);
 * 	friend bool operator>(const myString & s1, const myString & s2);
 *	friend bool operator>=(const myString & s1, const myString & s2);
 * 		They take two myString object input parameters - s1 and s2 and return a boolean result of
 * 		s1 == s2
 * 		s1 != s2
 * 		s1 <  s2
 * 		s1 <= s2
 * 		s1 >  s2
 * 		s1 >= s2
 *
 */
class myString {
private:
	char * str;
public:
	myString();
	myString(const char *);
	myString(const myString &);
	~myString();

	int length() const;
    char operator[](int index) const;
    char & operator[](int index);

    myString & operator=(const myString &);
	myString & operator+=(const myString &);
    friend myString operator+(const myString &, const myString &);

    friend ostream & operator<<(ostream &, const myString &);
    friend istream & operator>>(istream &, myString &);
	void read(istream &, char);

	friend bool operator==(const myString &, const myString &);
	friend bool operator!=(const myString &, const myString &);
	friend bool operator<(const myString &, const myString &);
	friend bool operator<=(const myString &, const myString &);
	friend bool operator>(const myString &, const myString &);
	friend bool operator>=(const myString &, const myString &);
};






#endif /* MYSTRING_H_ */










/*


----- Testing basic String creation & printing
string [0] = Wow
string [1] = C++ is neat!
string [2] =
string [3] = a-z

----- Now reading myStrings from file

----- first, word by word
Read string = The
Read string = first
Read string = time
Read string = we
Read string = will
Read string = read
Read string = individual
Read string = words,
Read string = next
Read string = we
Read string = read
Read string = whole
Read string = lines

----- now, line by line
Read string = The  first  time  we  will
Read string =     read individual words, next
Read string = we read whole lines

----- Testing access to characters (using const)
Whole string is abcdefghijklmnopqsrtuvwxyz
now char by char: abcdefghijklmnopqsrtuvwxyz
----- Testing access to characters (using non-const)
Start with abcdefghijklmnopqsrtuvwxyz and convert to ABCDEFGHIJKLMNOPQSRTUVWXYZ

----- Testing relational operators between myStrings
Comparing app to apple
	Is left < right? 1
	Is left <= right? 1
	Is left > right? 0
	Is left >= right? 0
	Does left == right? 0
	Does left != right ? 1
Comparing apple to
	Is left < right? 0
	Is left <= right? 0
	Is left > right? 1
	Is left >= right? 1
	Does left == right? 0
	Does left != right ? 1
Comparing  to Banana
	Is left < right? 1
	Is left <= right? 1
	Is left > right? 0
	Is left >= right? 0
	Does left == right? 0
	Does left != right ? 1
Comparing Banana to Banana
	Is left < right? 0
	Is left <= right? 1
	Is left > right? 0
	Is left >= right? 1
	Does left == right? 1
	Does left != right ? 0

----- Testing relations between myStrings and char *
Comparing he to hello
	Is left < right? 1
	Is left <= right? 1
	Is left > right? 0
	Is left >= right? 0
	Does left == right? 0
	Does left != right ? 1
Comparing why to wackity
	Is left < right? 0
	Is left <= right? 0
	Is left > right? 1
	Is left >= right? 1
	Does left == right? 0
	Does left != right ? 1

----- Testing concatentation on myStrings
outrageous + milk = outrageousmilk
milk +  = milk
 + cow = cow
cow + bell = cowbell

----- Testing concatentation between myString and char *
abcde + XYZ = abcdeXYZ
XYZ + abcde = XYZabcde

----- Testing shorthand concat/assign on myStrings
who += what = whowhatandwhowhat
what += WHEN = whatWHENandwhatWHEN
WHEN += Where = WHENWhereandWHENWhere
Where += why = WherewhyandWherewhy

----- Testing shorthand concat/assign using char *
I love  += programming = I love programming

----- Testing copy constructor and operator= on myStrings
original is cake, copy is fake
original is cake, copy is fake
after self assignment, copy is Copy Cat
Testing pass & return myStrings by value and ref
after calling Append, sum is BinkyBoo
val is winky
after assign,  val is BinkyBoo

*/
