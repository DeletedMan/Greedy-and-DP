#include<iostream>
#include<bits/stdc++.h>
#include<stack>
#include<list>
#include<set>
#include<map>

using namespace std;
int min(int a,int b,int c)
{
	return min(min(a,b),c);
}

int main()
{
	int test;
	std::cin>>test;
	while(test--)
	{
		int n,i,j;
		std::cin>>n;
		int arr[n][n];
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<n;j++)
			{
				std::cin>>arr[i][j];
			}
		}
		int temp[n][n];
		temp[0][0]=arr[0][0];
		for(i=1;i<n;i++)
		{
			temp[i][0]=temp[i-1][0]+arr[i][0];
		}
		for(j=1;j<n;j++)
		{
			temp[0][j]=temp[0][j-1]+arr[0][j];
		}
		for(i=1;i<n;i++)
		{
			for(j=1;j<n;j++)
			{
				temp[i][j]=min(temp[i-1][j-1],temp[i][j-1],temp[i-1][j])+arr[i][j];
			}
		}
		std::cout<<temp[n-1][n-1]<<endl;
	}
	return 0;
}
