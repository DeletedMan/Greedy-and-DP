#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int max(int a,int b)
{
	return(a>b?a:b);
}

int MaxDotProduct(int *A,int *B,int m,int n)
{
	int dp[n+1][m+1];
	memset(dp,0,sizeof(dp));
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			dp[i][j]=max(A[i-1]*B[j-1]+dp[i-1][j-1],dp[i][j-1]);
		}
	}
	return dp[n][m];
}
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int m,n;
		scanf("%d %d",&m,&n);
		int *A=(int*)malloc(sizeof(int)*m);
		int *B=(int*)malloc(sizeof(int)*n);
		for(int i=0;i<m;i++)
		{
			scanf("%d",&A[i]);
		}
		for(int j=0;j<n;j++)
		{
			scanf("%d",&B[j]);
		}
		int m1=sizeof(A)/sizeof(A[0]);
		int n1=sizeof(B)/sizeof(B[0]);
		printf("%d\n",MaxDotProduct(A,B,m1,n1));
	}
	return 0;
}
