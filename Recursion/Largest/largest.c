#include<stdio.h>
#include<stdlib.h>

int largestCount(int[],int,int,int*);

int main()
{
   FILE*fp = fopen("result.txt","w");
   if(fp == NULL)
   {
      perror("Error!!");
      exit(1);
   }

   int n=10, i=0;

   while(n!=110)
   {
      int arr[n], l=0, r=n-1, a, count=0; 
      int*p = &count;
      for(a=i; a<n; a++)
        arr[i] = i+1;

      a = largestCount(arr,l,r,p);
      fprintf(fp,"%d\t%d\n",n,*p);
      n+=10;
      i+=10;
   }   

   fclose(fp);

   return 0;
}

int largestCount(int arr[], int l, int r, int*p)
{
   int count=0;
   
   if(r == l)
     return l;

   else
   {
     int t1 = largestCount(arr,l,(l+r)/2,p);
     int t2 = largestCount(arr,(l+r)/2+1,r,p);
     *p+=1;

     if(arr[t1] > arr[t2])
       return t1;

     else
       return t2;
   }
}