/*
 * Name:	Jeffrey Qiu
 * Class:	CS110B
 * Date:	03/14/2015
 * Instructor:	Professor Harden
 * File Name: a9.cpp
 * Description: This program will record high-scores for a made up game. The program will
 * prompt the user to enter names for five different players, and one score
 * for each player. Each name and score pair will be stored in a struct named highscore, and printed back
 * out by score from highest to lowest.
 */





#include <iostream>
#include <stdlib.h>
#include <string.h>

using namespace std;












/*
 * Global Variables and Constants
 */
const int NUM_OF_RECORDS = 5;	// maximum number of records
const int STRING_SIZE = 25;	// max size for char array to hold 24 characters












/*
 * struct definition
 */
struct HighScore {
	char name[STRING_SIZE];
	int score;
};










/*
 * function prototypes
 */
void readRecords(HighScore [], const int);
void selectionSort(HighScore [], const int);
void printRecords(const HighScore [], const int);












/*
 * Play game to read NUM_OF_RECORDS name and score pairs, 
 * sort the scores from the highest to the lowest value,
 * and then print out the scorer's name and score pair
 * in the sorted order.
 */
int main()
{

	HighScore *hScorePtr = new HighScore [NUM_OF_RECORDS];

	readRecords(hScorePtr, NUM_OF_RECORDS);
	selectionSort(hScorePtr, NUM_OF_RECORDS);
	printRecords(hScorePtr, NUM_OF_RECORDS);

	delete [] hScorePtr;

	return 0;
}












/*
 * Read NUM_OF_RECORDS of name and score pairs into name and score arrays respectively. 
 * The values in the two arrays will be returned to the caller.
 * 
 * Input parameters: HighScore array, and the size of the array
 * Output parameters: HighScore array
 */
void readRecords(HighScore hScore[], const int size)
{
	cout << "Please enter name and score for " << size << " game players." << endl;

	for (int i = 0; i < size; i++)
	{
		cout << "Enter the name for score #" << i+1 << ": ";
		cin >> hScore[i].name;

		string input;
		cout << "Enter the score for score #" << i+1 << ": ";
		cin >> input;
		hScore[i].score = atoi(input.c_str());

		cout << endl;
	}
}












/*
 * Sort the score from the largest to the smallest value and place the corresponding
 * name in the right place in the name array.
 *
 * Input parameter: HighScore array, size of the array
 * Output parameter: HighScore array (sorted by the score field)
 */
void selectionSort(HighScore hScore[], const int size)
{
	for (int i = 0; i < size - 1; i++)
	{
		int largest = i;

		for (int j = i+1; j < size; j++)
			if (hScore[largest].score < hScore[j].score)
				largest = j;
		
		if (largest != i)
		{
			int tempScore = hScore[i].score;
			char tempName[STRING_SIZE];
			strcpy(tempName, hScore[i].name);

			hScore[i].score = hScore[largest].score;
			strcpy(hScore[i].name, hScore[largest].name); 

			hScore[largest].score = tempScore;
			strcpy(hScore[largest].name, tempName);
		}
	}
}












/*
 * Print the names and scores based on sorted scores from the highest to the lowest value.
 * 
 * Input parameters: HighScore array, size of the array
 */
void printRecords(const HighScore hScore[], const int size)
{
	cout << endl << "Top scorers : " << endl;

	for (int i = 0; i < size; i++)
	{
		cout << hScore[i].name << " : " << hScore[i].score << endl;
	}

	cout << endl;
}












/*

Please enter name and score for 5 game players.
Enter the name for score #1: Josh
Enter the score for score #1: 554

Enter the name for score #2: John
Enter the score for score #2: 852

Enter the name for score #3: Roman
Enter the score for score #3: 987

Enter the name for score #4: Steve
Enter the score for score #4: 875

Enter the name for score #5: Ryan
Enter the score for score #5: 8824


Top scorers :
Ryan : 8824
Roman : 987
Steve : 875
John : 852
Josh : 554

*/


