#include<iostream>
#include<bits/stdc++.h>
#include<stack>
#include<list>
#include<set>
#include<map>

using namespace std;

int main()
{
	int test;
	std::cin>>test;
	while(test--)
	{
		int n;
		std::cin>>n;
		int x,y,z;
		int arr[3];
		std::cin>>x>>y>>z;
		arr[0]=x;
		arr[1]=y;
		arr[2]=z;
		int dp[4][n+1];
		for(int i=0;i<4;i++)
		{
			for(int j=0;j<n+1;j++)
			{
				dp[i][j]=0;
			}
		}
		for(int i=0;i<4;i++)
	    {
	        dp[i][0]=0;
	    }
	     for(int i=0;i<n+1;i++)
	    {
	        dp[0][i]=0;
	    }
	    
	    for(int i=1;i<4;i++)
	    {
	        for(int j=1;j<n+1;j++)
	        {
	            if(arr[i-1]>j)
	            {
	                dp[i][j]=dp[i-1][j];
	            }
	           else if(arr[i-1]==j)
	           {
	               dp[i][j]=max(dp[i-1][j],1);
	           }
	           else if(arr[i-1]<j)
	           {
	               int k=dp[i][j-arr[i-1]];
	               if(k)
	               {
	                   k=k+1;
	               }
	               
	              dp[i][j]=max(k,dp[i-1][j]);
	               
	           }
	          
	        }
	    }
	    std::cout<<dp[3][n];
	    std::cout<<endl;
	}
	return 0;
}
