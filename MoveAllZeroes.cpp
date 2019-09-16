#include<iostream>
#include<bits/stdc++.h>
#include<cmath>
#include<stack>
#include<map>
#include<set>

using namespace std;

void MoveAllZeroes(int arr[],int n)
{
	int count=0,count1=0,i;
	vector<int>vect1,vect2;
	for(i=0;i<n;i++)
	{
		if(arr[i]!=0)
		{
			count++;
			vect1.push_back(arr[i]);
		}
		else
		{
			count1++;
			vect2.push_back(arr[i]);
		}
	}
	for(i=0;i<count;i++)
	{
		std::cout<<vect1[i]<<" ";
	}
	for(i=0;i<count1;i++)
	{
		std::cout<<vect2[i]<<" ";
	}
	return;
}

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
		MoveAllZeroes(arr,n);
		std::cout<<"\n";
	}
	return 0;
}
