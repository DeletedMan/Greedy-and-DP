#include<iostream>
#include<bits/stdc++.h>
#include<stack>
using namespace std;

int wayToScore(int n)
{
	int i;
	int dp[n/2+1];
	dp[0]=1;
	dp[1]=1;
	dp[2]=2;
	for(i=3;i<(n/2+1);i++)
	{
		dp[i]=dp[i-1]+dp[i-2]+dp[i-3];
	}
	return dp[i-1];
}

int main()
{
	int test;
	std::cin>>test;
	while(test--)
	{
		int n;
		std::cin>>n;
		std::cout<<wayToScore(n)<<endl;
	}
	return 0;
}

