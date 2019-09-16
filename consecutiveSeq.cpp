#include<iostream>
#include<bits/stdc++.h>
#include<stack>

using namespace std;

int consecutive(int arr[],int n)
{
	int i,ans=0;
	unordered_set<int>hash;
	for(i=0;i<n;i++)
	{
		hash.insert(arr[i]);
	}
	for(i=0;i<n;i++)
	{
		if(hash.find(arr[i]-1)==hash.end())
		{
			int j=arr[i];
			while(hash.find(j)!=hash.end())
			{
				j++;
			}
			ans=max(ans,j-arr[i]);
		}
	}
	return ans;
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
		std::cout<<consecutive(arr,n)<<endl;
	}
	return 0;
}
