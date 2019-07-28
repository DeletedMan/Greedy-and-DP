#include<stdio.h>
#include<stdlib.h>

int max(int a,int b)
{
	return(a>b?a:b);
}

int main()
{
	int t,n;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		int arr[2][n];
		for(int i=0;i<2;i++)
		{
			for(int j=0;j<n;j++)
			{
				scanf("%d",&arr[i][j]);
			}
		}
		int *dp=(int*)malloc(sizeof(int)*n);
		dp[0]=max(arr[0][0],arr[1][0]);
		dp[1]=max(arr[0][1],arr[1][1]);
		for(int i=2;i<n;i++)
		{
			dp[i]=max(max(arr[0][i],arr[1][i])+dp[i-2],dp[i-1]);
		}
		printf("%d\n",dp[n-1]);
	}
	return 0;
}
