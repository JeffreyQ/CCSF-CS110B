/*
 * Name:		Jeffrey Qiu
 * Class:		CS110B
 * Date:		02/08/2015
 * Instructor:	Professor Harden
 * File name:	a4.cpp
 * Description:
 * This program will read five cards that the user inputs, then analyzes the cards
 * and prints out the type of hand that they represent. Poker hands are categorized
 * as the following: Straight flush, four of a kind, full house, straight, flush,
 * three of a kind, two pairs, pair, and high card. Our deck will not contain card
 * suits and face cards. The value of the cards that the user inputs will be a
 * positive integer value from 2 to 9. When the program is first executed it will
 * prompt the user to input five integer values and store the integers in an array
 * with 5 elements.
 * Also, note that because we do not have card suits we will not have flushes of any
 * kind.
 */





#include <iostream>
#include <stdlib.h>
#include <string.h>

using namespace std;






/*
 * Global Variables and Constants
 */
bool gVerbose = false;		// toggle verbose mode
const int NUM_OF_CARDS = 5;	// maximum number of cards
const int MIN = 2;			// minimum card value is 2
const int MAX = 9;			// maximum card value is 9
const int FOUR_OF_A_KIND = 7;
const int FULL_HOUSE = 6;
const int STRAIGHT = 5;
const int THREE_OF_A_KIND = 4;
const int TWO_PAIR = 3;
const int PAIR = 2;
const int HIGH_CARD = 1; 










/*
 * function prototypes
 */
void testing();
void readCards(int []);
int analyze(int []);
void sort(int []);
void printResult(int);
bool containsFourOfaKind(const int []);
bool containsFullHouse(const int []);
bool containsStraight(const int []);
bool containsThreeOfaKind(const int []);
bool containsTwoPair(const int []);
bool containsPair(const int []);












/*
 * There is an option to run in verbose mode that shows test cases to
 * demonstrate the game, and prints additional information for debugging.
 * When the verbose mode is turned off, it asks the game user to play the
 * game by generating 5 cards within [2, 9]. Then it prints out the result.
 */
int main()
{
	int hand[NUM_OF_CARDS];
	char response = 'y';
	int result = 0;

	cout << "Would you like to turn on the verbose mode? (y/n) ";
	cin >> response;
	if (response == 'y' || response == 'Y')
	{
		gVerbose = true;

		testing();
	}

	cout << endl << "Game starts." << endl;
	do
	{
		readCards(hand);
		result = analyze(hand);
		printResult(result);

		cout << "Would you like to play again? (y/n) ";
		cin >> response;
	} while (response == 'y' || response == 'Y');

	return 0;
}












/*
 * A testing program runs through all 7 kinds of hand of cards.
 */
void testing()
{
	int myCards1[NUM_OF_CARDS] = {8,9,8,8,8};
	int myCards2[NUM_OF_CARDS] = {4,6,4,6,6};
	int myCards3[NUM_OF_CARDS] = {2,3,4,5,6};
	int myCards4[NUM_OF_CARDS] = {9,9,4,9,5};
	int myCards5[NUM_OF_CARDS] = {7,2,7,4,2};
	int myCards6[NUM_OF_CARDS] = {2,8,3,3,5};
	int myCards7[NUM_OF_CARDS] = {7,2,3,4,9};
	int result = 0;

	result = analyze(myCards1);
	printResult(result);

	result = analyze(myCards2);
	printResult(result);

	result = analyze(myCards3);
	printResult(result);

	result = analyze(myCards4);
	printResult(result);

	result = analyze(myCards5);
	printResult(result);

	result = analyze(myCards6);
	printResult(result);

	result = analyze(myCards7);
	printResult(result);
}












/*
 * Read NUM_OF_CARDS cards into an array. The values in the array will be returned to the caller.
 * If the user enters a non-number or a number outside of the range, then it asks the user to
 * enter a number for the same card until the input is correct.
 * 
 * Input/Output parameter: integer array
 */
