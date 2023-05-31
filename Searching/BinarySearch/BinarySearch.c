#include<stdio.h>
#include<stdlib.h>
#include<time.h>


FILE * ptr;


int BinarySearch(int arr[], int size, int key){
	int low = 0;
	int count = 0;
	int high = size - 1;
	int mid = (low+high)/2;
	while(low<=high){
		count++;
		mid = (low+high)/2;
		if(arr[mid]==key){
			return count;
		}
		else if(arr[mid]>key){
			high=mid-1;
		}
		else{
			low=mid+1;
		}
	}
	return count;
}
int main(){
	int size;
	int i, x, result;
	srand(time(0));
	int j = 10;
	ptr = fopen("Iterative.txt", "w");
	if(ptr==NULL){
		printf("Error file not generated\n");
		exit(0);
	}
	while(j!=110){
		int arr[j];
		for(i=0;i<j;i++)
			arr[i] = i;
		
		//BEST CASE =>
		x = arr[(j-1)/2];
		int k;
		int count = BinarySearch(arr, j, x);
		
		fprintf(ptr, "%d\t%d\t", j, count);
		
		//WORST CASE =>	
		x = arr[j-1];
		count = BinarySearch(arr, j, x);
		
		fprintf(ptr, "%d\t", count);

		//AVERAGE CASE =>
		x = rand()%j;
		count = BinarySearch(arr, j, x);
		
		fprintf(ptr, "%d\n", count);
		
		
		j = j + 10;
	}
		return 0;
}
