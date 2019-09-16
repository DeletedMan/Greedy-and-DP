#include<iostream>
#include<bits/stdc++.h>
#include<stack>
#define mod 1000003
using namespace std;

int chainReaction(unsigned long long int n,unsigned long long x)
{
    unsigned long long int prev=x;
    int i;
    for(i=1;i<=n;i++)
    {
        prev=(prev*i)%mod;
    }
    return prev;
}
int main()
{
	unsigned long int test;
	std::cin>>test;
	while(test--)
	{
		unsigned long long int n,x;
		std::cin>>n>>x;
		std::cout<<chainReaction(n,x)<<endl;
	}
	return 0;
}
