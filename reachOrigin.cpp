#include<iostream>
#include<bits/stdc++.h>
#include<stack>
#include<queue>
#include<deque>

using namespace std;

int reachOrigin(int n,int m)
{
	int i,j;
	int dp[n+1][m+1];
	memset(dp,0,sizeof(dp));
	for(i=0;i<=n;i++)
	{
		dp[i][0]=1;
	}
	for(i=0;i<=m;i++)
	{
		dp[0][i]=1;
	}
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=m;j++)
		{
			dp[i][j]=dp[i-1][j]+dp[i][j-1];
		}
	}
	return dp[n][m];
}

int main()
{
	int test;
	std::cin>>test;
	while(test--)
	{
		int n,m;
		std::cin>>n>>m;
		std::cout<<reachOrigin(n,m)<<endl;
	}
	return 0;
}
