/*
 * Name:	Jeffrey Qiu
 * Class:	CS110B
 * Date:	04/19/2015
 * Instructor:	Professor Harden
 * File Name:	fraction.h
 * Description: This is the implementation file for the myString class.
 */






#include "myString.h"






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






// constant
const int LINESIZE = 128;





// constructor, no input parameter, allocate 1 char space for str and store the null terminator into the space.
myString::myString()
{
	str = new char[1];
	str[0] = '\0';
}





// constructor, takes a c-style string as the input parameter, allocate strlen(s)+1 for member str and copy the string s into it.
myString::myString(const char * s)
{
	if (s == NULL)
	{
		str = new char[1];
		str[0] = '\0';
	}
	else
	{
		int iLen = strlen(s) + 1;

		str = new char[iLen];
		strcpy(str, s);
	}
}






// constructor, takes a myString object myStr as the input parameter, allocate myStr.strlen(s)+1 for member str and copy the
// myStr.str into it.
myString::myString(const myString & myStr)
{
	int iLen = strlen(myStr.str) + 1;

	str = new char[iLen];
	strcpy(str, myStr.str);
}






// destructor, it de-allocates the memory allocated for str, and then destroy itself.
myString::~myString()
{
	delete [] str;
}






// length(), returns the number of characters stored in member str.
int myString::length() const
{
	return strlen(str);
}






// operator[], it takes an integer as input parameter. If the integer value is neither < 0 nor >= strlen(str), it returns str[index] value.
char myString::operator[](int index) const
{
	int iLen = strlen(str);

	assert(index >= 0 && index < iLen);

	return str[index];
}






// operator[], it takes an integer as input parameter. If the integer value is neither < 0 nor >= strlen(str), it returns str[index] reference.
char & myString::operator[](int index)
{
	int iLen = strlen(str);

	assert(index >= 0 && index < iLen);

	return str[index];
}






// operator=, it takes 1 myString object as input parameter. If the source is the same as left hand side variable, it does not do anything
// but returns the reference to itself. Otherwise, it makes a copy of source.str and puts it into member str.
myString & myString::operator=(const myString & source)
{
	if (this == &source)
		return *this;

	delete [] str;
	str = new char[source.length() + 1];
	strcpy(str, source.str);

	return *this;
}






// operator+=, it takes 1 myString object source as input parameter. It concatenates the source.str value into member str. Of course, all the
// memory allocation and deallocation have to be correctly made.
myString & myString::operator+=(const myString & source)
{
	int iLen = length() + source.length() + 1;
	char * tmp = new char[iLen];
	strcpy(tmp, str);
	strcat(tmp, source.str);

	delete [] str;
	str = tmp;

	return *this;
}






// friend operator+, it takes 2 myString objects s1 and s2 as input parameters. It concatenates the s1.str and s2.str, and returns a temporary
// myString object to keep the result. Of course, all the memory allocation and deallocation have to be correctly made.
myString operator+(const myString & s1, const myString & s2)
{
	char * tmp = new char[s1.length() + s2.length() + 1];
	strcpy(tmp, s1.str);
	strcat(tmp, s2.str);

	myString tmpString;
	delete [] tmpString.str;
	tmpString.str = tmp;

	return tmpString;
}






// operator==, takes two myString objects s1 and s2 as input parameters. Compare s1.str and s2.str, and return true/false based on the comparison.
bool operator==(const myString & s1, const myString & s2)
{
	bool result = (strcmp(s1.str, s2.str) == 0);
	return result;
}






// operator!=, takes two myString objects s1 and s2 as input parameters. Compare s1.str and s2.str, and return true/false based on the comparison.
bool operator!=(const myString & s1, const myString & s2)
{
	bool result = (strcmp(s1.str, s2.str) != 0);
	return result;
}






// operator<, takes two myString objects s1 and s2 as input parameters. Compare s1.str and s2.str, and return true/false based on the comparison.
bool operator<(const myString & s1, const myString & s2)
{
	bool result = (strcmp(s1.str, s2.str) < 0);
	return result;
}






// operator<=, takes two myString objects s1 and s2 as input parameters. Compare s1.str and s2.str, and return true/false based on the comparison.
bool operator<=(const myString & s1, const myString & s2)
{
	bool result = (strcmp(s1.str, s2.str) <= 0);
	return result;
}






// operator>, takes two myString objects s1 and s2 as input parameters. Compare s1.str and s2.str, and return true/false based on the comparison.
bool operator>(const myString & s1, const myString & s2)
{
	bool result = (strcmp(s1.str, s2.str) > 0);
	return result;
}






// operator>=, takes two myString objects s1 and s2 as input parameters. Compare s1.str and s2.str, and return true/false based on the comparison.
bool operator>=(const myString & s1, const myString & s2)
{
	bool result = (strcmp(s1.str, s2.str) >= 0);
	return result;
}






// insertion function, prints out source.str on the putput stream
ostream & operator<<(ostream & out, const myString & source)
{
	out << source.str;

	return out;
}






// extraction function, read one myString object from the input stream and put it into target.
istream & operator>>(istream & in, myString & target)
{
	char * input = new char[LINESIZE];

	in >> input;
	target = input;

	delete [] input;
	return in;
}






// read() member function. It takes two input parameters, in and stopChar. It read the characters from in until it hits stopChar.
// Then it puts the read characters into member str. Of course, all memory allocation and deallocation are taken care of.
// There is an assumption that the input string will be less than 127 characters (before hitting the stopChar).
void myString::read(istream & in, char stopChar)
{
	char ch = '\0';
	int i = 0;
	char * buffer = new char[LINESIZE];

	while (in && in.peek() != stopChar)
	{
		in.get(ch);
		buffer[i] = ch;
		i++;
	}
	buffer[i] = '\0';
	in.ignore(1, stopChar);

	delete [] str;
	str = new char[i+1];
	strcpy(str, buffer);

	delete [] buffer;
}



