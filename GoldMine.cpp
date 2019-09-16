#include<iostream>
#include<bits/stdc++.h> 
using namespace std; 

i
int main()
{
	int test;
	std::cin>>test;
	while(test--)
	{
		int n,m;
		std::cin>>n>>m;
		int mat[n][m];
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<m;j++)
			{
				std::cin>>mat[i][j];
			}
		}
		std::cout<<goldMine(mat,m,n)<<endl;
	}
	return 0;
}
