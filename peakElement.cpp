#include<iostream>
#include<bits/stdc++.h>
#include<cmath>
#include<stack>
#include<map>
#include<set>

using namespace std;

int peakElementUtil(int arr[],int size,int start,int end)
{
	if(end>=start)
	{
		int mid=start+(end-start)/2;
		if((mid==0 || arr[mid-1]<arr[mid]) && (mid==size-1 || arr[mid+1]<arr[mid]))
		{
			return mid;
		}
		else if(arr[mid+1]>arr[mid])
		{
			return peakElementUtil(arr,size,mid+1,end);
		}
		else if(arr[mid-1]>arr[mid])
		{
			return peakElementUtil(arr,size,start,mid-1);
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
		if(peakElementUtil(arr,n,0,n-1))
		{
			std::cout<<"1"<<endl;
		}
		else
		{
			std::cout<<"0"<<endl;
		}
	}
	return 0;
}
