#include<iostream>
#include<bits/stdc++.h>
#include<cmath>
#include<cstring>
#include<queue>
#include<deque>

using namespace std;

int fbi_Agent(string str,int n)
{
	if(n==1 || n==0)
	{
		return 1;
	}
	if(str[0]=='0')
	{
		return 0;
	}
	int count=0;
	if(str[n-1]>'0')
	{
		count=fbi_Agent(str,n-1);
	}
	if(str[n-2]=='1' || (str[n-2]=='2' && str[n-1]<'7'))
	{
		count+=fbi_Agent(str,n-2);
	}
	return count;
}

int main()
{
	int test;
	std::cin>>test;
	while(test--)
	{
		int n;
		std::cin>>n;
		string str;
		std::cin>>str;
		std::cout<<fbi_Agent(str,n)<<endl;
	}
	return 0;
}
