/*#include<stdio.h>
#include<stdlib.h>
#include<math.h>
/*
int isSubsetSetSum(int arr[],int n,int sum)
{
	if(sum!=0 && n==0)
	{
		return 0;
	}
	if(sum==0)
	{
		return 1;
	}
	if(arr[n-1]>sum)
	{
		isSubsetSetSum(arr,n-1,sum);
	}
	return(isSubsetSetSum(arr,n-1,sum) || isSubsetSetSum(arr,n-1,sum-arr[n-1]));
}
*/
/*
int isSubSetSum(int arr[],int n,int s)
{
	int dp[n+1][s+1];
	int i,j;
	for(i=0;i<=n;i++)
	{
		for(j=0;j<=n;j++)
		{
			dp[i][j]=0;
		}
	}
	for(i=0;i<=s;i++)
	{
		dp[0][i]=0;
	}
	for(i=0;i<=n;i++)
	{
		dp[i][0]=1;
	}
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=s;j++)
		{
			if(arr[i-1]>j)
			{
				dp[i][j]=dp[i-1][j];
			}
			if(j>=arr[i-1])
			{
				dp[i][j]=dp[i-1][j] || dp[i-1][j-arr[i-1]];
			}
		}
	}
	return dp[n][s];
}

int main()
{
	long int t,n,sum;
	scanf("%ld",&t);
	while(t--)
	{
		scanf("%ld",&n);
		int arr[n];
		for(int i=0;i<n;i++)
		{
			scanf("%d",&arr[i]);
		}
		scanf("%ld",&sum);
		if(isSubSetSum(arr,n,sum)==1)
		{
			printf("Yes Found!");
		}
		else
		{
			printf("No");
		}
		printf("\n");
	}
	return 0;
}*/
#include<stdio.h>
#include<stdlib.h>
/*
int isSubSetSum(int arr[],int n,int sum)
{
	if(sum==0)
	{
		return 1;
	}
	if(sum>0 && n==0)
	{
		return 0;
	}
	if(arr[n-1]>sum)
	{
		isSubSetSum(arr,n-1,sum);
	}
	else
	{
		return(isSubSetSum(arr,n-1,sum) || isSubSetSum(arr,n-1,sum-arr[n-1]));
	}
} */
#include<stdio.h>
#include<stdlib.h>

int dp[5000][5000];
int isSubSetSum(int arr[],int s,int n)
{
	//int dp[n+1][s+1];
	int i,j;
	/*for(i=0;i<=n;i++)
	{
		for(j=0;j<=n;j++)
		{
			dp[i][j]=0;
		}
	}*/
	for(i=0;i<=s;i++)
	{
		dp[0][i]=0;
	}
	for(i=0;i<=n;i++)
	{
		dp[i][0]=1;
	}
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=s;j++)
		{
			if(arr[i-1]>j)
			{
				dp[i][j]=dp[i-1][j];
			}
			if(j>=arr[i-1])
			{
				dp[i][j]=dp[i-1][j] || dp[i-1][j-arr[i-1]];
			}
		}
	}
	if(dp[n][s])
	{
		printf("YES\n");
	}
	else
	{
		printf("NO\n");
	}
}
void findSubsetSum(int arr[],int n)
{
	int sum=0;
	if(n==1)
	{
		printf("NO\n");
		return;
	}
	for(int i=0;i<n;i++)
	{
		sum+=arr[i];
	}
	if(sum%2==1)
	{
		printf("NO\n");
	}
	else
	{
		isSubSetSum(arr,sum/2,n);
	}
}
int main() 
{
	//code
	int t;
	
	scanf("%d",&t);
	
	while(t--)
	{
	    int n;
	    
	    scanf("%d",&n);
	    
	    int arr[n];
	    
	    for(int i=0;i<n;i++)
	    {
	       scanf("%d",&arr[i]); 
	    }
	    
	    findSubsetSum(arr,n);
	}
	return 0;
}
