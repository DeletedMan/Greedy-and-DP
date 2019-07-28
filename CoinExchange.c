#include<stdio.h>
#include<stdlib.h>

int CoinExchange(int arr[],int m,int n)
{
	int x,i,j;//m :amount
	//n is number of coin
	int table[n+1][m+1];
	for(i=0;i<(m+1);i++)
	{
		table[0][i]=0;
	}
	for(j=0;j<(n+1);j++)
	{
		table[j][0]=1;
	}
	for(i=1;i<(n+1);i++)
	{
		for(j=1;j<(m+1);j++)
		{
			if(arr[i-1]<=j)
			{
				x=table[i-1][j]+table[i][j-arr[i-1]];
			}
			else if(arr[i-1]>j)
			{
				x=table[i-1][j];
			}
			table[i][j]=x;
		}
	}
	return x;
}

int main()
{
	int m,n,i;
	scanf("%d",&n);
	int arr[n];
	for(i=0;i<n;i++)
	{
		scanf("%d",&arr[i]);
	}
	printf("Enter the required sum number:\n");
	scanf("%d",&m);
	printf("%d ",CoinExchange(arr,m,n));
	return 0;
}
