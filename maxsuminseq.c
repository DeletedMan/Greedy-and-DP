#include<stdio.h>
#include<stdlib.h>

int maxsuminseq(int arr[],int n)
{
	int list[n],i;
	for(i=0;i<n;i++)
	{
		list[i]=arr[i];
	}
	for(i=1;i<n;i++)
	{
		for(int j=0;j<i;j++)
		{
			if(arr[i]>arr[j] && list[i]<arr[i]+list[j])
			{
				list[i]=arr[i]+list[j];
			}
		}
	}
	int max_val=0;
	for(i=0;i<n;i++)
	{
		if(max_val<list[i])
		{
			max_val=list[i];
		}
	}
	return max_val;
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
		printf("%d\n",maxsuminseq(arr,n));
	}
	return 0;
}
