/* Jeffrey Qiu
 * This small program asks the user how many asterisks it should print out. The use then responds with a number, and the
 * program prints out the asterisks. Finally the program asks the user whether it should start over, and repeats as many
 * times as the user would like.
 */

#include <iostream>
using namespace std;

int main() {
	int numAsterisks;
	char response;

	cout << "Would you like to print some asterisks (Y/N)? ";
	cin >> response;

	while (response != 'N') {
		cout << "How many asterisks would you like to print? ";
		cin >> numAsterisks;

		for (int i = 0; i < numAsterisks; i++) {
			cout << "*";
		}
		cout << endl;

		cout << "Would you like me to print some asterisks (Y/N)? ";
		cin >> response;
	}
}

/*Would you like to print some asterisks (Y/N)? Y
How many asterisks would you like to print? 12
************
Would you like me to print some asterisks (Y/N)? Y
How many asterisks would you like to print? 2
**
Would you like me to print some asterisks (Y/N)? Y
How many asterisks would you like to print? 1
*
Would you like me to print some asterisks (Y/N)? N
 */
