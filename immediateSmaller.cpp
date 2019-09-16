#include<iostream>
#include<bits/stdc++.h>
#include<list>
#include<stack>
#include<queue>
#include<deque>

using namespace std;

void immediateSmaller(int arr[],unsigned long long n)
{
	int i;
	for(i=0;i<n;i++)
	{
		if(arr[i+1]<arr[i] && i!=n-1)
		{
			std::cout<<arr[i+1]<<" ";
		}
		else if(i==n-1)
		{
			std::cout<<"-1";
		}
		else
		{
			std::cout<<"-1"<<" ";
		}
	}
}

int main()
{
	int test;
	std::cin>>test;
	while(test--)
	{
		unsigned long long n;
		std::cin>>n;
		int arr[n];
		for(int i=0;i<n;i++)
		{
			std::cin>>arr[i];
		}
		immediateSmaller(arr,n);
		std::cout<<endl;
	}
	return 0;
}
