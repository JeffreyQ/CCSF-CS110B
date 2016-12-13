/*
 * Name:		Jeffrey Qiu
 * Class:		CS110B
 * Date:		01/25/2015
 * Instructor:	Professor Harden
 * File name:	a2.cpp
 * Description:
 * This program emulates the card game called 'blackjack'. In this game
 * the user gets two cards to start with, and then she is asked whether
 * or not she should be dealt one more card. The user can continue to take
 * as many cards as she likes, responding with 'y' for yes and 'n' for no.
 * The objective of this game is to get as close as possible to a total of
 * 21 without going over. In this version of the game a random number
 * between 1 and 10 will be generated each time the player gets a card.
 * Each of the values [1, 10] will be equally likely. A running total
 * of the player's cards will be documented and the player will be asked
 * whether or not a new card should be dealt.
 * Also, in this simplified blackjack game there are no suits, and any
 * particular card can appear any number of times.
 */




#include <iostream>
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
using namespace std;




/*
 * Global Constants
 */
const int nonBustedMaxValue = 21;	// The biggest value that is not a bust
const int cardMaxValue = 10;    	// The largest value that a card can be






/*
 * The new_card function first creates a new card by generating a random
 * number within [1, cardMaxValue]. After creating the new card, it prints out
 * the sequence # and the value of the card. The value is also returned to
 * the caller.
 *
 * Input Parameter: cardNo  -  this is the sequence # of the new card
 * Return Value: the value of the new card
 */
int new_card(int cardNo)
{
    int newCard = rand() % cardMaxValue + 1;	// get a random number [1, cardMaxValue] for a new card
    cout << "No. " << cardNo << " card:\t" << newCard << endl;

    return newCard;
}












/*
 * This is the function which allows the user to play the blackjack
 * game once. First, two cards, between one to ten, are dealt. Then,
 * the total of the two cards is calculated and displayed. If the
 * user input is yes, and the total value is less than 21, then the
 * user will be prompted whether or not to draw a new card. If yes,
 * a new card will be dealt, the new total will be calculated, and
 * if the total is still less than 21 the user will be prompted
 * again to draw a card. If the user says no or the total value is
 * equal to or greater than 21 then the blackjack function is
 * finished and the total value is returned to the main function.
 *
 * Note that any user response other than 'y' or 'Y' will be treated
 * as no.
 *
 * Return Value: the result of the blackjack game
 */
int blackjack()
{
    char response = 'y';	// variable to store the user input
    int newCard = 0;		// store the value of the new card
    int numCards = 0;		// number of cards
    int total = 0;			// sum value of all dealt cards

    srand(time(NULL));		// initialize the random seed

    // get the first card
    numCards++;
    newCard = new_card(numCards);
    total += newCard;

    // get the second card
    numCards++;
    newCard = new_card(numCards);
    total += newCard;

    cout << "Total:\t" << total << endl;

    while ((total < nonBustedMaxValue) && (response == 'y' || response == 'Y'))
    {
        cout << "Would you like to have another card? (y/n):";
        cin >> response;

        if (response == 'y' || response == 'Y')
        {
            numCards++;
            newCard = new_card(numCards);
            total += newCard;

            cout << "Total:\t" << total << endl;
        }
    }

    return total;
}












/*
 * The main() function allows a player to repeat the game over and
 * over again until she decides to stop. First the user goes
 * through the do-while loop and calls on the blackjack() function.
 * The result is returned and if the result is equal to 21, then
 * the user is congratulated and wins. If the returned result is
 * greater than 21 then the user is busted. If the returned result
 * is less than 21 the user's score is printed on the screen.
 * After the post-game analysis the user is asked again whether
 * she would like to play again. If the answer is yes the do loop
 * repeats itself and the blackjack() function is called. If the
 * answer is no the whole program is terminated.
 *
 * Note that any user response other than 'y' or 'Y' will be treated
 * as no.
 *
 * Return Value: always returns 0
 */
int main()
{
    char response = 'n';	// variable to store the user input
    int result = 0;			// result of the blackjack game

    // since it has to play at least once, the do-while loop is better here
    do
    {

        result = blackjack();
        if (result == nonBustedMaxValue)
        {
            cout << "Congratulations, you win!" << endl;
        }
        else if (result > nonBustedMaxValue)
        {
            cout << "Bust!" << endl;
        }
        else
        {
            cout << "Your score is " << result << "." << endl;
        }
        cout << endl << "Thanks for playing blackjack. Would you like to play again? (y/n):";
        cin >> response;
    }
    while (response == 'y' || response == 'Y');

	return 0;
}












/*
 * No. 1 card:	1
 * No. 2 card:	4
 * Total:	5
 * Would you like to have another card? (y/n):y
 * No. 3 card:	6
 * Total:	11
 * Would you like to have another card? (y/n):y
 * No. 4 card:	8
 * Total:	19
 * Would you like to have another card? (y/n):y
 * No. 5 card:	6
 * Total:	25
 * Bust!
 *
 * Thanks for playing blackjack. Would you like to play again? (y/n):y
 * No. 1 card:	8
 * No. 2 card:	3
 * Total:	11
 * Would you like to have another card? (y/n):y
 * No. 3 card:	7
 * Total:	18
 * Would you like to have another card? (y/n):n
 * Your score is 18.
 *
 * Thanks for playing blackjack. Would you like to play again? (y/n):n
 */


/* Professor Harden's feedback 1.27.2015
   Very good!


Line 37. Good use of global constants, as per Style Convention 7a. Conventionally, constants are written in all caps, e.g., CARD_MAX_VALUE.

In this course, helper functions must be prototyped, and main() must be the first function defined.

Line 141. Generally, merge these comments into the initial file comments. main() doesn’t require function comments.

Avoid comments in the function body. Style Convention 1A.
Avoid comments that an expert C++ programmer would not need. Style Convention 1B.
 */
