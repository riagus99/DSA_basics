#include <stdio.h>

void CountingSort(int *arr, int size){
	// if all elements are natural numbers and are same as or less than 10000
	int *count_array = new int[10000];
	for (int i = 0; i < 10000; i++) count_array[i] = 0;
	for (int i = 0; i < size; i++){
		count_array[arr[i]-1]++; // count the numbers
	}
	
	int k = 0;
	for (int i = 0; i < 10000; i++){
		for (int j = 0; j < count_array[i]; j++){
			arr[k] = i+1;
			k++;
		}
	}
	
	delete[] count_array;
}

int main(void){
	int N;
	scanf("%d", &N);
	int *num_array;
	num_array = new int[N];
	for (int i = 0; i < N; i++) scanf("%d", &num_array[i]);
	
	CountingSort(num_array, N);
	
	for (int i = 0; i < N; i++) printf("%d\n", num_array[i]);
	
	delete[] num_array;
}
