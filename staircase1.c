#include<stdio.h>
#include<stdlib.h>
#include<math.h>
/*
int PossibleWay(int n)
{
	unsigned long dp[100001];
	dp[0]=1;
	dp[1]=2;
	for(int i=2;i<=100001;i++)
	{
		dp[i]=(dp[i-1]%1000000007+dp[i-2]%1000000007)%1000000007;
	}
	return dp[n+1]%1000000007;
}

int main()
{
	int t,n;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		printf("%d \n",PossibleWay(n));
	}
	return 0;
}

*/

int main() 
{
	int t,n;
	scanf("%d",&t);
	unsigned long  a[100001];
        a[0]=1;
        a[1]=2;
        for(int i=2;i<=100000;i++)
          a[i]=(a[i-1]%1000000007+a[i-2]%1000000007)%1000000007;
	while(t>0)
	{
	    scanf("%d",&n);
	    printf("%lu\n",a[n-1]);
	    t--;
	}
	return 0;
}
