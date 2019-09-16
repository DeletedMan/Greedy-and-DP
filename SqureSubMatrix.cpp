#include<iostream>
#include<bits/stdc++.h>
#include<map>
#include<set>
#include<algorithm>
#include<stack>
#define R 6
#define C 5
using namespace std;

int main()
{
	int test,i,j;
	std::cin>>test;
	while(test--)
	{
		int m,n;
		std::cin>>m>>n;
		int mat[m][n],res[m+1][n+1];
		for(i=0;i<n;i++)
		{
			res[0][i]=mat[0][i];
		}
		for(j=0;j<m;j++)
		{
			res[j][0]=mat[j][0];
		}
		for(i=1;i<m;i++)
		{
			for(j=1;j<n;j++)
			{
				if(mat[i][j]==1)
				{
					res[i][j]=1+min(res[i-1][j],res[i-1][j-1],res[i][j-1]);
				}
				else
				{
					res[i][j]=0;
				}
			}
		}
		int max=res[i][j];
		for(i=0;i<m;i++)
		{
			for(j=0;j<n;j++)
			{
				if(max>res[i][j])
				{
					max=res[i][j];
				}
			}
		}
	}
	std::cout<<max<<endl;
	return 0;
}
