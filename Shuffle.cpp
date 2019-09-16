#include<iostream>
#include<bits/stdc++.h>
#include<stack>
using namespace std;

void shuffle(unsigned long long int arr[],unsigned long int start,unsigned long int end)
{
	if(end<start)
	{
		return;
	}
        if(end-start==1)
        {
            return;
        }
        int mid=(start+end)/2;
        int temp=mid+1;
        int mmid=(start+mid)/2;
        for(int i=mmid+1;i<=mid;i++)
        {
            swap(arr[i],arr[temp++]);
        }
        shuffle(arr,start,mid);
        shuffle(arr,mid+1,end);
}

void printArray(unsigned long long int arr[],unsigned long int n)
{
	int i;
	for(i=0;i<n;i++)
	{
		std::cout<<arr[i]<<" ";
	}
	std::cout<<endl;
}

int main() 
{
	int test;
	std::cin>>test;
	while(test--)
	{
	    unsigned long int n;
	    std::cin>>n;
	    unsigned long long int *arr=new unsigned long long int[n];
	    for(int i=0;i<n;i++)
	    {
	        std::cin>>arr[i];
	    }
	    shuffle(arr,0,n-1);
	    printArray(arr,n);
	}
	return 0;
}
