//Author: Gavin Limchayseng
//File Name: MergeSort.cpp
//Date: 2/21/19

#include <iostream>

using namespace std;

void merge(int *arr, int left, int middledledle, int right);
void mergeSort(int *arr, int left, int right);


int main()
{
	
	int arrSize;
	cout << "How many Numbers will be sorted in the array: ";
	cin >> arrSize;
	int* arr = new int[arrSize];

	int temp;
	cout << endl << endl << "Please input " << arrSize << " Numbers: ";
	for (int i = 0; i < arrSize; i++) {
		cin >> temp;
		arr[i] = temp;
	}

	cout << "Given Array: " << endl << "{ ";
	for (int i = 0; i < arrSize; i++)
		cout << arr[i] << " ";
	cout << "}" << endl;

	mergeSort(arr, 0, arrSize - 1);

	cout << "Sorted Array: " << endl << "{ ";
	for (int i = 0; i < arrSize; i++)
		cout << arr[i] << " ";
	cout << "}" << endl;

	delete[] arr;

	return 0;
}

void merge(int *arr, int left, int middle, int right) {
	
	//Temp Dynamic Array
	int* temp = new int[right - left + 1];

	//Variables used to count
	int x = left;
	int	y = middle + 1;
	int	z = 0;

	//traverse both arrays and sort 
	while (x <= middle && y <= right) {
		if (arr[x] <= arr[y]) {
			temp[z] = arr[x];
			z++; 
			x++;

		}
		else {
			temp[z] = arr[y];
			z++; 
			y++;
		}
	}

	//Add to left section
	while (x <= middle) {
		temp[z] = arr[x];
		z++; 
		x++;
	}

	//Add to right section 
	while (y <= right) {
		temp[z] = arr[y];
		z++; 
		y++;
	}

	//copy back to array
	for (x = left; x <= right; x++) {
		arr[x] = temp[x - left];
	}
}



void mergeSort(int *arr, int left, int right) {

	if (left < right) {
		int middle = (left + right)/2;
		mergeSort(arr, left, middle);
		mergeSort(arr, middle + 1, right);
		merge(arr, left, middle, right);
	}
}