void readCards(int hand[])
{
	cout << endl << "Please enter " << NUM_OF_CARDS << " cards between " << MIN << " and " << MAX << "." << endl;

	for (int i = 0; i < NUM_OF_CARDS; i++)
	{
		do
		{
			string input;

			cout << "Card " << i+1 << ": ";
			cin >> input;
			hand[i] = atoi(input.c_str());
		} while ((hand[i] < MIN) || (hand[i] > MAX));
	}

	cout << endl;
}












/*
 * The function takes an array with 5 cards. It then sorts the numbers in the array.
 * After the array is sorted, it checks what kind of cards in hand and return the
 * result to the caller.
 *
 * Input parameter: an array with 5 cards within [2, 9]
 * Return value: the type of the cards in hand
 */
int analyze(int hand[])
{
	int result = 0;

	if (gVerbose)
		for (int i=0; i < NUM_OF_CARDS; i++)
			cout << "Card " << i+1 << ": " << hand[i] << endl;

	sort(hand);

	if (containsFourOfaKind(hand))
		result = FOUR_OF_A_KIND;
	else if (containsFullHouse(hand))
		result = FULL_HOUSE;
	else if (containsStraight(hand))
		result = STRAIGHT;
	else if (containsThreeOfaKind(hand))
		result = THREE_OF_A_KIND;
	else if (containsTwoPair(hand))
		result = TWO_PAIR;
	else if (containsPair(hand))
		result = PAIR;
	else
		result = HIGH_CARD;

	return result;
}












/*
 * Sort the array from smallest value to largest value and print the sorted
 * array in the verbose mode.
 *
 * Input parameter: pointer to an integer array with NUM_OF_CARDS elements
 * Output parameter: pointer to the same array which has sorted numbers
 */
void sort(int hand[])
{
	for (int i = 0; i < NUM_OF_CARDS - 1; i++)
		for (int j = i+1; j < NUM_OF_CARDS; j++)
			if (hand[i] > hand[j])
			{
				int temp = hand[i];
				hand[i] = hand[j];
				hand[j] = temp;
			}

	if (gVerbose)
	{
		cout << endl << "Sorted cards: " << endl;
		for (int i=0; i < NUM_OF_CARDS; i++)
			cout << "Card " << i+1 << ": " << hand[i] << endl;
		cout << endl;
	}
}










/*
 * Based on the result, print the corresponding message
 *
 * Input parameter: integer value for the result
 */
void printResult(int result)
{
	switch (result)
	{
		case FOUR_OF_A_KIND : 
			cout << "Four Of a Kind.";
			break;
		case FULL_HOUSE :
			cout << "Full House.";
			break;
		case STRAIGHT : 
			cout << "Straight.";
			break;
		case THREE_OF_A_KIND :
			cout << "Three Of a Kind.";
			break;
		case TWO_PAIR :
			cout << "Two Pair.";
			break;
		case PAIR :
			cout << "Pair.";
			break;
		default :
			cout << "High Card.";
	}
	cout << endl << endl;
}












/*
 * check if the sorted array has 4 cards with the same value
 *
 * Input parameter: pointer to a sorted integer array
 * Return value: if it has 4 cards with the same value, returns true; otherwise, returns false
 */
bool containsFourOfaKind(const int hand[])
{
	bool isFourOfaKind = false;

	if (hand[1] == hand[2] && hand[1] == hand[3])
	{
		if (hand[0] == hand[1] || hand[3] == hand[4])
			isFourOfaKind = true;
	}

	return isFourOfaKind;
}












/*
 * check if the sorted array has 1 pair and 1 three of a kind
 *
 * Input parameter: pointer to a sorted integer array
 * Return value: if it has 5 consecutive cards, returns true; otherwise, returns false
 */
bool containsFullHouse(const int hand[])
{
	bool isFullHouse = false;

	if (hand[0] == hand[1] && hand[0] == hand[2] && hand[3] == hand[4])
		isFullHouse = true;
	else if (hand[0] == hand[1] && hand[2] == hand[3] && hand[2] == hand[4])
		isFullHouse = true;

	return isFullHouse;
}












