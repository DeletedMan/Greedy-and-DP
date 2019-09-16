#include<iostream>
#include<bits/stdc++.h>
#include<stack>
#include<queue>
#include<deque>

using namespace std;

void printArray(int arr[],int n)
{
	int i;
	for(i=0;i<n;i++)
	{
		std::cout<<arr[i]<<" ";
	}
	std::cout<<"\n";
	return;
}

int fuckingGirl(int temp[],int n)
{
	if(n==1)
	{
		return temp[0];
	}
	int k=0;
	int arr[n/2];
	for(int i=0;i<n;i++)
	{
		if(i%2)
		{
			arr[k++]=temp[i];
		}
	}
	for(i=0;i<n/2;i++)
	{
		temp[i]=arr[i];
	}
	std::cout<<"I want to see the result"<<endl;
	printArray(temp,sizeof(arr)/sizeof(arr[0]));
	return fuckingGirl(arr,n/2);
}
int fibEasy(int n)
{
	int dp[n+1];
	dp[0]=1;
	dp[1]=1;
	for(int i=2;i<=n;i++)
	{
		dp[i]=dp[i-1]+dp[i-2];
	}
	int temp[n+1];
	int fuck;
	for(int j=0;j<=n;j++)
	{
		fuck=dp[j];
		temp[j]=fuck%10;
	}
	int size=sizeof(temp)/sizeof(temp[0]);
	return fuckingGirl(temp,size);
}

int main()
{
	int test;
	std::cin>>test;
	while(test--)
	{
		unsigned long long int n;
		std::cin>>n;
		std::cout<<fibEasy(n)<<endl;
	}
	return 0;
}
