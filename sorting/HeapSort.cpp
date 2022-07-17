#include <stdio.h>

void swap(int &a, int &b){
	int temp = a;
	a = b;
	b = temp;
}

void heapify(int *arr, int parentnode, int size){
	int childnode1 = parentnode * 2 + 1;
	int childnode2 = parentnode * 2 + 2;
	
	int largest = parentnode;
	if (childnode1 < size && arr[childnode1] > arr[largest]) largest = childnode1;
	if (childnode2 < size && arr[childnode2] > arr[largest]) largest = childnode2;
	
	if (largest != parentnode) {
		swap(arr[parentnode], arr[largest]);
		heapify(arr, largest, size);
	}
}

void heapSort(int *arr, int size){
	// initially make max heap
	for (int i = size / 2 - 1; i >= 0; i--) heapify(arr, i, size); // the number of inner node = [number of all nodes / 2]
	// iteratively sort & heapify
	for (int i = size - 1; i > 0; i--){
		swap(arr[0], arr[i]); // swap with root element
		heapify(arr, 0, i);   // heapify from the root node
	}
}

int main(void){
	int N;
	scanf("%d", &N);
	int *num_array;
	num_array = new int[N];
	for (int i = 0; i < N; i++) scanf("%d", &num_array[i]);
	
	heapSort(num_array, N);
	
	for (int i = 0; i < N; i++) printf("%d\n", num_array[i]);
	
	delete[] num_array;
}
