#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int max(int a,int b)
{
	return(a>b?a:b);
}

int lcs(char *str1,char* str2,int m,int n)
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
			else if(str1[i-1]==str2[j-1])
			{
				dp[i][j]=1+dp[i-1][j-1];
			}
			else
			{
				dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
			}
		}
	}
	return dp[m][n];
}

int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n,m;
		scanf("%d %d",&m,&n);
		char *str1=(char*)malloc(sizeof(char)*m);
		char *str2=(char*)malloc(sizeof(char)*n);
		scanf("%s",str1);
		scanf("%s",str2);
		int m1=strlen(str1);
		int n1=strlen(str2);
		int len=lcs(str1,str2,m1,n1);
		int cost1,cost2;
		scanf("%d %d",&cost1,&cost2);
		int required_min_cost=cost1*(m1-len)+cost2*(n1-len);
		printf("%d ",required_min_cost);
	}
	return 0;
}
