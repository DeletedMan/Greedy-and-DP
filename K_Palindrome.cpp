#include<bits/stdc++.h>
using namespace std;

int isKPalRec(string str1,string str2,int m,int n)
{
	if(m==0)
	{
		return n;
	}
	if(n==0)
	{
		return m;
	}
	if(str1[m-1]==str2[n-1])
	{
		isKPalRec(str1,str2,m-1,n-1);
	}
	return(1+min(isKPalRec(str1,str2,m-1,n),isKPalRec(str1,str2,m,n-1)));
}

bool isKPal(string str,int k)
{
	string revStr=str;
	reverse(revStr.begin(),revStr.end());
	int len=str.length();
	return(isKPalRec(str,revStr,len,len));
}

int main()
{
	string str="acdcb";
	int k=2;
	printf("Desire output is:\n");
	isKPal(str,k)?cout<<"YES":cout<<"No";
	return 0;
}
