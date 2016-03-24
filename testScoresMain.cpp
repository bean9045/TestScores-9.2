#include "testScoresHeader.h"

int main()
{
	do
	{
		const int TEST_ARRAY_SIZE = getTestScores();
		double* testArray = new double[TEST_ARRAY_SIZE];

		initializeAndSort(testArray, TEST_ARRAY_SIZE);
		cout << endl;
		displayArray(testArray, TEST_ARRAY_SIZE);

		cout << endl << "The average test score is: " << displayAverage(testArray, TEST_ARRAY_SIZE) << endl << endl;

		delete [] testArray;

	} while (!wantToExit());

	return 0;
}
