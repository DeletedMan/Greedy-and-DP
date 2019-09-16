#include<iostream>
#include<bits/stdc++.h>
#include<stack>
#include<queue>
#include<deque>
#include<list>
#include<map>
#include<set>
using namespace std;

int findMin(int arr[],int n,int sum,int m)
{
	/*int sum=0;
	for(int i=0;i<n;i++)
	{
		sum+=arr[i];
	}*/
	if(n>m)
	{
		return 1;
	}
	int dp[n+1][sum+1];
	int i,j;
	for(i=0;i<=sum;i++)
	{
		if(i==0)
		{
			dp[0][i]=1;
		}
		else
		{
			dp[0][i]=0;
		}
	}
	for(i=0;i<=n;i++)
	{
		dp[i][0]=1;
	}
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=sum;j++)
		{
			if(arr[i-1]>j)
			{
				dp[i][j]=dp[i-1][j];
			}
			else if(j>=arr[i-1])
			{
				dp[i][j] =dp[i-1][j-arr[i-1]] + dp[i-1][j];
			}
		}
	}/*
	for(i=0;i<=n;i++)
	{
		for(j=0;j<=sum;j++)
		{
			std::cout<<dp[i][j]<<" ";
		}
		std::cout<<endl;
	}*/
	/*int diff=INT_MAX;
	for(int j=sum/2;j>=0;j--)
	{
		if(dp[n][j]==true)
		{
			diff=sum-2*j;
			break;
		}
	}
	return diff;*/
	//return dp[n][sum];
	int flag=0;
	for(int i=0;i<=n;i++)
	{
		if(dp[i][m]==1)
		{
			flag=1;
			break;
		}
	}
	if(flag==1)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

int main()
{
	int test,sum=0;
	std::cin>>test;
	while(test--)
	{
		int n,m;
		std::cin>>n>>m;
		int *arr=new int[n];
		for(int i=0;i<n;i++)
		{
			std::cin>>arr[i];
			sum+=arr[i];
		}
		
		std::cout<<findMin(arr,n,sum,m)<<endl;
	}
	return 0;
}

