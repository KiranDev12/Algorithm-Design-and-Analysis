#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int powOpCount(int, int, int *);

int main(){
	FILE *fp = fopen("powOpCount.txt", "w");
	
	int a=3, n=2;
	while(n!=11){
		int count=0;
		int ans=powOpCount(a, n, &count);
		fprintf(fp, "%d\t%d\n", n, count);
		n++;	
	}
	fclose(fp);
	return 0;
}

int powOpCount(int a, int n ,int *count){
	if(n==1){
		return a;	
	}
	else{
		*count+=1;
		return powOpCount(a, n/2, count)*powOpCount(a, n/2+(n%2), count);
	}
}