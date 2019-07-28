#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int isSubsetSetSum(int arr[],int n,int sum)
{
	if(sum!=0 && n==0)
	{
		return 0;
	}
	if(sum==0)
	{
		return 1;
	}
	if(arr[n-1]>sum)
	{
		isSubsetSetSum(arr,n-1,sum);
	}
	return(isSubsetSetSum(arr,n-1,sum) || isSubsetSetSum(arr,n-1,sum-arr[n-1]));
}

int main()
{
	long int t,n,sum;
	scanf("%ld",&t);
	while(t--)
	{
		scanf("%ld",&n);
		int arr[n];
		for(int i=0;i<n;i++)
		{
			scanf("%d",&arr[i]);
		}
		scanf("%ld",&sum);
		if(isSubsetSetSum(arr,n,sum)==1)
		{
			printf("Yes Found!");
		}
		else
		{
			printf("No");
		}
		printf("\n");
	}
	return 0;
}
