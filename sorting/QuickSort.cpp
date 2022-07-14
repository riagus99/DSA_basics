#include <stdio.h>

void Swap(int &a, int &b){
	int temp = a;
	a = b;
	b = temp;
}

int Partition(int* arr, int left, int right){
	/* description : select the pivot as the first element of the array -> arr[left]
	partition the array -> left part is smaller than the pivot, right part is greater than the pivot
	insert the pivot in the middle of 2 parts
	and then, return the index of the pivot
	*/
	int pivot = arr[left];
	int low = left + 1;
	int high = right;
	while(low <= high){
		// start from the left + 1, find the element which is greater than or same as the pivot
		while (pivot > arr[low] && low <= right) low++;
		// start from the right, find the element which is smaller than the pivot
		while (pivot <= arr[high] && high >= left + 1) high--;
		// swap the element and proceed... until high < low
		if (low < high) Swap(arr[low], arr[high]); // else, end of the partitioning, does not have to do anything
	}
	// swap the pivot and arr[high]
	Swap(arr[left], arr[high]);
	// return the index of the pivot
	return high;
}

void QuickSort(int* arr, int left, int right){       // best & average case : O(nlogn), Worst Case : O(n^2)
	// Divide & Conquer Algorithm
	if (left < right){ // if only array size is greater than 1
		int pivot = Partition(arr, left, right); // divide
		QuickSort(arr, left, pivot-1);             // n conquer
		QuickSort(arr, pivot+1, right);
	}
	// else, doesn't have to do anything
}

int main(void){
	int N;
	int num_array[1000];
	scanf("%d", &N);
	for (int i = 0; i < N; i++) scanf("%d", &num_array[i]);
	// for (int i = 0; i < N; i++) printf("%d\n", num_array[i]);
	
	// implement quick sort
	QuickSort(num_array, 0, N-1);
	
	// print results
	for (int i = 0; i < N; i++) printf("%d\n", num_array[i]);
	
}
