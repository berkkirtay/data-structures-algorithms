/*This code was written for the project of Analysis of Algorithms class.*/
#include <iostream>
#include <chrono>
#include <vector>
#include <random>
#include <memory>
#include <string.h>

enum testType{
	RANDOM = 1,
	REVERSED = 2,
	SORTED = 3,
	HIGH_FREQ = 4,
};

class SortAnalysis
{
private:
	int* generatedNumbers = nullptr;
	unsigned long limit = 0;
	unsigned long int numberOfComparisons = 0;
	unsigned long int totalMemoryAccesses = 0;
	unsigned long int spaceComplexity = 0;
	float freq = 0.1; // 10% of the inputs have the same value
	// We are using std::chrono library to calculate the time complexity
	std::chrono::duration<double> duration = std::chrono::seconds(0);
	std::string sortingType;
	int testCount;
	int maxInt;
	std::chrono::duration<double> finalBestCase = std::chrono::seconds(100000000);
	std::chrono::duration<double> finalWorstCase = std::chrono::seconds(0);
public:
	// testCount: 	Number of different test arrays.
	// limit: 		size of each test array.
	SortAnalysis(int testCount, int limit) {
		srand(time(NULL));
		this->testCount = testCount;
		this->limit = limit;
		this->maxInt = 10000;
		this->generatedNumbers = new int[limit];
		std::cout << "Test count: " << testCount << ", Array Size: " << limit <<  " \n" << std::endl;
	}
	~SortAnalysis() {
		delete[] this->generatedNumbers;
	}
	void test(testType arrayGenType) {
		if (arrayGenType == RANDOM){
			std::cout << "\n\nArray generation: RANDOM\n" << std::endl;
		}
		else if (arrayGenType == REVERSED){
			std::cout << "\n\nArray generation: REVERSED\n" << std::endl;
		}
		else if (arrayGenType == SORTED) {
			std::cout << "\n\nArray generation: SORTED\n" << std::endl;
		}
		else if (arrayGenType == HIGH_FREQ){
			std::cout << "\n\nArray generation: HIGH-FREQ\n" << std::endl;
		}
		
		int bestCaseComparisons;
		for (int i = 0; i < 7; i++) {
			// We calculate average, best and worst cases for each sorting algorithm.
			std::chrono::duration<double> averageCase = std::chrono::seconds(0);
			std::chrono::duration<double> bestCase = std::chrono::seconds(100000000);
			std::chrono::duration<double> worstCase = std::chrono::seconds(0);

			int validCounter = 0;
			unsigned long int totalComparisonCount = 0;

			// We test each sorting algorithm by testCount times.
			for (int j = 0; j < testCount; j++) {
				sortTable(i, arrayGenType);
				totalComparisonCount += numberOfComparisons;
				if (isValid()) validCounter++;
				if (duration < bestCase) {
					bestCase = duration;
				}
				if (duration > worstCase) {
					worstCase = duration;
				}
				if (duration < finalBestCase) {
					finalBestCase = duration;
				}
				if (duration < finalWorstCase) {
					finalWorstCase = duration;
				}
				averageCase += duration;
			}
			averageCase /= testCount;
			// Experiment Outputs
			std::cout << "--------" << sortingType << "--------\n"  	<<
			"Average Duration: " << (double)averageCase.count() << " seconds, "	<<
		        "Worst Case: " << (double)worstCase.count() << " seconds, " 		<<
			"Best Case: " << (double)bestCase.count() << std::endl;
			std::cout << "Average number of comparisons: " << totalComparisonCount / testCount << std::endl;
			std::cout << "Average Total Memory Accesses: " << totalMemoryAccesses / testCount << std::endl;
			std::cout << "Average Space Complexity: " << (double)spaceComplexity / testCount + 1 << std::endl;
			std::cout << validCounter << "/" << testCount << " Sorted correctly\n" << std::endl;
		}
	}

	// This function validates if the array is sorted correctly.
	bool isValid() {
		for (int i = 0; i < limit-1; i++) {
			if (generatedNumbers[i] > generatedNumbers[i+1])
				return false;
		}
		return true;
	}

	// In this function we reset all the parameters and create a random array again for the next sorting experiment.
	// We also calculate the actual time in this function by "duration = timeEnd - timeStart;"
	void sortTable(int type, testType arrayGenType) {
		reset(arrayGenType);
		std::chrono::time_point<std::chrono::system_clock> timeStart = std::chrono::system_clock::now();
		switch (type) {
		case 0:
			sortingType = "Insertion Sort";
			insertionSort();
			break;
		case 1:
			sortingType = "Binary Insertion Sort";
			binaryInsertionSort();
			break;
		case 2:
			sortingType = "Merge Sort";
			startMergeSort();
			break;
		case 3:
			sortingType = "Quick Sort with the first element pivot selection";
			startQuickSort(1);
			break;
		case 4:
			sortingType = "Quick Sort with median-of-three pivot selection";
			startQuickSort(2);
			break;
		case 5:
			sortingType = "Heap Sort";
			heapSort();
			break;
		case 6:
			sortingType = "Counting Sort";
			countingSort();
			break;
		}
		std::chrono::time_point<std::chrono::system_clock> timeEnd = std::chrono::system_clock::now();
		duration = timeEnd - timeStart;
	}

