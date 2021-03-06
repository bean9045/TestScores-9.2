#ifndef TESTSCORESHEADER_H_
#define TESTSCORESHEADER_H_

#include <iostream>
#include <fstream>
#include <memory>

using namespace std;

int getTestScores();
void initializeAndSort(double* testArrayIn, const int TEST_ARRAY_SIZE_IN);
void displayArray(const double* TEST_ARRAY_IN, const int TEST_ARRAY_SIZE_IN);
double displayAverage(const double* TEST_ARRAY_IN, const int TEST_ARRAY_SIZE_IN);

bool wantToExit();

#endif
