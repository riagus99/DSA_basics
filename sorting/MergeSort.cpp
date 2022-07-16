#include <stdio.h>

void Swap(int &a, int &b){
	int temp = a;
	a = b;
	b = temp;
}

void CopyArray(int* A, int* B, int size){ // copy array A to B
	for (int i = 0; i < size; i++) B[i] = A[i];
}

void TopDownMerge(int* B, int* A, int start, int mid, int end){ // sorting result from B to A
	int i = start;
	int j = mid + 1;
	for (int k = start; k < end + 1; k++){
		if (i < mid + 1 && (j >= end + 1 || B[j] > B[i])) { // CRUCIAL !! should consider when idx is out of bound
			A[k] = B[i];
			i++;
		}
		else {
			A[k] = B[j];
			j++;
		}
	}
}

void MergeSortTopDown(int* B, int* A, int start, int end){ // from B to A
	if (start < end) {
		int mid = (start + end) / 2;
		MergeSortTopDown(A, B, start, mid); // sorting result from A to B
		MergeSortTopDown(A, B, mid + 1, end);
		TopDownMerge(B, A, start, mid, end); // sorting result from B to A
	}
}

void MergeSort(int* A, int* B, int size){       // time complexity : O(nlogn)
	// Top down -> Divide & Conquer Algorithm
	CopyArray(A,B,size); // copy array A to B(original array)
	MergeSortTopDown(B, A, 0, size-1); // save sorted result in A	
}

int main(void){
	int N;
	int *num_array, *sub_array;
	scanf("%d", &N);
	num_array = new int[N];
	for (int i = 0; i < N; i++) scanf("%d", &num_array[i]);
	// for (int i = 0; i < N; i++) printf("%d\n", num_array[i]);
	
	// implement merge sort
	sub_array = new int[N]; // need additional storage for saving intermediate result
	MergeSort(num_array, sub_array, N);
	
	// print results
	for (int i = 0; i < N; i++) printf("%d\n", num_array[i]);
	
	delete[] num_array;
	delete[] sub_array;
}
