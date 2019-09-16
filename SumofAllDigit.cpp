#include<iostream>
#include<bits/stdc++.h>
#include<stack>
#include<queue>
#include<deque>

using namespace std;

int fuckingBeast(int n)
{
	if(n<10)
	{
		return (n*(n+1)/2);
	}
	int d=log10(n);
	//std::cout<<d<<endl;
	int *arr=new int[d+1];
	arr[0]=0,arr[1]=45;
	for(int i=2;i<=d;i++)
	{
		arr[i]=arr[i-1]*10+45*ceil(pow(10,i-1));
		
	}
	int p=ceil(pow(10,d));
	int msb=n/p;
	return msb*arr[d]+(msb*(msb-1)/2)*p+msb*(1+n%p)+fuckingBeast(n%p);
}
int main()
{
	int test;
	std::cin>>test;
	while(test--)
	{
		int n;
		std::cin>>n;
		std::cout<<fuckingBeast(n)<<endl;
	}
	return 0;
}
