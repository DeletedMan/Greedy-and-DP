#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int count(int n)
{
	int c=(n/2+1);
	int table[c];
	memset(table,0,sizeof(table));
	table[0]=1,table[1]=1,table[2]=2;
	for(int i=3;i<c;i++)
	{
		table[i]=table[i-1]+table[i-2]+table[i-3];
	}
	return table[c-1];
}

int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n;
		scanf("%d",&n);
		printf("%d",count(n));
	}
	return 0;
}
