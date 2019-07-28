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
		int a,b;
		scanf("%d %d",&a,&b);
		char *str1=(char*)malloc(sizeof(char)*a);
		char *str2=(char*)malloc(sizeof(char)*b);
		scanf("%s",str1);
		scanf("%s",str2);
		int m=strlen(str1);
		int n=strlen(str2);
		int ans=lcs(str1,str2,m,n);
		printf("%d\n",ans);
	}
	return 0;
}
