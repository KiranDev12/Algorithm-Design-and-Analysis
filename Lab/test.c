#include<stdio.h>
#include<stdlib.h>
#include<time.h>

FILE *ptr;

int binary_search(int arr[], int l, int r, int x, int *count){
    if (r >= l) {
        int mid = l + (r - l) / 2;
        if (arr[mid] == x){
            (*count)++;
            return mid;
        }
        if (arr[mid] > x){
            (*count)++;
            return binary_search(arr, l, mid - 1, x, count);
        }
        else{
            (*count)++;
            return binary_search(arr, mid + 1, r, x, count);
        }
    }
 
    return -1;
}

int main(){
    int size;
    int i, x, result1,result2,result3;
    srand(time(0));
    int j = 100;
    ptr = fopen("test.txt", "w");
    if(ptr==NULL){
        printf("Error file not generated\n");
        exit(0);
    }
    while(j<=2000){
        int arr[j];
        for(i=0;i<j;i++)
            arr[i] = i*100;
        printf("Array initialised\n");
        
        //BEST CASE =>
        x = arr[(j-1)/2];
        int k, count = 0;
        binary_search(arr, 0, j - 1, x, &count);
        result1=count;
        
        //AVERAGE CASE =>
        x=rand()%size;
        count = 0;
        binary_search(arr, 0, j - 1, x, &count);
        result2=count;
        
        //WORST CASE =>    
        x = -1;
        count = 0;
        binary_search(arr, 0, j - 1, x, &count);
        result3=count;
        
       fprintf(ptr,"%d\t%d\t%d\t%d\n",j,result1,result2,result3);
        j = j + 100;
    }
    return 0;
}
    