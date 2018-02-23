#include "QS.h"

QS::QS()
{
	int* intArray = NULL;
	int size = 0;
	int capacity = 0;
	bool valid=false;
}

QS::~QS()
{
	clear();
}



//probably create a helper() function;

void QS::helper(int left, int right){

	//base cases
	if(left == right) { return; }

	if(left +1 == right || left + 2 == right){
		medianOfThree(left,right);
		return;
	}

	//else sort recursively
	else{
		int pivot = medianOfThree(left,right);
		pivot = partition(left,right,pivot);
		helper(left,pivot-1);
		helper(pivot+1,right);
	}
}


void QS::sortAll()
{
	helper(0,size-1);
}





int QS::medianOfThree(int left, int right)
{

	if(intArray == NULL) {return -1; }
	if(left < 0 || left >= right || right > capacity -1){
		return -1;
	}

	int pivot = (left + right) / 2;

	if(intArray[left] > intArray[pivot]){
		int temp = intArray[left];
		intArray[left] = intArray[pivot];
		intArray[pivot] = temp;
	}

	if(intArray[left] > intArray[right]){
		int temp = intArray[left];
		intArray[left] = intArray[right];
		intArray[right] = temp;
	}

	if(intArray[pivot] > intArray[right]){
		int temp = intArray[pivot];
		intArray[pivot] = intArray[right];
		intArray[right] = temp;
	}

	return pivot;


}





int QS::partition(int left, int right, int pivotIndex)
{


	if(intArray == NULL) {return -1; }
	if(left < 0 || left >= right || right > size -1){ return -1; }
	if(pivotIndex >= right || pivotIndex <= left){ return -1; }


	//switch values of pivotIndex and left
	int temp = intArray[pivotIndex];
	intArray[pivotIndex] = intArray[left];
	intArray[left] = temp;

	//walk through the array
	int x = left +1;
	int o = right -1;
	while(x < o){
		while(intArray[x] <= intArray[left] && x <= right) {
			x++;
		}
		while(intArray[o] > intArray[left] && o >= left){
			o--;
		}
		if(o > x){
			int temp = intArray[o];
			intArray[o] = intArray[x];
			intArray[x] = temp;
		}
	}

	//switch values of left and o
	temp = intArray[o];
	intArray[o] = intArray[left];
	intArray[left] = temp;

	return o;

}











string QS::getArray()//////////done
{
	stringstream ss;
	for (int i = 0; i < size; i++){
		ss << intArray[i];
		if (i != size-1){
			ss << ",";
		}
	}

	if(intArray == NULL) { return ""; }

	return ss.str();


}







int QS::getSize()///easy
{
	return size;
}






void QS::addToArray(int value)/////////////done
{
	if(intArray == NULL) { return; }

	if(size < capacity){
		intArray[size] = value;
		size++;
	}
}

bool QS::createArray(int capacity)/////////////////DONE
{
	if(capacity < 0) { return false; }

	if(intArray != NULL) { clear(); }

	if(intArray == NULL){
		intArray = new int[capacity];
		this->capacity = capacity;
		valid = true;
	}

	return true;
}





void QS::clear()/////////DONE
{
	if(intArray == NULL) { return; }

	delete [] intArray;
	size = 0;
	capacity = 0;
	valid = false;
	intArray = NULL;
}




/* HELP SESSION NOTES
 * keep track of size or count or whatever.
 * size is different from capacity
 * median of 3 & partition is what you use in your sort all function
 *
 * passing in the index not the value for the median of three of list so that the function can be used on any portion of the list that you are working on
 * pivot: l/r divided by 2
 * sort left right and pivot; sort the actual values
 * median of three: return pivot index, not the actual value
 *
 * partition method
 * being passed in three vlaues: l, r, p; the indexes, not the values
 * example: partition (0,6,3)
 * first: switch values of pivot and left
 * while index of _ is greaterthan or lessthen _, then increment;
 * if/while i and j swap or orverlap, (look at indexes) then j saw with pivot
 * return the index of j
 *
 * sort all
 * calls the median of three function and the partition function recursively
 * create a helper function?
 * sortall() { helper(L, R, ){ base cases; do something; } };
 *
 * create array dynamically
 * create an int pointer call it array or whatever
 * private datatmembers something tsomething
 * array pointer example: arr = new int[capacity];
 * ^this will dynamically allocate
 * datamemeber: int* arr;
 * array = new int [10];
 * points to the beginning of the array;
 * new is setting aside the memory space for it
 *
 * clear function
 * delete[]arr
 * destructor calls clear function
 *
 *
 * */









