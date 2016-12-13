/*
 * Name: 	Jeffrey Qiu
 * Class: 	CS110B
 * Date: 	2/14/2015
 * Instructor:	Professor Harden
 * File name: 	a5.cpp
 * Description:
 * This program will record high-scores for a made up game. The program will
 * prompt the user to enter names for five different players, and one score
 * for each player. Each score will be stored in memory, and printed back
 * out by score from highest to lowest.
 */





#include <iostream>
#include <stdlib.h>
#include <string.h>

using namespace std;






/*
 * Constants
 */
const int NUM_OF_RECORDS = 5;	// maximum number of records
const int MAX = 10000;		// assume this is the highest score
const int MIN = 0;		// assume this is the lowest score










/*
 * function prototypes
 */
void initializeArrays(string *, int *, const int);
void sortData(string [], int [], const int);
void displayData(const string [], const int [], const int);












/*
 * Play game to read NUM_OF_RECORDS name and score pairs, 
 * sort the scores from the highest to the lowest value,
 * and then print out the scorer's name and score pair
 * in the sorted order.
 */
int main()
{
	string name[NUM_OF_RECORDS];
	int score[NUM_OF_RECORDS];

	initializeArrays(name, score, NUM_OF_RECORDS);
	sortData(name, score, NUM_OF_RECORDS);
	displayData(name, score, NUM_OF_RECORDS);

	return 0;
}












/*
 * Read NUM_OF_RECORDS of name and score pairs into name and score arrays, respectively.
 * The values in the two arrays will be returned to the caller.
 * 
 * Input parameters: name string array and score int array, and the size of the array
 * Output parameters: name string array and score int array
 */
void initializeArrays(string * name, int * score, const int size)
{
	cout << "Please enter name and score for " << NUM_OF_RECORDS << " game players." << endl;

	for (int i = 0; i < NUM_OF_RECORDS; i++)
	{
		cout << "Enter the name for score #" << i+1 << ": ";
		cin >> name[i];

		do
		{
			string input;

			cout << "Enter the score for score #" << i+1 << ": ";
			cin >> input;
			score[i] = atoi(input.c_str());

			if ((score[i] < MIN) || (score[i] > MAX))
			{
				cout << endl << "Score must be within [" << MIN << ", " << MAX << "]. ";
				cout << "Please enter the score again." << endl;
			}
		} while ((score[i] < MIN) || (score[i] > MAX));

		cout << endl;
	}
}












/*
 * Sort the score by using selection sort algorithm from the largest to the smallest value
 * and place the corresponding name in the right place in the name array.
 *
 * Input parameter: name array, score array, size of the array
 * Output parameter: name array (reordered based on sorted score), score array (sorted)
 */
void sortData(string name[], int score[], const int size)
{
	for (int i = 0; i < NUM_OF_RECORDS - 1; i++)
	{
		int largest = i;

		for (int j = i+1; j < NUM_OF_RECORDS; j++)
			if (score[largest] < score[j])
				largest = j;
		
		if (largest != i)
		{
			int tempScore = score[i];
			string tempName = name[i];

			score[i] = score[largest];
			name[i] = name[largest]; 

			score[largest] = tempScore;
			name[largest] = tempName;
		}
	}
}












/*
 * Print the names and scores based on sorted scores from the highest to the lowest value.
 * 
 * Input parameters: name string array and score int array, size of the array
 */
void displayData(const string name[], const int score[], const int size)
{
	cout << endl << "Top scorers : " << endl;

	for (int i = 0; i < NUM_OF_RECORDS; i++)
	{
		cout << name[i] << " : " << score[i] << endl;
	}

	cout << endl;
}












/*

Please enter name and score for 5 game players.
Enter the name for score #1: Bob
Enter the score for score #1: 5000

Enter the name for score #2: Jeffrey
Enter the score for score #2: 9898

Enter the name for score #3: Simon
Enter the score for score #3: -100

Score must be within [0, 10000]. Please enter the score again.
Enter the score for score #3: 0

Enter the name for score #4: Mary
Enter the score for score #4: 7878

Enter the name for score #5: Nancy
Enter the score for score #5: 909


Top scorers :
Jeffrey : 9898
Mary : 7878
Bob : 5000
Nancy : 909
Simon : 0

*/


