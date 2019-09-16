#include<iostream>
#include<bits/stdc++.h>
#include<cmath>
#include<stack>
#include<map>
#include<set>

using namespace std;

int _TappedWater(int arr[],int n)
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
		std::cout<<_TappedWater(arr,n)<<endl;
	}
	return 0;
}
