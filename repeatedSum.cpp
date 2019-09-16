#include<iostream>
#include<bits/stdc++.h>
#include<stack>
#include<queue>
#include<deque>

using namespace std;

unsigned long int repeatedSum(unsigned long int n)
{
	unsigned long int sum=0;
	if(n<10)
	{
		return n;
	}
	else
	{
		unsigned long int temp=n;
		while(temp!=0)
		{
			sum=sum+temp%10;
			temp=temp/10;
			if(temp==0 && sum>9)
			{
				temp=sum;
				sum=0;
			}
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
		unsigned long int n;
		std::cin>>n;
		std::cout<<repeatedSum(n)<<endl;
	} 
	return 0;
}

