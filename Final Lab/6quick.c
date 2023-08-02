#include<stdio.h>
#include<stdlib.h>

int count=0;

void swap(int *a,int *b)
{
	int temp=*a;
	*a=*b;
	*b=temp;
}

int partition(int arr[],int low,int high)
{
	int pivot=arr[low];
	int i=low;
	int j=high;
	
	while(i<j){
		if(arr[i]>pivot)
		    count++;
		while(arr[i]<=pivot){
			i++;
			count++;
		}
		while(arr[j]>pivot){
			j--;
			count++;
		}
		if(arr[j]<=pivot)
		        count++;
		swap(&arr[i],&arr[j]);
		
	}
	swap(&arr[i],&arr[j]);
	swap(&arr[low],&arr[j]);
	return j;

}

void quickSort(int arr[],int low,int high){
	if(low<high){
		int pivot=partition(arr,low,high);
		quickSort(arr,low,pivot-1);
		quickSort(arr,pivot+1,high);
	}
}

void bestSwap(int arr[],int l,int r){
	if (l<r){
		int mid = (l+r)/2;
		bestSwap(arr,l,mid-1);
		swap(&arr[l],&arr[mid]);
		bestSwap(arr,mid+1,r);
	}
}

void printArray(int *arr,int n)
{
	for (int i = 0; i < n-1; i++)
	{
		printf("%d ",arr[i]);
	}
	printf("\n\n");
}

void main()
{
	FILE *fp=fopen("Plot.txt","w");
	int n=2,result1,result2,result3;
	while(n<=512)
	{
		int arr[n],i;
		for(i=0;i<n;i++)
			arr[i]=i+1;
		
		//Worst Case
		count=0;
		quickSort(arr,0,n-1);
		result3=count;
		
		//Best Case
		count=0;
		bestSwap(arr,0,n-1);
		// for(i=0;i<n;i++)
		// 	arr[i]=1;
		printArray(arr,n-1);
		quickSort(arr,0,n-1);
		result1=count;	
		
		//Avg Case
		count=0;
		for(i=0;i<n;i++)
			arr[i]=rand()%100;
		quickSort(arr,0,n-1);
		result2=count;
		fprintf(fp,"%d\t%d\t%d\t%d\n",n,result1,result2,result3);

		n*=2;

	}
	fclose(fp);
	
}
