#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define R 6
#define C 5

void printArr(int table[R][C])
{
	for(int i=0;i<R;i++)
	{
		for(int j=0;j<C;j++)
		{
			printf("%d ",table[i][j]);
		}
		printf("\n");
	}
	printf("\n");
	return;
}

int min(int a,int b)
{
	return(a>b?b:a);
}

int minimum(int x,int y,int z)
{
	return(min(x,min(y,z)));
}

void MaximumSubMatrix(int table[R][C])
{
	int dp[R][C];
	int i,j;
	for(i=0;i<C;i++)
	{
		dp[0][i]=table[0][i];
	}
	for(j=0;j<R;j++)
	{
		dp[j][0]=table[j][0];
	}
	for(i=1;i<R;i++)
	{
		for(j=1;j<C;j++)
		{
			if(table[i][j]==1)
			{
				dp[i][j]=1+minimum(dp[i-1][j],dp[i][j-1],dp[i-1][j-1]);
			}
			else
			{
				dp[i][j]=0;
			}
		}
	}
	
	int max_val=dp[0][0];
	int k,l;
	for(i=0;i<R;i++)
	{
		for(j=0;j<C;j++)
		{
			if(dp[i][j]>max_val)
			{
				max_val=dp[i][j];
				k=i;
				l=j;
			}
		}
	}
	printf("\n");
	printf("Maximum size sub_matrix is:\n");
	for(i=0;i<max_val;i++)
	{
		for(j=0;j<max_val;j++)
		{
			printf("1");
		}
		printf("\n");
	}
	return;	
}

int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int table[R][C];
		for(int i=0;i<R;i++)
		{
			for(int j=0;j<C;j++)
			{
				scanf("%d",&table[i][j]);
			}
		}
		printf("Content of the above 2D-Array:\n");
		printArr(table);
		MaximumSubMatrix(table);
	}
	return 0;
}
