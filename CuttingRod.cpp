#include<iostream>
#include<bits/stdc++.h>
#include<stack>
#include<list>
#include<set>
#include<map>

using namespace std;

int CuttingRod(int price[],int n)
{
	int dp[n+1];
	dp[0]=0;
	int i,j;
	int max_Value=INT_MIN;
	for(i=1;i<=n;i++)
	{
		for(j=0;j<i;j++)
		{
			max_Value=max(max_Value,price[j]+dp[i-j-1]);
		}
		dp[i]=max_Value;
	}
	return dp[n];
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
		std::cout<<CuttingRod(arr,n)<<endl;
	}
	return 0;
}
