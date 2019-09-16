#include<iostream>
#include<bits/stdc++.h>
#include<stack>
#include<queue>
#include<deque>
#include<list>
#include<map>
#include<set>
using namespace std;

int frogJumping(int n)
{
	int dp[n+1];
	dp[0]=0;
	dp[1]=1;
	dp[2]=2;
	dp[3]=4;
	for(int i=4;i<=n;i++)
	{
		dp[i]=dp[i-1]+dp[i-2]+dp[i-3];
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
		std::cout<<frogJumping(n)<<endl;
	}
	return 0;
}
