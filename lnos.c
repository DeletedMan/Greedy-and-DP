#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int lnos(char* str,int n)
{
	int dp[n+1][n+1];
	int i;
	for(i=0;i<n;i++)
	{
		dp[i][i]=0;
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=0;j<n-i+1;j++)
		{
			int k=i+j;
			if(str[j]==str[k])
			{
				dp[j][k]=1+dp[j-1][k-1];
			}
			else
			{
				dp[j][k]=0;
			}
		}
	}
	int max_len=0;
	for(int k=1;k<=n;k++)
	{
		for(int l=0;l<n-k+1;l++)
		{
			int p=k+l;
			if(dp[l][p]>max_len)
			{
				max_len=dp[l][p];
			}
		}
	}
	return max_len;
}

int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n;
		scanf("%d",&n);
		char *str=(char*)malloc(sizeof(char)*n);
		scanf("%s",str);
		int m=strlen(str);
		printf("%d\n",lnos(str,m));
	}
	return 0;
}
