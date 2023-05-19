#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void swap(int arr[], int i, int j){
	int temp = arr[i];
	arr[i] = arr[j];
	arr[j] = temp;
}

void selectionSort(int arr[], int n, int * count){
	for(int i = 0; i<n-1; i++){
		int minIndex = i;
		for(int j = 0; j<n; j++){
			(*count)++;
			if(arr[j]<arr[minIndex]){
				minIndex = j;
			}
		}
		if(minIndex!=i){
			swap(arr, i, minIndex);
		}
	}
}

int main(){
	FILE *fptr;
	fptr=fopen("count.txt", "w");
	for(int n = 10; n<=100; n+=10){
		int arr[n];
		srand(time(NULL));
		
		//Best Case
		for(int i = 0; i<n; i++){
			arr[i]=i;
		}
		int count=0;
		selectionSort(arr, n, &count);
		fprintf(fptr, "%d\t%d", n, count);

		//Avg Case
		for(int i = 0; i<n; i++){
			arr[i]=rand()%100;
		}
		count=0;
		selectionSort(arr, n, &count);
		fprintf(fptr, "\t%d",count);

		//Worst Case
		for(int i = 0; i<n; i++){
			arr[i]=n-i;
		}
		count=0;
		selectionSort(arr, n, &count);
		fprintf(fptr, "\t%d\n", count);
	}
	fclose(fptr);
	return 0;
}