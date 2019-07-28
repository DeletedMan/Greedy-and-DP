#include<stdio.h>
#include<stdlib.h>

// This is Naive Approach of above algorithm...

int SumOfAllDigit(int n)
{
	int temp;
	int sum=0;
	for(int i=1;i<=n;i++)
	{
		temp=i;
		while(temp!=0)
		{
			sum=sum+temp%10;
			temp=temp/10;
		}
	}
	return sum;
}

int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n;
		scanf("%d",&n);
		printf("%d ",SumOfAllDigit(n));
		printf("\n");
	}
	return 0;
}
