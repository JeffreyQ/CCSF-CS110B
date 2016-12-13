/*
 * Name: 	Jeffrey Qiu
 * Class: 	CS110B
 * Date: 	01/29/2015
 * Instructor:	Professor Harden
 * File name: 	a3.cpp
 * Description:
 * A game user thinks about a number within [1, 100] and let the program guess what
 * the number is. The program will use binary search to make a guess of this number.
 * When the guessed number is lower than the number, user will answer "l" (lower).
 * When the guessed number is higher than the number, user will answer "h" (higher).
 * When the guessed number equals to the number, user will answer "c" (correct), then
 * the game is over. The program will ask the game user whether she wants to play
 * again, if the answer is "y" (yes), the program will repeat the same game.
 *
 */






#include <iostream>
#include <stdlib.h>
using namespace std;






// Global Constants

const int MIN_NUMBER = 1;
const int MAX_NUMBER = 100;






// Function Prototypes

void helper();

int getMidPoint(int, int);

void getUserResponseToGuess(int, char&);

int playGame(int, int);












/*
 * main() allows a player to repeat the game over and over again until he/she decides to stop
 *
 * A response other than 'y' and 'Y' will be considered as NO.
 */
int main(int argc, char* argv[])
{
    char response = 'n';
    int theNumber = 0;

    if (argc > 1)
        helper();

    cout << "Ready to play the number guess game? (y/n): ";
    cin >> response;
    while (response == 'y' || response == 'Y')
    {
        theNumber = playGame(MIN_NUMBER, MAX_NUMBER);
        cout << endl << "The number is " << theNumber << endl;

        if (theNumber < 0)
            cout << endl << "Your answers were invalid." << endl;

        cout << endl << "Would you like to play the game again? (y/n): ";
        cin >> response;
    }

    return 0;
}












void helper()
{
    cout << "Number guess game." << endl;
    cout << "\tPlease think of a number. When the computer prompts a guess, ";
    cout << "please enter h for higher, l for lower, and c for correct." << endl;
    exit(0);
}












/*
 * Calculate the mid point number of low and high values.
 *
 * Input Parameters:
 *      low -- the lower value
 *      high -- the higher value
 *
 * Return Value: the value of mid point of the low and high values
 */
int getMidPoint(int low, int high)
{
        int midPoint = (low + high) / 2;

        return midPoint;
}












/*
 * Pass in the guessed number and asks the user to confirm if the value
 * is higher (h) or lower (l) than guessed number or correct answer (c).
 * If the answer is not (h/l/c), the function will ask the question
 * again until a correct answer is entered.
 *
 * Input Parameter:
 *      guess -- it is the guessed number
 * Output Parameter:
 *      result -- use a reference to bring back the value from the function
 */
void getUserResponseToGuess(int guess, char& result)
{
    do {
        cout << endl << "Is it " << guess << "? (h/l/c): ";
        cin >> result;
        if (result == 'h' || result == 'H')
            result = 'h';
        else if (result == 'l' || result == 'L')
            result = 'l';
        else if (result == 'c' || result == 'C')
            result = 'c';
        else {
            cout << endl << "Please enter (h/l/c).";
            result = 'w';
        }
    } while (result == 'w');
}












/*
 * This is a recursive function which guess the number by using binary search.
 *
 * Return Value: the correctly guessed number if no error
 *		 otherwise, returns -1
 */
int playGame(int low, int high)
{
    char response = '0';
    int theNumber = 0;

    if (low > high)
        return -1;
    else
        theNumber = getMidPoint(low, high);

    getUserResponseToGuess(theNumber, response);

    if (response == 'h') {
        low = theNumber + 1;
        theNumber = playGame(low, high);
    } else if (response == 'l') {
        high = theNumber - 1;
        theNumber = playGame(low, high);
    }

    return theNumber;
}






/*

Ready to play the number guess game? (y/n): y

Is it 50? (h/l/c): h

Is it 75? (h/l/c): h

Is it 88? (h/l/c): l

Is it 81? (h/l/c): c

The number is 81

Would you like to play the game again? (y/n): y

Is it 50? (h/l/c): c

The number is 50

Would you like to play the game again? (y/n): y

Is it 50? (h/l/c): h

Is it 75? (h/l/c): l

Is it 62? (h/l/c): l

Is it 56? (h/l/c): l

Is it 53? (h/l/c): l

Is it 51? (h/l/c): l

The number is -1

Your answers were invalid.

Would you like to play the game again? (y/n): n

 */
