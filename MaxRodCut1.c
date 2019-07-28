#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void printArr(int arr[],int n)
{
	for(int i=0;i<n;i++)
	{
		printf("%d ",arr[i]);
	}
	printf("\n");
	return;
}

int max(int a,int b)
{
	return(a>b?a:b);
}

int CutRod(int price[],int n)
{
	int table[n+1];
	memset(table,0,sizeof(table));
	table[0]=0;
	for(int i=1;i<=n;i++)
	{
		int max_val=-1;
		for(int j=0;j<i;j++)
		{
			max_val=max(max_val,price[j]+table[i-1-j]);
		}
		table[i]=max_val;
	}
	return table[n];
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
		printf("Maximum Obtainable Value is :%d \n",CutRod(arr,n));
	}
	return 0;
}
