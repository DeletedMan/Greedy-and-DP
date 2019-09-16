#include<iostream>
#include<bits/stdc++.h>
#include<stack>
#include<queue>
#include<deque>
using namespace std;

int coinExchange(int arr[],int m,int n)
{
	int i,j,x,y;
	int table[n+1][m];
	for(i=0;i<m;i++)
	{
		table[0][i]=1;
	}
	for (i = 1; i < n + 1; i++) 
    { 
        for (j = 0; j < m; j++) 
        { 
            x = (i-arr[j] >= 0) ? table[i - arr[j]][j] : 0; 
            y = (j >= 1) ? table[i][j - 1] : 0; 
            table[i][j] = x + y; 
        } 
    } 
    return table[n][m - 1]; 
}
// This is recursive solution..O(k^n).

int main()
{
	int test;
	std::cin>>test;
	while(test--)
	{
		int n;
		std::cin>>n;
		int *arr=new int[n];
		for(int i=0;i<n;i++)
		{
			std::cin>>arr[i];
		}
		int c;
		std::cin>>c;
		std::cout<<coinExchange(arr,n,c)<<endl;
	}
	return 0;
}
