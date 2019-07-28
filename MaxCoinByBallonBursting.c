#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int MaxCoinByBallonBursting(int arr[],int n)
{
	int table[n][n];
	//memset(table,0,sizeof(table));
	for(int i=0;i<n;i++)
	{
		table[i][i]=0;
	}
	i=0,j=1
	while(i<=0 && j<=4)
	{
		table[i][j]=0;
		i++;
		j++;
	}
	for(int len=2;len<=n-1;len++)
	{
		for(int i=0;i<n-(len+1);i++)
		{
			int j=i+len;
			if(j-i==2)
			{
				table[i][j]=table[i][j-1]+table[j-1][j]+arr[i]*arr[i+1]*arr[i+2];	
			}
			else
			{
				
			}
		}
	}
}
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n;
		scanf("%d",&n);
		int arr[n];
		for(int i=0;i<n;i++)
		{
			scanf("%d",&arr[i]);
		}
		printArr(arr,n);
		printf("Max Coin By Bursting above coin will be:\n");
		printf("%d",MaxCoinByBallonBursting(arr,n));
	}
	return 0;
}
