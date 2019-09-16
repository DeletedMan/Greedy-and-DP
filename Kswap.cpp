#include<iostream>
#include<bits/stdc++.h>
#include<stack>
#include<queue>
#include<deque>
#include<list>
#include<map>
#include<set>
using namespace std;

void kswap(string str,int k,string& max)
{
	int i,j;
	if(k==0)
	{
		return;
	}
	int n=str.length();
	for(i=0;i<n-1;i++)
	{
		for(j=i+1;j<n;j++)
		{
			if(str[i]<str[j])
			{
				swap(str[i],str[j]);
				if(str.compare(max)>0)
				{
					max=str;
				}
				kswap(str,k-1,max);
				swap(str[i],str[j]);
		    }
	     }
     }
}

int main()
{
	int test;
	std::cin>>test;
	while(test--)
	{
		int k;
		std::cin>>k;
		string str;
		std::cin>>str;
		string max=str;
		kswap(str,k,max);
		std::cout<<max<<endl;
	}
	return 0;
}
