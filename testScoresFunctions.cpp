#include "testScoresHeader.h"

int getTestScores()
{
	ofstream testScores;
	testScores.open("testScores");

	cout << "INSTRUCTIONS: Input as many test scores as you'd like.\nWhen you're finished simply input \"-1\""
	     << " and the program will process the numbers." << endl << endl;

	double userInput = 0;
	int count = 0;

	while (userInput != -1)
	{
		cout << "Please enter test score " << count + 1 << ": " << flush;

		cin >> userInput;

		if (userInput < -1)
		{
			cout << "INVALID INPUT. Please enter a positive number or \"-1\"." << endl;

		} else if (userInput != -1)
		{
			testScores << userInput << endl;
			count++;

		} else if (userInput == -1)
		{
			testScores.close();
			return count;

		}
	}
}
void initializeAndSort(double* testArrayIn, const int TEST_ARRAY_SIZE_IN)
{
	ifstream testFile;
	testFile.open("testScores");

	int count = 0;

	while (testFile >> *(testArrayIn + count))
	{
		count++;
	}
	testFile.close();

	bool sorting;

	do
	{
		sorting = false;

		for (int k = 0; k < TEST_ARRAY_SIZE_IN - 1; k++)
		{
			if (*(testArrayIn + k) > *(testArrayIn + k + 1))
			{
				double temp = *(testArrayIn + k);
				*(testArrayIn + k) = *(testArrayIn + k + 1);
				*(testArrayIn + k + 1) = temp;

				sorting = true;
			}
		}
	} while (sorting);
}
void displayArray(const double* TEST_ARRAY_IN, const int TEST_ARRAY_SIZE_IN)
{
	for (int k = 0; k < TEST_ARRAY_SIZE_IN; k++)
	{
		cout << "Test score " << k + 1 << ": " << *(TEST_ARRAY_IN + k) << endl;
	}
}
double displayAverage(const double* TEST_ARRAY_IN, const int TEST_ARRAY_SIZE_IN)
{
	double sum = 0;

	for (int k = 0; k < TEST_ARRAY_SIZE_IN; k++)
	{
		sum += *(TEST_ARRAY_IN + k);
	}

	double average = static_cast<double>(sum) / TEST_ARRAY_SIZE_IN;

	return average;
}
bool wantToExit()
{
	bool validInput = false;
	bool wantsExit = false;

	char userInput;

	do
	{
		cout << "Would you like to exit? (y/n): " << flush;
		cin >> userInput;

		switch(userInput)
		{
		  case 'y':
		  case 'Y': cout << "Exiting..." << endl;
				    validInput = true;
				    wantsExit = true;
				    break;
		  case 'n':
		  case 'N': cout << "Continuing..." << endl << endl;
				    validInput = true;
				    break;

		  default: cin.ignore(100, '\n');
			       cin.clear();
				   cout << "INVALID INPUT." << endl;
				   break;
		}
	} while (!validInput);

	return wantsExit;
}