/*
 * check if the sorted array has 5 consecutive cards
 *
 * Input parameter: pointer to a sorted integer array
 * Return value: if it has 5 consecutive cards, returns true; otherwise, returns false
 */
bool containsStraight(const int hand[])
{
	int prev = hand[0];
	int i = 1;
	bool isStraight = true;
/*
	while (i < NUM_OF_CARDS && isStraight)
	{
		if (hand[i] == prev + 1)	
			prev = hand[i];
		else 
			isStraight = false;
		i++;
	}
*/
	for (i = 1; i < NUM_OF_CARDS && isStraight; i++)
	{
		if (hand[i] == prev + 1)
			prev = hand[i];
		else
			isStraight = false;
	}

	return isStraight;
}












/*
 * check if the sorted array has 3 cards with the same value
 *
 * Input parameter: pointer to a sorted integer array
 * Return value: if it has 3 cards with the same value, returns true; otherwise, returns false
 */
bool containsThreeOfaKind(const int hand[])
{
	bool isThreeOfaKind = false;

	if (hand[0] == hand[1] && hand[0] == hand[2])
		isThreeOfaKind = true;
	else if (hand[1] == hand[2] && hand[1] == hand[3])
		isThreeOfaKind = true;
	else if (hand[2] == hand[3] && hand[2] == hand[4])
		isThreeOfaKind = true;

	return isThreeOfaKind;
}












/*
 * check if the sorted array has two pairs of cards with the same value
 *
 * Input parameter: pointer to a sorted integer array
 * Return value: if it has 2 pairs, returns true; otherwise, returns false
 */
bool containsTwoPair(const int hand[])
{
	bool isTwoPair = false;

	if (hand[0] == hand[1] && hand[2] == hand[3])
		isTwoPair = true;
	else if (hand[1] == hand[2] && hand[3] == hand[4])
		isTwoPair = true;
	else if (hand[0] == hand[1] && hand[3] == hand[4])
		isTwoPair = true;

	return isTwoPair;		
}












/*
 * check if the sorted array has at least one pair of cards with the same value
 *
 * Input parameter: pointer to a sorted integer array
 * Return value: if it has a pair, returns true; otherwise, returns false
 */
bool containsPair(const int hand[])
{
	bool isPair = false;

	if (hand[0] == hand[1])
		isPair = true;
	else if (hand[1] == hand[2])
		isPair = true;
	else if (hand[2] == hand[3])
		isPair = true;
	else if (hand[3] == hand[4])
		isPair = true;

	return isPair;		
}












/*

Would you like to turn on the verbose mode? (y/n) n

Game starts.

Please enter 5 cards between 2 and 9.
Card 1: 2
Card 2: 3
Card 3: 4
Card 4: 5
Card 5: 6

Straight.

Would you like to play again? (y/n) y

Please enter 5 cards between 2 and 9.
Card 1: 6
Card 2: 7
Card 3: 8
Card 4: 7
Card 5: 6

Two Pair.

Would you like to play again? (y/n) y

Please enter 5 cards between 2 and 9.
Card 1: 6
Card 2: 7
Card 3: 6
Card 4: 6
Card 5: 6

Four Of a Kind.

Would you like to play again? (y/n) y

Please enter 5 cards between 2 and 9.
Card 1: 9
Card 2: 2
Card 3: 9
Card 4: 2
Card 5: 2

Full House.

Would you like to play again? (y/n) y

Please enter 5 cards between 2 and 9.
Card 1: 5
Card 2: 8
Card 3: 6
Card 4: 5
Card 5: 5

Three Of a Kind.

Would you like to play again? (y/n) y

Please enter 5 cards between 2 and 9.
Card 1: 3
Card 2: 2
Card 3: 4
Card 4: 5
Card 5: 7

High Card.

Would you like to play again? (y/n) y

Please enter 5 cards between 2 and 9.
Card 1: 5
Card 2: 6
Card 3: 5
Card 4: 7
Card 5: 6

Two Pair.

Would you like to play again? (y/n) n


 */

