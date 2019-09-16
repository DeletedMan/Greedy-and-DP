#include<iostream>
#include<bits/stdc++.h>
#include<cmath>
#include<stack>
#include<map>
#include<set>

using namespace std;

void MaxHeapify(long long int arr[],unsigned long int n,int index)
{
	int left=2*index+1;
	int right=2*index+2;
	int largest=index;
	if(left<n && arr[left]>arr[index])
	{
		largest=left;
	}
	if(right<n && arr[right]>arr[largest])
	{
		largest=right;
	}
	if(largest!=index)
	{
		swap(arr[largest],arr[index]);
		MaxHeapify(arr,n,largest);
	}
	return;
}
int tgc(long long int arr[],unsigned long int n)
{
	for(int i=(n/2)-1;i>=0;i--)
	{
		MaxHeapify(arr,n,i);
	}
	int prod=arr[0]*arr[1]*arr[2];
	return prod;
}
int main()
{
	int test;
	std::cin>>test;
	while(test--)
	{
		unsigned long int n;
		std::cin>>n;
		long long int *arr=new long long int[n];
		for(int i=0;i<n;i++)
		{
			std::cin>>arr[i];
		}
		std::cout<<tgc(arr,n)<<endl;
	}
	return 0;
}
