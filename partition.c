#include<stdio.h>
#include<stdlib.h>

int isSubSetSum(int arr[],int n,int sum)
{
	if(sum==0)
	{
		return 1;
	}
	if(sum>0 && n==0)
	{
		return 0;
	}
	if(arr[n-1]>sum)
	{
		isSubSetSum(arr,n-1,sum);
	}
	else
	{
		return(isSubSetSum(arr,n-1,sum) || isSubSetSum(arr,n-1,sum-arr[n-1]));
	}
} 

int main()
{
	int t,i;
	scanf("%d",&t);
	while(t--)
	{
		int n;
		scanf("%d",&n);
		int arr[n];
		for(i=0;i<n;i++)
		{
			scanf("%d",&arr[i]);
		}
		int sum=0;
		for(i=0;i<n;i++)
		{
			sum+=arr[i];
		}
		if(sum%2==0)
		{
			if(isSubSetSum(arr,n,sum/2)==1)
			{
				printf("YES\n");
			}
			else
			{
				printf("NO\n");
			}
		}
		else
		{
			printf("NO\n");
		}
	}
	return 0;
}
