#include<iostream>
#include<bits/stdc++.h>
#include<stack>
#include<list>
#include<set>
#include<map>

using namespace std;

void rotatebyd(int arr[],int n,int d)
{
	int temp;
	int i;
	for(i=0;i<d;i++)
	{
		temp=arr[0];
		for(int j=0;j<n;j++)
		{
			arr[j]=arr[j+1];
		}
		arr[n-1]=temp;
	}
	for(i=0;i<n;i++)
	{
		std::cout<<arr[i]<<" ";
	}
	return;
}

int main()
{
	int test;
	std::cin>>test;
	while(test--)
	{
		int n,d;
		std::cin>>n>>d;
		int arr[n];
		for(int i=0;i<n;i++)
		{
			std::cin>>arr[i];
		}
		rotatebyd(arr,n,d);
		std::cout<<endl;
	}
	return 0;
}
