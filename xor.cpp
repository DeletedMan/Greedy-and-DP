#include<iostream>
#include<bits/stdc++.h>
#include<stack>
#include<set>
#include<map>
#include<algorithm>
#include<list>

using namespace std;

int missing_number(int arr[],int n)
{
	int i;
	int xor_1=0,xor_2=0;
	for(i=1;i<=n;i++)
	{
		xor_1=xor_1^i;
	}
	//Now i m going to print missing number result
	int size=sizeof(arr)/sizeof(arr[0]);
	for(i=0;i<size;i++)
	{
		xor_2=xor_2^arr[i];
	}
	return (xor_1 ^ xor_2);
}
//This is my own version of the code....I am fucking beast

int main()
{
	int test;
	std::cin>>test;
	while(test--)
	{
		int n;
		std::cin>>n;
		int *arr=new int[n-1];
		for(int i=0;i<n-1;i++)
		{
			std::cin>>arr[i];
		}
		std::cout<<missing_number(arr,n)<<endl;
	}
	return 0;
}
