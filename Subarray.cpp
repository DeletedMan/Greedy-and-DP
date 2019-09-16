#include<iostream>
#include<bits/stdc++.h>
#include<stack>
#include<algorithm>
#include<set>

using namespace std;

int Subarray(unsigned long int arr[],unsigned long int n,unsigned long int sum)
{
	int start=0,i;
	int curr_sum=arr[0];
	for(i=1;i<=n;i++)
	{
		if(curr_sum>sum && start<i-1)
		{
			curr_sum=curr_sum-arr[start++];
		}
		if(curr_sum==sum)
		{
			std::cout<<start+1<<" "<<i-1<<endl;
			return 1;
		}
		if(i<n)
		{
			curr_sum+=arr[i];
		}
	}
	return 0;
}

int main()
{
	int test;
	std::cin>>test;
	while(test--)
	{
		unsigned long int n,sum;
		std::cin>>n>>sum;
		unsigned long int *arr=new unsigned long int[n];
		for(int i=0;i<n;i++)
		{
			std::cin>>arr[i];
		}
		Subarray(arr,n,sum);
	}
	return 0;
}
