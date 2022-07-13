#include <stdio.h>

void InsertionSort(int* arr, int size){                         // Best case : O(n), Worst Case : O(n^2)
	int insertvalue, insertpos;
	for (int i = 1; i < size; i++){
		insertvalue = arr[i];                                   // copy insert value
		insertpos = i;
		while(insertpos > 0 && arr[insertpos-1] > insertvalue){
			arr[insertpos] = arr[insertpos-1];
			insertpos--;                                        // move insert position until it encounters the value smaller than(or same as) the insertvalue
		}
		arr[insertpos] = insertvalue;                           // insert value in insert position
	}
}

int main(void){
	int N;
	int num_array[1000];
	scanf("%d", &N);
	for (int i = 0; i < N; i++) scanf("%d", &num_array[i]);
	// for (int i = 0; i < N; i++) printf("%d\n", num_array[i]);
	
	// implement insertion sort
	InsertionSort(num_array, N);
	
	// print results
	for (int i = 0; i < N; i++) printf("%d\n", num_array[i]);
	
}
