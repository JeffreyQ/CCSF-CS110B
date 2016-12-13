#include <iostream>
using namespace std;

int main() {
		int numAsterisks;
		char response;

		cout << "Would you like me to print asterisks (Y/N)? ";
		cin >> response;
		while (response != 'N') {
			cout << "How many asterisks? ";
			cin >> numAsterisks;

			for (int i = 0; i < numAsterisks; i++) {
				cout << "*";
			}
			cout << endl;

			cout << "Would you like me to print asterisks (Y/N)? ";
			cin >> response;
		}

		return 0;
}
