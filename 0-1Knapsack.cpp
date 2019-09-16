#include<iostream>
#include<bits/stdc++.h>
#include<stack>
#include<queue>
#include<deque>
#include<list>
#include<map>
#include<set>
using namespace std;

int max(int a,int b)
{
	return (a>b?a:b);
}
/*
int _01Knapsack(int wt[],int price[],int n,int c)
{
	int dp[n+1][c+1];
	int i,j;
	for(i=0;i<=c;i++)
	{
		dp[0][i]=0;
	}
	for(j=0;j<=n;j++)
	{
		dp[j][0]=0;
	}
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=c;j++)
		{
			if(wt[i-1]<=j)
			{
				dp[i][j]=max(price[i-1]+dp[i-1][j-wt[i-1]],dp[i-1][j]);
			}
			else
			{
				dp[i][j]=dp[i-1][j];
			}
		}
	}
	return dp[n][c];
}
*/

int _01Knapsack(int W,int wt[],int val[],int n) 
{ 
int i, w; 
int K[n+1][W+1];  
for (i = 0; i <= n; i++) 
{ 
	for (w = 0; w <= W; w++) 
	{ 
		if (i==0 || w==0) 
			K[i][w] = 0; 
		else if (wt[i-1] <= w) 
				K[i][w] = max(val[i-1] + K[i-1][w-wt[i-1]], K[i-1][w]); 
		else
				K[i][w] = K[i-1][w]; 
	} 
} 
return K[n][W]; 
}

int main()
{
	int test;
	std::cin>>test;
	while(test--)
	{
		int n,w,i;
		std::cin>>n;
		std::cin>>w;
		int *wt=new int[n];
		int *price=new int[n];
		for(i=0;i<n;i++)
		{
			std::cin>>wt[i];
		}
		for(i=0;i<n;i++)
		{
			std::cin>>price[i];
		}
		std::cout<<_01Knapsack(w,wt,price,n)<<endl;
	}
	return 0;
}
  
