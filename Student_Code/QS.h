#pragma once

#include <iostream>
#include <sstream>
#include <string>

#include "QSInterface.h"

using namespace std;

class QS : public QSInterface
{

private:

	int* intArray = NULL;

	int size = 0;
	int capacity = 0;
	bool valid = false;


public:

	QS();
	~QS();

	void helper(int left, int right);
	void sortAll(); //part 4; test 6
	int medianOfThree(int left, int right); //part 2; test 4
	int partition(int left, int right, int pivotIndex); //part 3; test 5
	string getArray(); //part 1; test 1-3
	int getSize(); //part 1; test 1-3
	void addToArray(int value); //part 1; test 1-3
	bool createArray(int capacity); //part 1; test 1-3
	void clear(); //part 1; test 1-3


};
