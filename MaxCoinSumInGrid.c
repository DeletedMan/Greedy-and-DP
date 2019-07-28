#include<stdio.h>
#include<stdlib.h>

void printArr(int table[n][m],int n,int m)
{
	int i,j;
	for(i=0;i<n;i++)
	{
		for(j=0;j<m;j++)
		{
			printf("%d ",table[i][j]);
		}
		printf("\n");
	}
	printf("\n");
	return;
}

int max(int a,int b)
{
	return(a>b?a:b);
}

int MaxCoinSumInGrid(int table[n][m],int x,int y1,int y2,int n,int m)
{
	int maxCoin=0;
	if(y1==y2)
	{
		maxCoin+=table[x][y1];
	}
	else
	{
		maxCoin+=table[x][y1]+table[x][y2];
	}
	maxCoin+=Maximum(MaxCoinSumInGrid(table,x+1,y1,y2,n,m),
	             MaxCoinSumInGrid(table,x+1,y1,y2-1,n,m),
	             MaxCoinSumInGrid(table,x+1,y1,y2+1,n,m),
	             MaxCoinSumInGrid(table,x+1,y1+1,y2,n,m),
	             MaxCoinSumInGrid(table,x+1,y1+1,y2-1,n,m),
	             MaxCoinSumInGrid(table,x+1,y1+1,y2+1,n,m),
	             MaxCoinSumInGrid(table,x+1,y1-1,y2,n,m),
	             MaxCoinSumInGrid(table,x+1,y1-1,y2-1,n,m),
	             MaxCoinSumInGrid(table,x+1,y1-1,y2+1,n,m));
	return maxCoin;             
}

int main()
{
	int n,m;
	printf("Enter the number of row and collumn:\n");
	scanf("%d %d",&n,&m);
	int table[n][m];
	int i,j;
	for(i=0;i<n;i++)
	{
		for(j=0;j<m;j++)
		{
			scanf("%d",&table[i][j]);
		}
	}
	printArr(table,m,n);
	printf("%d ",MaxCoinSumInGrid(table,0,0,m-1,n,m));
	return 0;
}
