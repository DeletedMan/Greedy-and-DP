#include<stdio.h>
#include<stdlib.h>

void printArr(int arr[],int n)
{
	for(int i=0;i<n;i++)
	{
		printf("%d ",arr[i]);
	}
	printf("\n");
	return;
}

int MaximumSumSubArray(int arr[],int n)
{
	int max_sum_so_far=0;
	int current_sum=0;
	int index;
	for(index=0;index<n;index++)
	{
		current_sum=current_sum+arr[index];
		if(current_sum<0)
		{
			current_sum=0;
		}
		else if(max_sum_so_far<current_sum)
		{
			max_sum_so_far=current_sum;
		}
	}
	return max_sum_so_far;
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
		printf("Content of the above array is:\n");
		printArr(arr,n);
		printf("This is our output:\n");
		printf("%d",MaximumSumSubArray(arr,n));
	}
	return 0;
}
