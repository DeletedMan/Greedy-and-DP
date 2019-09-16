#include<iostream>
#include<bits/stdc++.h> 
using namespace std; 
int min(int x, int y, int z) 
{ 
	return min(min(x, y), z); 
} 

int EditDistance(char *str1,char *str2, int m, int n) 
{ 
	int dp[m+1][n+1]; 
	for (int i=0; i<=m; i++) 
	{ 
		for (int j=0; j<=n; j++) 
		{ 
			if (i==0) 
				dp[i][j] = j;
			else if (j==0) 
				dp[i][j] = i;
			else if (str1[i-1] == str2[j-1]) 
				dp[i][j] = dp[i-1][j-1]; 
			else
				dp[i][j] = 1 + min(dp[i][j-1], 
								dp[i-1][j], 
								dp[i-1][j-1]);
		} 
	} 

	return dp[m][n]; 
} 

int main()
{
	int test;
	std::cin>>test;
	while(test--)
	{
		int n,m;
		std::cin>>n>>m;
		char str1[n],str2[m];
		std::cin>>str1>>str2;
		std::cout<<EditDistance(str1,str2,m,n)<<endl;
	}
	return 0;
}
