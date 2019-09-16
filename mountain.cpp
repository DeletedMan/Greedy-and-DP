#include<iostream>
#include<bits/stdc++.h>
#include<stack>
#include<queue>
#include<deque>

using namespace std;

long long int preprocess(long long int arr[],long long int n,long long int left[],long long int right[])
{
	left[0]=0;
	int firstIncr=0,i;
	for(i=1;i<n;i++)
	{
		if(arr[i]>arr[i-1])
		{
			firstIncr=i;
		}
		left[i]=firstIncr;
	}
	int firstDecr=n-1;
	right[n-1]=n-1;
	for(i=n-2;i>=0;i--)
	{
		if(arr[i]>arr[i+1])
		{
			firstDecr=i;
		}
		right[i]=firstDecr;
	}
}

bool isSubarrayMountainForm(long long int arr[],long long int left[],long long int right[],long long int l,long long int r)
{
	return right[l]>=left[r];
}
int main()
{
	int test;
	std::cin>>test;
	while(test--)
	{
		long long  int n;
		std::cin>>n;
		long long int *arr=new long long int[n];
		for(int i=0;i<n;i++)
		{
			std::cin>>arr[i];
		}
		long long int l,r;
		std::cin>>l>>r;
		long long int left[n],right[n];
		preprocess(arr,n,left,right);
		if(isSubarrayMountainForm(arr,left,right,l,r))
		{
			std::cout<<"Yes"<<endl;
		}
		else
		{
			std::cout<<"No"<<endl;
		}
	}
	return 0;
}
