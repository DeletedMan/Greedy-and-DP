#include<stdio.h>
#include<stdlib.h>

int ldsc(int arr[],int n)
{
	int *list=(int*)malloc(sizeof(int)*n);
	for(int k=0;k<n;k++)
	{
		list[k]=1;
	}
	
	int i,j,max_len=0;
	for(i=1;i<n;i++)
	{
		for(j=0;j<i;j++)
		{
			if(arr[i]<arr[j] && list[i]<list[j]+1)
			{
				list[i]=list[j]+1;
			}
		}
	}
	
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
		printf("%d\n",ldsc(arr,n));
	}
	return 0;
}
