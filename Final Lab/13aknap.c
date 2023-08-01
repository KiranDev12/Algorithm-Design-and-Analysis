#include <stdio.h>
int n,Cap;
int max(int a,int b){
    return (a>b?a:b);
}
void main(){
    int T[20][20],Wt[20]={0},Val[20]={0},n,Cap,Max;
    printf("Enter no of items\n");
    scanf("%d",&n);
    printf("Enter Sack capacity\n");
    scanf("%d",&Cap);
    printf("Enter the Weight and Value of items\n");
    for (int i = 1; i < n+1; i++)
    {
        scanf("%d %d",&Wt[i],&Val[i]);
    }
    for (int i = 0; i < n+1; i++)
    {
        for (int j = 0; j < Cap+1; j++)
        {
            if(i==0||j==0){
                T[i][j]=0;
            }
            else if(j<Wt[i]){
                T[i][j]=T[i-1][j];
            }
            else{
                T[i][j]=max(T[i-1][j],Val[i]+T[i-1][j-Wt[i]]);
            }
        }
        
    }
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= Cap; j++)
        {
            printf("%d  ",T[i][j]);
        }
        printf("\n");
    }
    
    Max=T[n][Cap];
    printf("Max:%d\n",Max);
    printf("Composition:\n");
    for (int i = n; i > 0; i--)
    {
        if(T[i][Cap]!=T[i-1][Cap]){
            printf("%d ",i);
            Cap=Cap-Wt[i];
        }
    }
    

}