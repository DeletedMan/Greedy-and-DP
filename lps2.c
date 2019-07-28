#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int max(int a,int b)
{
	return(a>b?a:b);
}
//Be crazy like unstoppable man........
int lps(char *str,int n)
{
	int dp[n+1][n+1];
	for(int i=0;i<=n;i++)
	{
		dp[i][i]=1;
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=0;j<n-i+1;j++)
		{
			int k=i+j;
			if(str[j]==str[k])
			{
				dp[j][k]=2+dp[j+1][k-1];
			}
			else
			{
				dp[j][k]=max(dp[j][k-1],dp[j+1][k]);
			}
		}
	}
	return dp[0][n];
}

int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n;
		scanf("%d",&n);
		char* str=(char*)malloc(sizeof(char)*n);
		scanf("%s",str);
		int len=strlen(str);
		printf("%d\n",lps(str,len));
	}
	return 0;
}

