#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define R 10
#define C 10

//m---->Row
//n---->Column
int min(int a,int b)
{
	return(a>b?b:a);
}

int minimum(int a,int b,int c)
{
	return (min(a,min(b,c)));
}

int findways(int cost[R][C],int m,int n)
{
	int dp[R][C],i,j;
	dp[0][0]=cost[0][0];
	//inialize first column 
	for(i=1;i<=m;i++)
	{
		dp[i][0]=dp[i-1][0]+cost[i][0];
	}
	//Inialize the first row of the cost matrix
	for(j=1;j<=n;j++)
	{
		dp[0][j]=dp[0][j-1]+cost[j][1];
	}
	for(i=1;i<=m;i++)
	{
		for(j=1;j<=n;j++)
		{
			dp[i][j]=cost[i][j]+minimum(dp[i-1][j-1],dp[i-1][j],dp[i][j-1]);
		}
	}
	return dp[m][n];	
}

int main()
{
	int t,n,m;
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
		printf("%d\n",findways(arr,m,n));
	}
	return 0;
}
