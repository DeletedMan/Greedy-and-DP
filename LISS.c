#include<stdio.h>
#include<stdlib.h>
#include<string.h>

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

int liss(int arr[],int n)
{
	int i,j;
	int *list=(int*)malloc(sizeof(int)*n);
	//memset(list,1,sizeof(list));
	for(int k=0;k<n;k++)
	{
		list[k]=1;
	}
	for(i=1;i<n;i++)
	{
		for(j=0;j<i;j++)
		{
			if(arr[i]>arr[j] && list[i]<list[j]+1)
			{
				list[i]=list[j]+1;
			}
		}
	}
	int max_len=0;
	for(int i=0;i<n;i++)
	{
		if(max_len<list[i])
		{
			max_len=list[i];
		}
	}	
	return max_len;	
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
		printf("The Content of the array is:\n");
		printArr(arr,n);
		printf("The Longest Increasing Sequence is:");
		printf("%d",liss(arr,n));
	}
	return 0;
}
