#include<iostream>
#include<bits/stdc++.h>
#include<stack>
#include<queue>

using namespace std;

unsigned long int _EquiIndex(unsigned long int arr[],unsigned long int n)
{
	unsigned long int index,sum=0,leftsum=0;
	unsigned long int flag=0,i;
	for(i=0;i<n;i++)
	{
		sum+=arr[i];
	}
	for(i=0;i<n;i++)
	{
		sum=sum-arr[i];
		if(sum==leftsum)
		{
			flag=1;
			return (i+1);
		}
		leftsum=leftsum+arr[i];
	}
	if(flag==0)
	{
		return -1;
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
		unsigned long int *arr=new unsigned long int[n];
		for(int i=0;i<n;i++)
		{
			std::cin>>arr[i];
		}
		std::cout<<_EquiIndex(arr,n)<<endl;
	}
	return 0;
}
