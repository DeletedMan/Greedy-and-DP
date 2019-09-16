#include<iostream>
#include<bits/stdc++.h>
#include<cmath>
#include<stack>
#include<map>
#include<set>

using namespace std;

int rotation(int arr[],int n)
{
	int arr1[n];
	for(int i=0;i<n;i++)
	{
		arr1[i]=arr[i];
	}
	
}

int main()
{
	int test;
	std::cin>>test;
	while(test--)
	{
		unsigned long int n;
		std::cin>>n;
		unsigned long long int *arr=new unsigned long long int[n];
		for(int i=0;i<n;i++)
		{
			std::cin>>arr[i];
		}
		std::cout<<rotation(arr,n)<<endl;
	}
	return 0;
}
