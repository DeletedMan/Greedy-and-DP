#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int max(int x,int y)
{
	return(x>y?x:y);
}

int lcs(char *str1,char *str2,int m,int n)
{
	int dp[m+1][n+1];
	//memset(dp,0,sizeof(dp));
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
