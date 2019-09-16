#include<iostream>
#include<bits/stdc++.h>
#include<stack>
#include<queue>

using namespace std;

int main()
{
	int test;
	std::cin>>test;
	while(test--)
	{
		int n;
		std::cin>>n;
		int arr[n][n],res[n][n];
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<n;j++)
			{
				std::cin>>arr[i][j];
			}
		}
		int table[n][n]={0,0};
		for(int i=n-1;i>=0;i--)
		{
			for(int j=0;j<n;j--)
			{
				if(i==n-1)
				{
					table[i][j]=arr[i][j];
				}
				else
				{
					if(j-1>=0 && j+1<n)
					  table[i][j]=arr[i][j]+max(table[i+1][j],max(table[i+1][j-1],table[i+1][j+1]));
				    else if(j-1>=0)
					  table[i][j]=arr[i][j]+max(table[i+1][j],table[i+1][j-1]);
				    else
					  table[i][j]=arr[i][j]+max(table[i+1][j],table[i+1][j+1]);
		        }
	    	}
    	}
		int max_sum=INT_MIN;
		for(int k=0;k<n;k++)
		{
			max_sum=max(table[0][k],max_sum);
		}
	}
	return 0;
}
