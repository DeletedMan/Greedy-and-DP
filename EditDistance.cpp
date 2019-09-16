#include<iostream>
#include<bits/stdc++.h>
#include<stack>
#include<map>
#include<set>
#include<algorithm>
using namespace std;

int min(int a,int b,int c)
{
	return(min(a,min(b,c)));
}

int EditDistance(char *str1,char *str2,int m,int n)
{
	if(m==0)
	{
		return n;
	}
	if(n==0)
	{
		return m;
	}
	if(str1[m-1]=str2[n-1])
	{
		return EditDistance(str1,str2,m-1,n-1);
	}
	else
	{
		return 1+min(EditDistance(str1,str2,m-1,n-1),EditDistance(str1,str2,m-1,n),EditDistance(str1,str2,m,n-1));
	}
}

int main()
{
	int test;
	std::cin>>test;
	while(test--)
	{
		int m,n;
		std::cin>>m>>n;
		char str1[m];
		char str2[n];
		std::cin>>str1>>str2;
		std::cout<<EditDistance(str1,str2,m,n)<<endl;
	}
	return 0;
}
