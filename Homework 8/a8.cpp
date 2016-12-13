/*
 * Name:	Jeffrey Qiu
 * Class:	CS110B
 * Date:	03/08/2015
 * Instructor:	Professor Harden
 * File name: 	a8.cpp
 * Description: This program contains five different functions to process and deal with null terminated C-Style strings.
 *
 */


#include <iostream>
#include <string.h>
using namespace std;





/*
 * Global constant.
 */
const int MAX_STRING_SIZE = 200;











/*
 * function prototypes
 */
int lastIndexOf(char *, char);
void reverse(char *);
int replace(char *, char, char);
bool isMatch(char *, char *, int);
int findSubstring(char *, char []);
bool isPalindrome(char *);












/*
 * test all C-string functions built in this assignment
 */
int main()
{
	char str[MAX_STRING_SIZE] = {"I am a student."};
	char substr[MAX_STRING_SIZE] = {"student"};
	char strBad[MAX_STRING_SIZE] = {""};

	cout << "str\t:\t" << "\"" << str << "\"" << endl;
	cout << "substr\t:\t" << "\"" << substr << "\"" << endl;
	cout << "strBad\t:\t" << "\"" << strBad << "\"" << endl;

	cout << "lastIndexOf(str, 's')\t:\t" << lastIndexOf(str, 's') << endl;

	cout << "lastIndexOf(str, '%')\t:\t" << lastIndexOf(str, '%') << endl;

	reverse(str);
	cout << "reverse(str)\t:\t" << "\"" << str << "\"" << endl;

	cout << "replace(str, 'a', 'A')\t:\t" << replace(str, 'a', 'A') << "\t" << "\"" << str << "\"" << endl;

	reverse(str);
	cout << "reverse(str)\t:\t" << "\"" << str << "\"" << endl;

	cout << "findSubstring(str, substr)\t:\t" << findSubstring(str, substr) << endl;
	cout << "findSubstring(str, \"A\")\t:\t" << findSubstring(str, (char *)"A") << endl;

	cout << "findSubstring(strBad, substr)\t:\t" << findSubstring(strBad, substr) << endl;

	cout << "isPalindrome(str)\tyes=1/no=0\t:\t" << isPalindrome(str) << endl;
	cout << "isPalindrome(\"neveroddoreven\")\tyes=1/no=0\t:\t" << isPalindrome((char*)"neveroddoreven") << endl;

	return 0;
}













/*
 * Given a C-string and a character, find the last occurrence of the character in the string
 * 
 * Input: 	a null terminated C-string, a target character
 * Output:	the position of the last occurrence of the character in the C-string
 *		if not found, return -1
 */
int lastIndexOf(char *str, char target)
{
	int index = -1;
	bool found = false;

	if (str != NULL)
	{
		index = strlen(str) - 1;
		while (index >= 0 && !found)
		{
			if (str[index] == target)
				found = true;
			else
				index--;
		}
	}
	
	return index;
}












/* 
 * Given a C-string, reverse the content of the string
 *
 * Input/Output: a null terminated C-string
 */
void reverse(char *str)
{
	if (str != NULL)
	{
		int len = strlen(str);

		for (int i = 0; i <= len / 2 - 1; i++)
		{
			char temp = str[i];
			str[i] = str[len - 1 - i];
			str[len - 1 - i] = temp;
		}
	}
}












/*
 * Given a null-terminated C-string, a target character and a replacement character
 * replace all target characters in the stirng with the replacement character.
 *
 * Input: 	a null-terminated C-string, a target character, a replacement character
 * Output: 	the string with replacement characters
 * Return value: 	number of characters being replaced
 */
int replace(char *str, char target, char replacementChar)
{
	int numRepl = 0;

	if (str != NULL)
	{
		for (int i = 0; i < (int) strlen(str); i++)
			if (str[i] == target)
			{
				str[i] = replacementChar;
				numRepl++;
			}
	}

	return numRepl;
}












/*
 * Given two char arrays with the same size, compare the content, if same content, return true; 
 * otherwise, return false
 *
 * Input: 	array1, array2, and size of the char arrays to be compared
 * Output:	true if the same content of array1 and array2; otherwise false
 */
bool isMatch(char *array1, char *array2, int size)
{
	bool match = true;
	int i = 0;

	while (i < size && match)
	{
		if (array1[i] != array2[i])
			match = false;
		else
			i++;
	}

	return match;
}












/*
 * Given two null terminated C-strings, find out whether the 1st string contains a substring 
 * that matches the 2nd string.
 *
 * Input:	a null terminated C-string, another null terminated C-string for substring search
 * Return Value:	if the 1st string contains a substring matching the 2nd string, return the
 *			index of the first occurance in the 1st string.
 */
int findSubstring(char *str, char substr[])
{
	int index = -1;

	if (str != NULL && substr != NULL && substr[0] != '\0')
	{
		int lenStr = strlen(str);
		int lenSubstr = strlen(substr);
		bool stop = false;
		index = 0;

		while (!stop)
		{
			if (lenStr - index < lenSubstr)
			{
				stop = true;
				index = -1;
			}
			else if (isMatch(&str[index], substr, lenSubstr))
			{
				stop = true;
			}				
			else
				index++;
		}
	}

	return index;
}












/*
 * Given a null terminated C-string, find out if it is a palindrome.
 *
 * Take note that a null string does not count as a palindrome. (i.e. strlen = 0)
 *
 * Input:	a null terminated C-string
 * Return Value: 	true if the string is a palindrome; otherwise false
 */
bool isPalindrome(char *str)
{
	bool palindrome = true;

	if (str != NULL)
	{
		int len = strlen(str);
		bool stop = false;
		int i = 0;

		while (!stop && i <= len / 2 - 1)
		{
			if (str[i] != str[len - 1 -i])
			{
				palindrome = false;
				stop = true;
			}
			else 
				i++;
		}
	}

	return palindrome;
}













/*

str	:	"I am a student."
substr	:	"student"
strBad	:	""
lastIndexOf(str, 's')	:	7
lastIndexOf(str, '%')	:	-1
reverse(str)	:	".tneduts a ma I"
replace(str, 'a', 'A')	:	2	".tneduts A mA I"
reverse(str)	:	"I Am A student."
findSubstring(str, substr)	:	7
findSubstring(str, "A")	:	2
findSubstring(strBad, substr)	:	-1
isPalindrome(str)	yes=1/no=0	:	0
isPalindrome("neveroddoreven")	yes=1/no=0	:	1




*/


