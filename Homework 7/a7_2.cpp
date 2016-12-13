/*
 * Name: 	Jeffrey Qiu
 * Class: 	CS110B
 * Date: 	2/24/2015
 * Instructor:	Professor Harden
 * File name: 	a7_2.cpp
 * Description:
 * This program will record high-scores for a made up game. The program will
 * prompt the user to enter names for five different players, and one score
 * for each player. Each score will be stored in memory, and printed back
 * out by score from highest to lowest. However, this time the program will
 * use dynamic memory allocation to create the names and scores arrays.
 */




#include <iostream>
#include <stdlib.h>
#include <string.h>

using namespace std;






/*
 * Global Variables and Constants
 */
const int MAX = 10000;		// assume this is the highest score
const int MIN = 0;		// assume this is the lowest score










/*
 * function prototypes
 */
void readRecords(string [], int [], const int);
//void selectionSort(string [], int [], const int);
void bubbleSort(string [], int [], const int);
void printResult(const string [], const int [], const int);












/*
 * Play game to read numOfRecords name and score pairs,
 * sort the scores from the highest to the lowest value,
 * and then print out the scorer's name and score pair
 * in the sorted order. This time we would like to try
 * bubble sort.
 */
int main()
{
	int numOfRecords = 0;

	do
	{
		cout << "How many records to be entered? (>= 2) " << endl;
		cin >> numOfRecords;
	} while (numOfRecords <= 1);

	string *name = new string[numOfRecords];
	int *score = new int[numOfRecords];

	// use bubble sort
	readRecords(name, score, numOfRecords);
	bubbleSort(name, score, numOfRecords);
	printResult(name, score, numOfRecords);

	// use selection sort
	//readRecords(name, score, numOfRecords);
	//selectionSort(name, score, numOfRecords);
	//printResult(name, score, numOfRecords);


	delete [] name;
	name = NULL;

	delete [] score;
	score = NULL;

	return 0;
}













/*
 * Read NUM_OF_RECORDS of name and score pairs into name and score arrays respectively. 
 * The values in the two arrays will be returned to the caller.
 * 
 * Input parameters: name string array and score int array, and the size of the array
 * Output parameters: name string array and score int array
 */
void readRecords(string name[], int score[], const int size)
{
	cout << "Please enter name and score for " << size << " game players." << endl;

	for (int i = 0; i < size; i++)
	{
		cout << "Enter the name for score #" << i+1 << ": ";
		cin >> name[i];

		while ((score[i] < MIN) || (score[i] > MAX))
		{
			string input;

			cout << "Enter the score for score #" << i+1 << ": ";
			cin >> input;
			score[i] = atoi(input.c_str());

			if ((score[i] < MIN) || (score[i] > MAX))
			{
				cout << endl << "Score must be within [" << MIN << ", " << MAX << "].";
				cout << "Please enter the score again." << endl;
			}
		}

		/*
		do
		{
			string input;

			cout << "Enter the score for score #" << i+1 << ": ";
			cin >> input;
			score[i] = atoi(input.c_str());

			if ((score[i] < MIN) || (score[i] > MAX))
			{
				cout << endl << "Score must be within [" << MIN << ", " << MAX << "].";
				cout << "Please enter the score again." << endl;
			}
		} while ((score[i] < MIN) || (score[i] > MAX));
		*/

		cout << endl;
	}
}












/*
 * Sort the score from the largest to the smallest value and place the corresponding
 * name in the right place in the name array.
 *
 * Input parameter: name array, score array, size of the array
 * Output parameter: name array (reordered based on sorted score), score array (sorted)
 */
/*
void selectionSort(string name[], int score[], const int size)
{
	for (int i = 0; i < size - 1; i++)
	{
		int largest = i;

		for (int j = i+1; j < size; j++)
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
*/












/*
 * Sort the score from the largest to the smallest value and place the corresponding
 * name in the right place in the name array. This sort uses bubble sort algorithm.
 *
 * Input parameter: name array, score array, size of the array
 * Output parameter: name array (reordered based on sorted score), score array (sorted)
 */
void bubbleSort(string name[], int score[], const int size)
{
	bool continueLoop = true;
	bool swap = false;
	int i = 0;

	while (continueLoop)
	{
		if (i == 0)
		{
			continueLoop = true;
		}
		else if (i == size - 1)
		{
			i = 0;
			if (!swap)
				continueLoop = false;
			else
			{
				swap = false;
				continueLoop = true;
			}
		}

		if (continueLoop)
		{
			if (score[i] < score[i + 1])
			{
				int tempScore = score[i];
				string tempName = name[i];

				score[i] = score[i + 1];
				name[i] = name[i + 1]; 

				score[i + 1] = tempScore;
				name[i + 1] = tempName;

				swap = true;
			}
			
			i++;
		}
	}
}












/*
 * Print the names and scores based on sorted scores from the highest to the lowest value.
 * 
 * Input parameters: name string array and score int array, size of the array
 */
void printResult(const string name[], const int score[], const int size)
{
	cout << endl << "Top scorers : " << endl;

	for (int i = 0; i < size; i++)
	{
		cout << name[i] << " : " << score[i] << endl;
	}

	cout << endl;
}






/*

How many records to be entered? (>= 2)
2
Please enter name and score for 2 game players.
Enter the name for score #1: Kevin
Enter the score for score #1: 52

Enter the name for score #2: Andrew
Enter the score for score #2: 668


Top scorers :
Andrew : 668
Kevin : 52

 */
