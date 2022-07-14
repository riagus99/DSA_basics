#include <stdio.h>

void Swap(int &a, int &b){
	int temp = a;
	a = b;
	b = temp;
}

void BubbleSort(int* arr, int size){                         // Best case : O(n), Worst Case : O(n^2)
	bool swapped;
	for(int i = 0; i < size-1; i++){
		swapped = false;
		for (int j = 0; j < size - i - 1; j++){
			if (arr[j] > arr[j+1]) {
				Swap(arr[j], arr[j+1]);
				swapped = true;
			}
		}
		if (!swapped) break;    // if not swapped, break
	}
}

int main(void){
	int N;
	int num_array[1000];
	scanf("%d", &N);
	for (int i = 0; i < N; i++) scanf("%d", &num_array[i]);
	// for (int i = 0; i < N; i++) printf("%d\n", num_array[i]);
	
	// implement bubble sort
	BubbleSort(num_array, N);
	
	// print results
	for (int i = 0; i < N; i++) printf("%d\n", num_array[i]);
	
}
