#include<stdio.h>
#include<stdlib.h>

int matchCount(char[],char[],int,int);

int main()
{
   FILE*fp = fopen("strMtchRes.txt","w");
   int n = 10, m = 3;
   
   while(n != 110)
   {
      int b, w, avg, i;
      char txt[n], ptrn[3];

      for(i = 0; i<n; i++)
         txt[i] = 'a';      // setting text

      for(i = 0; i<m; i++)
         ptrn[i] = 'a';

      b = matchCount(txt,ptrn,n,3);  // best case

      ptrn[2] = 'b';
      w = matchCount(txt,ptrn,n,3);  // worst case
   
      ptrn[1] = 'b';
      avg = matchCount(txt,ptrn,n,3);// average case 
      
      fprintf(fp,"%d\t%d\t%d\t%d\n",n,b,w,avg);
      n+= 10;
   }

   fclose(fp);
   return 0;
}


int matchCount(char txt[], char ptrn [], int n, int m)
{
   int i, j, count = 0;

   for(i = 0; i<= n-m; i++)
   {
      j = 0;

      while(j<m && ptrn[j] == txt[i+j])
      {
         j++;
         count++;
      }

      if(j == m)
         break;

      count++;     
   }

   return count;
}