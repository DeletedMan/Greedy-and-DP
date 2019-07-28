#include<stdio.h>
#include<stdlib.h>

int max(int a,int b)
{
	return(a>b?a:b);
}

int lcs(char *str1,char *str2,int m,int n)
{
	if(m==0 || n==0)
	{
		return 0;
	}
	if(str1[n-1]==str2[m-1])
	{
		return(1+lcs(str1,str2,m-1,n-1));
	}
	else
	{
		return max(lcs(str1,str2,m-1,n),lcs(str1,str2,m,n-1));
	}
}

int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n,m;
		scanf("%d %d",&n,&m);
		char str1[n],str2[m];
		printf("Enter the first string:\n");
		scanf("%s",str1);
		printf("Enter the second string:\n");
		scanf("%s",str2);
		printf("The Longest common subsequence is:\n");
		printf("%d ",lcs(str1,str2,n,m));
	}
	return 0;
}
