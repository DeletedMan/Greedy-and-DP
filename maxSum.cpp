#include<iostream>
#include<bits/stdc++.h>
#include<cmath>
#include<stack>
#include<map>
#include<set>

using namespace std;

int max_Sum(int A[],int n)
{
	int i,sum=0;
	for(i=0;i<n;i++)
	{
		sum+=i*A[i];
	}
	return sum;
}

int max_sum(int A[],int n)
{
	int till_max=0,curr_max;
	int i,j;
	for(i=0;i<n;i++)
	{
		till_max+=i*A[i];
	}
	for(i=0;i<n-1;i++)
	{
		int temp=A[0];
		for(j=0;j<n-1;j++)
		{
			A[j]=A[j+1];
		}
		A[j]=temp;
		curr_max=max_Sum(A,n);
		if(curr_max>till_max)
		{
			till_max=curr_max;
		}
	}
	return till_max;
}

int main()
{
	int test;
	std::cin>>test;
	while(test--)
	{
		int n;
		std::cin>>n;
		int *arr=new int[n];
		for(int i=0;i<n;i++)
		{
			std::cin>>arr[i];
		}
		std::cout<<max_sum(arr,n)<<endl;
	}
	return 0;
}
