#include <iostream>
#include "sort.h"


const size_t LENGTH = 10;
using namespace std;
using namespace sort;

void sortTest(){
	double arr[LENGTH] = {88.3, 67.1, 94.034, 90.121, 4.333, 32.001, 66.231, 99.999, 203.12, 55.666};
//	int arr[LENGTH] = {88, 67, 94, 90, 4, 32, 66, 99, 203, 55};
	printArr(arr, LENGTH);
	cout << "----------------------SORTING------------------------\n";

	cout << "SELECTION SORT\n";
	selSort(arr, LENGTH, ASC);

//	cout << "INSERTION SORT\n";
//	insertionSort(arr, LENGTH, DSC);
//
//	cout << "QUICKSORT\n";
//	quickSort(arr, LENGTH, DSC);

//	cout << "BUBBLE SORT\n";
//	bubbleSort(arr, LENGTH, DSC);


//	cout << "BINARY SORT\n";
//	binarySort(arr, LENGTH, ASC);

	printArr(arr, LENGTH);
}

int main()
{
	sortTest();
  return 0;
}
