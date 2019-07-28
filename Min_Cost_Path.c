#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#define R 3
#define C 3

int minimum(int b,int c)
{
	return(b<c?b:c);
}

int min(int a,int b,int c)
{
	return(minimum(a,minimum(b,c)));
}

int MinCostPath(int cost[R][C],int m,int n)
{
	if(m==0 && n==0)
	{
		return cost[m][n];
	}
	if(m<0 || n<0)
	{
		return INT_MAX;
	}
	else
	{
		return(cost[m][n]+min(MinCostPath(cost,m-1,n-1),MinCostPath(cost,m,n-1),MinCostPath(cost,m-1,n)));
	}
}

int main()
{
	int  t,n,m;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d %d",&m,&n);
		int arr[R][C];
		for(int i=0;i<R;i++)
		{
			for(int j=0;j<C;j++)
			{
				scanf("%d",&arr[i][j]);
			}
		}
		printf("%d\n",MinCostPath(arr,m,n));	
	}
	return 0;
}
