#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int max(int a,int b)
{
	return(a>b?a:b);
}

int LongesPalindromicSubsequence(char *str1,char* str2,int m,int n)
{
	int dp[m+1][n+1];
	for(int i=0;i<=m;i++)
	{
		for(int j=0;j<=n;j++)
		{
			if(i==0 || j==0)
			{
				dp[i][j]=0;
			}
			else if(str1[i]==str2[j])
			{
				dp[i][j]=1+dp[i-1][j-1];
			}
			else
			{
				dp[i][j]=max(dp[i][j-1],dp[i-1][j]);
			}
		}
	}
	return dp[m][n];
}

char *reverse(char* str,int m)
{
	char swap;
	int i;
	for(i=0;i<m/2;i++)
	{
		swap=*(str+i);
		*(str+i)=*(str+m-1-i);
		*(str+m-1-i)=swap;
	}
	return str;
}

int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n;
		scanf("%d",&n);
		char *str1=(char*)malloc(sizeof(char)*n);
		scanf("%s",str1);
		int m=strlen(str1);
		char *str2=reverse(str1,m);
		int len=strlen(str2);
		int t=LongesPalindromicSubsequence(str1,str2,m,len);
		printf("%d\n",t);
	}
	return 0;
}
