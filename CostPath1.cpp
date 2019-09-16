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
		int max=arr[0][0];
		int index_i=0,index_j=0;
		for(i=0;i<n;i++)
		{
			if(arr[0][i]>max)
			{
				max=arr[0][i];
				index_i=0;
				index_j=i;
			}
		}
		int max_cost_path=max;
		while(index_i<n)
		{
			if(index_j+1=n)
			{
				max_cost_path+=max(arr[index_i+1][index_j-1],arr[index_i+1][index_j]);
				index_i++;
			}
			else if(index_j+1!=n && index_j-1<0)
		}
	}
}
