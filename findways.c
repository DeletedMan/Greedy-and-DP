#include<stdio.h>
#include<stdlib.h>
#include<string.h>

long long int findWays(int m,int n,int x)
{
	long long int table[n+1][x+1];
	int i,j,k;
	//memset(table,0,sizeof(table));
	//Filling all the table enteries with zeroes........
	for(i=0;i<=n;i++)
	{
		for(j=0;j<=x;j++)
		{
			table[i][j]=0;
		}
	}
	
	for(j=1;j<=m && j<=x;j++)
	{
		table[1][j]=1;
	}
	for(i=2;i<=n;i++)
	{
		for(j=1;j<=x;j++)
		{
			for(k=1;k<=m && k<j;k++)
			{
				table[i][j]=table[i][j]+table[i-1][j-k];
			}
		}
	}
	return table[n][x];
}

int main()
{
	int t,x,y,z;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d %d %d",&x,&y,&z);
		printf("%lld\n",findWays(x,y,z));
	}
	return 0;
}
