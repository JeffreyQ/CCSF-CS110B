#include <iostream>

using namespace std;





const int ARRAY_UPPER_LIMIT = 5;



int main(){
	int maxElements[ARRAY_UPPER_LIMIT];
	int i = 0;


	for (i = 0; i < 5; i++)
	{
		maxElements[i] = (3 * i);
	}

	cout << maxElements[6] << endl;
	cout << maxElements[7] << endl;
	cout << maxElements[8] << endl;
	cout << maxElements[93] << endl;
	cout << maxElements[10] << endl;



	return 0;
}