	// Number generators

	/*
		Generates array randomly, but still an element inside of the array
		can not be higher than 10000 or lower than 0.
		ex array: {5462, 3219, 12, 0, ..., 1341, 8399, 9999}
	*/
	void randomNumberGenerator() {
		for (int i = 0; i < limit; i++) {
			generatedNumbers[i] = rand() % maxInt;
		}
	}

	/*
		Genearates a reverse sorted array.
		Start element is always 10000 and ending will be near zero
		and this function guarantees that every proceeding element
		will be smaller or equal to the preceding element.
		If the array is too large in size, there will be elements
		with the same value.
		ex array: {10000, 7500, 5000, 2500, 0}
	*/
	void reversedNumberGenerator(){
		float ratio = ((float)maxInt) / limit;
		for (int i = 0; i < limit; i++) {
			generatedNumbers[i] = (int)((float)maxInt - i * ratio);
		}
	}

	/*
		Genearates a sorted array.
		Start element is always 0 and ending will be near 10000
		and this function guarantees that every preceding element
		will be bigger or equal to the proceeding element.
		If the array is too large in size, there will be elements
		with the same value.
		ex array: {0, 2500, 5000, 7500, 10000}
	*/
	void inorderNumberGenerator() {
		float ratio = ((float)maxInt) / limit;
		for (int i = 0; i < limit; i++) {
			generatedNumbers[i] = (int)((float)i * ratio);
		}
	}

	/*
		Generates the array according to given freq class variable.
		In our case freq value is 0.1 and that means 10% of the
		array variables are the same (there are 10 distinct elements,
		1/freq distinct elements).
		But still we are working with integers and integers in some cases
		will not give exact values. For ex is the size of the array is 89
		there will be 11 distinct element in the first part and 1 more added
		in order to fill the array correctly.
		ex array: {6, 6, 2514, 2514, 4698, 4698, ..., 1004, 1004}

	*/
	void highFreqInputGenerator(){
		int n1 = freq * limit;
		int n2 = limit / n1;
		int last = (n2 - 1) * n1;
		for (int i=0; i<n2; i++){
			int n = rand() % maxInt;
			for (int j=0; j<n1; j++){
				generatedNumbers[j + i * n1] = n;
			}
		}
		int lastRandom = rand() % maxInt;
		for (int i=limit-1; i>last; i--){
			generatedNumbers[i] = lastRandom;
		}
	}

	void reset(testType arrayGenType) {
		numberOfComparisons = 0;
		totalMemoryAccesses = 0;
		spaceComplexity = 0;
		if (arrayGenType == RANDOM){
			randomNumberGenerator();
		}
		else if (arrayGenType == REVERSED){
			reversedNumberGenerator();
		}
		else if (arrayGenType == SORTED) {
			inorderNumberGenerator();
		}
		else if (arrayGenType == HIGH_FREQ){
			highFreqInputGenerator();
		}
	}

	void swap(int i, int j, int* arr) {
		int temp = arr[i];
		arr[i] = arr[j];
		arr[j] = temp;
	}

	// Sorting Algorithms

