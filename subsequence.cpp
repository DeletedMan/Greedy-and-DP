#include<iostream>
#include<bits/stdc++.h>
#include<stack>
#include<queue>
#include<deque>
#include<list>
#include<map>
#include<set>
using namespace std;

int subsequence(string str1,string str2,int m,int n)
{
	//int m=str1.length();
	//int n=str2.length();
	//std::cout<<m<<" "<<n<<endl;
	int dp[m+1][n+1];
	int i,j;
	for(i=0;i<=n;i++)
	{
		dp[0][i]=0;
	}
	for(i=0;i<=m;i++)
	{
		dp[i][0]=0;
	}
	for(i=1;i<=m;i++)
	{
		for(j=1;j<=n;j++)
		{
			if(str1[i-1]==str2[j-1])
			{
				dp[i][j]=1+dp[i-1][j-1];
			}
			else
			{
				dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
			}
		}
	}/*
	if(dp[m][n]==m)
	{
		return 1;
	}
	else
	{
		return 0;
	}*/
	return dp[m][n];
}

int main()
{
	int test;
	std::cin>>test;
	while(test--)
	{
		int n,m;
		std::cin>>m>>n;
		string str1,str2;
		std::cin>>str1>>str2;
		std::cout<<subsequence(str1,str2,m,n)<<endl;
	}
	return 0;
}
