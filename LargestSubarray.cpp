#include<iostream>
#include<bits/stdc++.h>
#include<stack>
#include<list>
#include<set>
#include<map>

using namespace std;

int largestSubarray(int arr[],int n)
{
	
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
		std::cout<<largestSubarray(arr,n)<<endl;
	}
	return 0;
}
