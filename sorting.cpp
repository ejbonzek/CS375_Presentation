#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <ctime>

using namespace std;

void swap(int* a, int* b){
	int temp = *a;
	*a = *b;
	*b = temp;
}

void insertionSort(int array[], int n){
	int key;
	int j;
	for(int i=1; i<n; i++){
		key=array[i];
		j=i-1;

		while(j>=0 && array[j]>key){
			array[j+1]=array[j];
			j--;
		}

		array[j+1]=key;
	}
}

void mergeSort(int array[], int left, int middle, int right){
	int num1 = middle - left + 1;
	int num2 = right - middle;
	int leftArray[num1];
	int rightArray[num2];

	for(int i=0; i<num1; i++){
		leftArray[i]=array[left+i];
	}

	for(int i=0; i<num2; i++){
		rightArray[i]=array[middle+1+i];
	}

	int i=0;
	int j=0;
	int k=left;
	while(i<num1 && j<num2){
		if(leftArray[i] <= rightArray[j]){
			array[k]=leftArray[i];
			i++;
		}
		else{
			array[k]=rightArray[j];
			j++;
		}

		k++;
	}

	while(i<num1){
		array[k]=leftArray[i];
		i++;
		k++;
	}

	while(j<num2){
		array[k]=rightArray[j];
		j++;
		k++;
	}
}

void mergeRecursion(int array[], int left, int right){
	if(left<right){
		int middle=left+(right-1)/2;

		mergeRecursion(array, left, middle);
		mergeRecursion(array, middle+1, right);
		mergeSort(array, left, middle, right);
	}
}

int partition(int array[], int low, int high){
	int pivot = array[high];
	int i = (low - 1);

	for(int j=low; j<=high-1; j++){
		if(array[j]<=pivot){
			i++;
			swap(&array[i], &array[j]);
		}
	}

	swap(&array[i+1], &array[high]);
	return (i+1);
}

int partition_r(int array[], int low, int high){
	srand(time(NULL));
	int random = low + rand() %  (high - low);
	swap(&array[random], &array[high]);
	return partition(array, low, high);
}

void quickSort(int array[], int low, int high){
	if(low < high){
		int piv =  partition(array, low, high);
		quickSort(array, low, piv-1);
		quickSort(array, piv+1, high);
	}
}

void quickSortRand(int array[], int low, int high){
	int piv = partition_r(array, low, high);
	quickSortRand(array, low, piv-1);
	quickSortRand(array, piv+1, high);
}

void printArray(int array[], int size){
	for(int i=0; i<size; i++){
		cout << array[i] << " ";
	}

	cout << endl;
}

int main(){
	int n=400;
	int array[n];
	srand(time(NULL));
	for(int i=0; i<n; i++){
		int random = rand()%400;
		array[i]=random;
	}

	clock_t start;
	double duration;
	start = clock();
	quickSort(array,0,n-1);
	duration = (clock() - start) / (double) CLOCKS_PER_SEC;
	cout << "Quick Sort: ";
	printArray(array, n);
	cout << "Duration: " << duration << endl;

	return 0;
}
