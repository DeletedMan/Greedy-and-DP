#include<iostream>
#include<bits/stdc++.h>
#include<stack>
#include<queue>
#include<deque>

using namespace std;

unsigned long int reachToNumber(unsigned long int n)
{
	int count=0;
	while(n>0)
	{
		if(n&1)
		{
			n=n-1;
		}
		else
		{
			n=n/2;
		}
		count++;
	}
	return count;
}
int main()
{
	int test;
	std::cin>>test;
	while(test--)
	{
		unsigned long int n;
		std::cin>>n;
		std::cout<<reachToNumber(n)<<endl;
	}
	return 0;
}
