#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int LongestEvenLengthSubstring(char *str)
{
	int n=strlen(str);
	int dp[n+1][n+1];
	memset(dp,0,sizeof(dp));
	for(int i=0;i<(n+1);i++)
	{
		dp[i][i]=*(str+i);
	}
	
}

int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n;
		scanf("%d",&n);
		char str[n];
		printf("Enter the string:\n");
		scanf("%s",str);
		printf("%d",LongestEvenLengthSubstring(str));
	}
	return 0;
}
