#include<iostream>
#include<bits/stdc++.h>
#include<stack>
#include<deque>
#include<queue>
#define mod 1000000007
using namespace std;
/*
int fence(int n,int k)
{
	if(n==1)
	{
		return k;
	}
	if(n==2)
	{
		return k*k;
	}
	if(k<2)
	{
		return 0;
	}
	if(n==3)
	{
		return k*((k-1)+(k-1)*k);
	}
	else
	{
		k*fence(n-1,k)-fence(n-3,k)*(k-1);
	}
}*/
/*
int fence(int n,int k)
{
    int dp[n+1];
    dp[0]=k,dp[1]=k*k,dp[2]=k*((k-1)+(k-1)*k);
    if(k<2)
    {
        return 0;
    }
    for(int i=3;i<=n;i++)
    {
        dp[i]=k*dp[i-1]-dp[i-3]*(k-1);
    }
    return dp[n];
}*/

long fence(int n,int k)
{
	long dp[n+1];
	memset(dp,0,sizeof(dp));
	dp[1]=k;
	int same=0,diff=k;
	for(int i=2;i<=n;i++)
	{
		same=diff;
		diff=(dp[i-1]*(k-1))%mod;
		dp[i]=(same+diff)%mod;
	}
	return dp[n];
}
int main()
{
	int test;
	std::cin>>test;
	while(test--)
	{
		long n,k;
		std::cin>>n>>k;
		std::cout<<fence(n,k)<<endl;
	}
	return 0;
}
