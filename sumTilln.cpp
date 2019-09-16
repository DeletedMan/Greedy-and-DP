#include<iostream>
#include<bits/stdc++.h>
#include<stack>
#include<queue>
#include<deque>

using namespace std;

int SumofAllDigit(int n)
{
	int i,sum=0;
	for(i=1;i<=n;i++)
	{
		int temp=i;
		while(temp!=0)
		{
			sum=sum+temp%10;
			temp=temp/10;
		}
	}
	return sum;
}

int main()
{
	int test;
	std::cin>>test;
	while(test--)
	{
		int n;
		std::cin>>n;
		std::cout<<SumofAllDigit(n)<<endl;
	}
	return 0;
}
