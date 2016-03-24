#include "testScoresHeader.h"

int main()
{
	do
	{
		int testArraySize = getTestScores();
		double* testArray = new double[testArraySize];

		initializeAndSort(testArray, testArraySize);
		cout << endl;
		displayArray(testArray, testArraySize);

		cout << endl << "The average test score is: " << displayAverage(testArray, testArraySize) << endl << endl;

		delete [] testArray;

	} while (!wantToExit());

	return 0;
}
