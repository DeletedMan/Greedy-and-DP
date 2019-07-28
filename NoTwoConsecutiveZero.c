#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int NoTwoConsecutiveZero(int n)
{
	int table[n+1];
	memset(table,0,sizeof(table));
	table[0]=0;
	table[1]=2;
	table[2]=3;
	for(int i=3;i<(n+1);i++)
	{
		table[i]=table[i-1]%1000000007 + table[i-2]%1000000007;
	}
	return (table[n]%1000000007);
}

int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n;
		scanf("%d",&n);
		printf("%d ",NoTwoConsecutiveZero(n));
		printf("\n");
	}
	return 0;
}
