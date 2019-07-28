#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int max(int a,int b)
{
	return(a>b?a:b);
}
long long int MaxDotProduct(int A[],int B[],int m,int n) 
{ 
	long long int dp[n+1][m+1]; 
	memset(dp, 0, sizeof(dp)); 
	for (int i=1; i<=n; i++) 
		for (int j=i; j<=m; j++) 
			dp[i][j] = max((dp[i-1][j-1] + (A[j-1]*B[i-1])) , 
							dp[i][j-1]); 
	return dp[n][m] ; 
} 
int main() 
{ 
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int m,n;
		scanf("%d %d",&m,&n);
		int A[m],B[n];
		for(int i=0;i<m;i++)
		{
			scanf("%d",&A[i]);
		}
		for(int j=0;j<n;j++)
		{
			scanf("%d",&B[j]);
		}
	   printf("%lld\n",MaxDotProduct(A, B, m, n)); 
   }
	return 0; 
}
