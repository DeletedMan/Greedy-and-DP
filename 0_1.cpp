#include<iostream>
#include<bits/stdc++.h>
#include<cmath>
#include<stack>
#include<map>
#include<set>

using namespace std;

int lengthOf(int arr[],int start,int end,int k)
{
	if(end>=start)
	{
		int mid=start+(end-start)/2;
		if(arr[mid]==k)
		{
			if(arr[mid-1]==0 && arr[mid+1]==1)
			{
				return mid;
			}
			if(arr[mid-1]==1)
			{
				return lengthOf(arr,start,mid-1,k);
			}
		}
		else if(arr[mid]==0)
		{
			if(arr[mid+1]==1)
			{
				return mid;
			}
			if(arr[mid+1]==0)
			{
				return lengthOf(arr,mid+1,end,k);
			}	
		}
	}
}

int lengthOfUtil(int arr[],int start,int end,int n)
{
	if(end>=start)
	{
		int mid=start+(end-start)/2;
		if(arr[mid]==1 && mid==n-1)
		{
			return mid;
		}
		else if(arr[mid]==1 && (mid+1)!=n-1)
		{
			return lengthOfUtil(arr,mid+1,end,n-1);	
		}
		else if(arr[mid]==0)
		{
			return lengthOfUtil(arr,mid+1,end,n-1);
		}
	}
	return -1;
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
		int start_index=lengthOf(arr,0,n-1,1);
		int last_index=lengthOfUtil(arr,0,n-1,n);
		std::cout<<last_index-start_index+1<<endl;
	}
	return 0;
}
