#include<stdio.h>
#include<stdlib.h>

int binSrch(int[],int,int);

int main()
{
   FILE*fp = NULL;
   fp = fopen("q2b.txt","w");
   if(fp == NULL)
   {
       printf("\nError!!\n");
       exit(1);
   }

   int n=10,i,keyB,keyW,keyA;
   
   while(n!=110)
   {
      int a[n];
      
      for(i=0;i<n;i++)
      a[i] = i+1;

      keyB = binSrch(a,n,a[(n-1)/2]);
      keyW = binSrch(a,n,a[n-1]);
      i = (rand()+1)%n;
      keyA = binSrch(a,n,a[i]);
      
      fprintf(fp,"%d\t%d\t%d\t%d\n",n,keyB,keyA,keyW);
      n+=10; 
   }
   
   fclose(fp);

   return 0;
}


int binSrch(int a[],int n, int key)
{
   int count = 0,left,right,mid;
   left = 0;
   right = n-1;
   
   while(left<=right)
   {
      count++;
      mid = (left + right)/2;

      if(a[mid] == key)
      break;
   
      else if(a[mid] < key)
      left = mid+1;
   
      else
      right = mid-1;
   }

   return count;
}





