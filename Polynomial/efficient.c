#include<stdio.h>
#include<stdlib.h>

int main(){
	int n = 3;
	FILE *fp = fopen("polyEff.txt", "w");
	if(fp==NULL){
		printf("\nError...\n");
		exit(1);
	}
	while(n!=11){
		int arr[n], sum, count=0, power, j, i;
		int x_val = rand()%100;
		for(i=0;i<n;i++){
			arr[i]=i+1;
		}
		sum = arr[0];
		power = 1;
		for(i=1;i<n; i++){
			count++;
			power*=x_val;
			sum+=arr[i]*power;
		}
		fprintf(fp, "%d\t%d\n", n-1, count);
		n++;
	}
	return 0;
}