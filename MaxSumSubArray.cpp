#include<iostream>
#include<bits/stdc++.h>
#include<stack>
#include<list>
#include<set>
#include<map>

using namespace std;

int maxSum(int arr[],int n)
{
	int index=-1;
	int max_so_far=INT_MIN,curr_sum=0;
	int i;
	for(i=0;i<n;i++)
	{
		curr_sum+=arr[i];
		if(curr_sum>max_so_far)
		{
			max_so_far=curr_sum;
			index=i;
		}
		if(curr_sum<0)
		{
			curr_sum=0;
		}
	}
	return max_so_far;
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
		std::cout<<maxSum(arr,n)<<endl;
	}
	return 0;
}
