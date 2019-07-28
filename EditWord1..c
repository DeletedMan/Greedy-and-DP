#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int min(int a,int b)
{
	return(a>b?b:a);
}

int minimum(int x,int y,int z)
{
	return(min(x,min(y,z)));
}

int EditWord(char *str1,char *str2)
{
	int n=strlen(str1);
	int m=strlen(str2);
	int dp[n+1][m+1];
	memset(dp,0,sizeof(dp));
	for(int i=0;i<(n+1);i++)
	{
		for(int j=0;j<(m+1);j++)
		{
			if(i==0)
			{
				dp[i][j]=j;
			}
			if(j==0)
			{
				dp[i][j]=i;
			}
			if(str1[i-1]==str2[i-1])
			{
				dp[i][j]=dp[i-1][j-1];
			}
			else
			{
				dp[i][j]=1+minimum(dp[i-1][j-1],dp[i][j-1],dp[i-1][j]);
			}
		}
	}
	return dp[n][m];
}

int main()
{
	int t;
	printf("Enter the number of test cases#:\n");
	scanf("%d",&t);
	while(t--)
	{
		int n,m;
		scanf("%d %d",&n,&m);
		char str1[n],str2[m];
		printf("Entet the first string:\n");
		scanf("%s",str1);
		printf("Enter the second string:\n");
		scanf("%s",str2);
		printf("%d",EditWord(str1,str2));
	}
	return 0;	
}
