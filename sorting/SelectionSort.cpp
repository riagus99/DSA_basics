#include <stdio.h>

void Swap(int &a, int &b){
	int temp = a;
	a = b;
	b = temp;
}

void SelectionSort(int* arr, int size){                         // Best case : O(n), Worst Case : O(n^2)
	int min, index;
	for(int i = 0; i < size-1; i++){
		min = arr[i];
		index = i;
		for (int j = i+1; j < size; j++){ // find minimum value & index from arr[j] ~ arr[end]
			if (min > arr[j]) {
				min = arr[j];
				index = j;
			}
		}
		Swap(arr[i], arr[index]); // swap with minimum element
	}
}

int main(void){
	int N;
	int num_array[1000];
	scanf("%d", &N);
	for (int i = 0; i < N; i++) scanf("%d", &num_array[i]);
	// for (int i = 0; i < N; i++) printf("%d\n", num_array[i]);
	
	// implement bubble sort
	SelectionSort(num_array, N);
	
	// print results
	for (int i = 0; i < N; i++) printf("%d\n", num_array[i]);
	
}
