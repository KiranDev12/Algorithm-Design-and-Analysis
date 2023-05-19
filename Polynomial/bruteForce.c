#include<stdio.h>
#include<stdlib.h>
int main(){
	int n = 3;
	FILE *fp = fopen("brute.txt", "w");
	if(fp==NULL){
		printf("Error...\n");
		exit(1);
	}
	while(n!=11){
		int arr[n], sum = 0, count = 0, power, i, j;
		int x_val = rand()%100;
		for(i=0; i<n; i++){
			arr[i]=i+1;
		}
		for(i=n-1;i>=0; i--){
			power = 1;
			for(j=1; j<=i; j++){
				count++;
				power*=x_val;
			}
			sum+=arr[i]*power;
		}
		fprintf(fp, "%d\t%d\n", n-1, count);
		n++;
	}
	return 0;
}	