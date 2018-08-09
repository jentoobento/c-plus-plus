#include <iostream>
using namespace std;

int main(){
	const int SIZE = 20;
	cout << "Enter 20 numbers and I will sort them!\n";
	for (int x = 0; x < SIZE; x++){
		cout << "Number " << x + 1 << ": ";
		cin >> array1[x];
	}
  for (int x = 0; x < SIZE; x++){
		array2[x] = array1[x];
	}

	//Bubble sort
	bool swapFound;
	int tempnum = 0;
	int bubbleCount = 0;
	do{
		swapFound = false;
		for (int x = 0; x < (SIZE - 1); x++){
			if (array1[x] > array1[x + 1]){
				bubbleCount++;
				tempnum = array1[x];
				array1[x] = array1[x + 1];
				array1[x + 1] = tempnum;
				swapFound = true;
			}
		}
	} while (swapFound);

	//selection sort
	int
		startingNum = 0,
		minNum = 0,
		minValue = 0,
		selectionCount = 0;

	for (startingNum = 0; startingNum < (SIZE - 1); startingNum++){
		minNum = startingNum;
		minValue = array2[startingNum];
		for (int x = (startingNum + 1); x < SIZE; x++){
			if (array2[x] < minValue){
				selectionCount++;
				minValue = array2[x];
				minNum = x;
			}
		}
		array2[minNum] = array2[startingNum];
		array2[startingNum] = minValue;
	}
	cout << "Here are the sorted numbers:\n";
	for (int x = 0; x < SIZE; x++){
		cout << array1[x] << " ";
	}
	cout << endl;
	cout << "The Bubble Sort made " << bubbleCount << " changes.\n";
	cout << "The Selection Sort made " << selectionCount << " changes.";
	return 0;
}
