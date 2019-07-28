#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int power(int x,int y)
{
	if(y==0)
	{
		return 1;
	}
	else if(y%2==0)
	{
		return power(x,y/2)*power(x,y/2);
	}
	else
	{
		return x*power(x,y/2)*power(x,y/2);
	}
}

int compute_sum_array(int d)
{
	int *arr=(int *)malloc(sizeof(int)*(d+1));
	arr[0]=0;
	arr[1]=45;
	int i;
	for(i=2;i<=d;i++)
	{
		arr[i]=arr[i-1]*10 + 45*power(10,i-1);
	}
	return arr[d];
}

int SumOfAllDigit(int n)
{
	int d=log10(n);
	int sum=compute_sum_array(d);
	int t=power(10,d);
	int lmd=n/power(10,d);
	return (lmd*sum+lmd*(lmd-1)*0.5+lmd*(1+n%t)+SumOfAllDigit(n%t));
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
