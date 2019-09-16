#include<iostream>
#include<bits/stdc++.h>
#include<stack>
#include<queue>
#include<deque>
using namespace std;

int newmanShank(int n)
{
	int dp[n+1];
	dp[0]=1;
	dp[1]=1;
	for(int i=2;i<=n;i++)
	{
		dp[i]=2*dp[i-1]+dp[i-2];
	}
	return dp[n];
}
//Fucking off..coding done..
int main()
{
	int test;
	std::cin>>test;
	while(test--)
	{
		int n;
		std::cin>>n;
		std::cout<<newmanShank(n)<<endl;
	}
	return 0;
}
