#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<limits.h>

void printArr(int arr[],int n)
{
	int i;
	for(i=0;i<n;i++)
	{
		printf("%d ",arr[i]);
	}
	printf("\n");
	return;
}

int maximum(int a,int b)
{
	return(a>b?a:b);
}

int CutRod(int price[],int n)
{
	int i,max=0;
	if(n<=0)
	{
		return 0;
	}
	for(i=0;i<n;i++)
	{
		max=maximum(max,price[i]+CutRod(price,n-1-i));
	}
	return max;
}

int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n,i;
		printf("Enter the lenght of the rod:\n");
		scanf("%d",&n);
		int arr[n];
		for(i=0;i<n;i++)
		{
			scanf("%d",&arr[i]);
		}
		printf("The content of the array is :\n");
		printArr(arr,n);
		printf("The maximum value is:%d\n",CutRod(arr,n));
	}
	return 0;
}