	void insertionSort() {
		for (int i = 1; i < limit; i++) {
			totalMemoryAccesses++;
			int temp = generatedNumbers[i];
			int j = i - 1;
			while (j >= 0) {
				numberOfComparisons++;
				totalMemoryAccesses++;
				if (temp < generatedNumbers[j]) {
					generatedNumbers[j + 1] = generatedNumbers[j];
					j--;
					totalMemoryAccesses++;
				}
				else {
					break;
				}
			}
			generatedNumbers[j + 1] = temp;
		}
	}
	int binarySearch(int l, int h, int temp) {
		numberOfComparisons++;
		totalMemoryAccesses++;
		int m = (l + h) / 2;
		if (temp == generatedNumbers[m]) {
			return m + 1;
		}
		if (h <= l) {
			if (temp > generatedNumbers[l])
				return l + 1;
			else
				return l;
		}
		if (temp < generatedNumbers[m]) {
			return binarySearch(l, m - 1, temp);
		}
		else{
			return binarySearch(m + 1, h, temp);
		}
	}
	void binaryInsertionSort() {
		for (int i = 1; i < limit; i++) {
			totalMemoryAccesses++;
			int temp = generatedNumbers[i];
			int j = i - 1;
			int index = binarySearch(0, j, temp);
			while (j >= index) {
				totalMemoryAccesses++;
				generatedNumbers[j + 1] = generatedNumbers[j];
				j--;
			}
			generatedNumbers[j + 1] = temp;
		}
	}
	void mergeSort(int* arr, int size) {
		int oddsize = size / 2;
		if (size % 2 == 1) {
			oddsize = size / 2 + 1;
		}
		int arr1[oddsize];
		int arr2[size - oddsize];
		int j = 0;
		while (j < oddsize) {
			spaceComplexity++;
			totalMemoryAccesses++;
			arr1[j] = arr[j++];
		}
		while (j < size) {
			spaceComplexity++;
			totalMemoryAccesses++;
			arr2[j - oddsize] = arr[j++];
		}
		if (size >= 2) {
			mergeSort(arr1, oddsize);
			mergeSort(arr2, size - oddsize);
		}
		mergeArrays(arr1, arr2, arr, oddsize, size - oddsize);
		// delete[] arr1;
		// delete[] arr2;
	}
	void mergeArrays(int* arr1, int* arr2, int* arr, int size1, int size2) {
		int i = 0, j = 0;
		while (i < size1 && j < size2) {
			numberOfComparisons++;
			totalMemoryAccesses += 2;
			if (arr1[i] < arr2[j]) {
				arr[i + j] = arr1[i];
				i++;
			}
			else {
				arr[i + j] = arr2[j];
				j++;
			}
		}
		while (i < size1) {
			totalMemoryAccesses++;
			arr[i + j] = arr1[i];
			i++;
		}
		while (j < size2) {
			totalMemoryAccesses++;
			arr[i + j] = arr2[j];
			j++;
		}
	}
	void startMergeSort() {
		mergeSort(generatedNumbers, limit);
	}
	void quickSort(int l, int h) {
		if (l < h) {
			int j = partition(l, h);
			quickSort(l, j);
			quickSort(j + 1, h);
		}
	}
	int partition(int l, int h) {
		spaceComplexity++;
		int pivot = generatedNumbers[l];
		int i = l;
		int j = h;
		while (i < j) {
			do {
				i++;
				numberOfComparisons++;
				totalMemoryAccesses++;
			} while (generatedNumbers[i] <= pivot);
			do {
				j--;
				numberOfComparisons++;
				totalMemoryAccesses++;
			} while (generatedNumbers[j] > pivot);

			if (i < j) {
				swap(i, j, generatedNumbers);
			}
		}
		swap(l, j, generatedNumbers);
		return j;
	}
	void startQuickSort(int type) {
		if (type == 2) {
			int m[3];
			m[0] = generatedNumbers[0];
			m[1] = generatedNumbers[limit / 2 - 1];
			m[2] = generatedNumbers[limit - 1];
			for (int i = 0; i < 2; i++){
				for (int j = i; j < 3; j++){
					numberOfComparisons++;
					if (m[i] > m[j]) {
						swap(i, j, m);
					}
				}
			}
			generatedNumbers[0] = m[1];
			generatedNumbers[1] = m[0];
			generatedNumbers[2] = m[2];
		}
		quickSort(0, limit);
	}
	void heapSort() {
		for (int i = limit / 2 - 1; i >= 0; i--)
			constructHeap(generatedNumbers, limit, i);
	
		for (int i = limit - 1; i > 0; i--) {
			swap(0, i, generatedNumbers);
			constructHeap(generatedNumbers, i, 0);
		}
	}
	void constructHeap(int* arr, int n, int i) {
		int largest = i;
		int left = 2 * i + 1;
		int right = 2 * i + 2;
	
		if (left < n && arr[left] > arr[largest])
			largest = left;
	
		if (right < n && arr[right] > arr[largest])
			largest = right;

		numberOfComparisons += 2;
		totalMemoryAccesses += 2;

		if (largest != i) {
			swap(i, largest, arr);
			constructHeap(arr, n, largest);
		}
	}
	void countingSort() {
		int maxElement = maxInt * 10;
		int* hashArr = new int[maxElement];
		int* sortedArr = new int[limit];
		// Setting all elements of hashArr as 0.
		memset(hashArr, 0, maxElement); 
		for (int i = 0; i < limit; i++) {
			totalMemoryAccesses++;
			spaceComplexity++;
			hashArr[generatedNumbers[i]]++;
		}
		for (int i = 1; i < maxElement; i++){ 
			totalMemoryAccesses++;
			hashArr[i] += hashArr[i - 1];
		}
		for (int i = limit - 1; i >= 0; i--) {
			totalMemoryAccesses++;
			spaceComplexity++;
			sortedArr[hashArr[generatedNumbers[i]] - 1] = generatedNumbers[i];
			hashArr[generatedNumbers[i]]--;
		}
		// Assigns values back to generatedNumbers array to be able to validate it
		for (int i = 0; i < limit; i++){
			totalMemoryAccesses++;
			generatedNumbers[i] = sortedArr[i];
		}
		delete[] sortedArr;
		delete[] hashArr;
	}
};

int main() {
	// Testing part
	SortAnalysis s1(10, 10000);
	for (int i=1; i<5; i++) s1.test((testType)i);

	// These tests are commented out because of the 
	// time that takes to complete these tests.
	// Since insertion and binary insertion sorts have O(n^2) time complexity
	// they will probably take more than minutes to complete.
	// But still for our mesurements we have waited them to be completed and took the data
	// out of these tests and use it in our report.

	// SortAnalysis s2(10, 50000);
	// for (int i=1; i<5; i++) s2.test(i);

	// SortAnalysis s3(10, 100000);
	// for (int i=1; i<5; i++) s3.test(i);

	return 0;
}
