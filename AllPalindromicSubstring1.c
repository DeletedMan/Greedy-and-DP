#include<stdio.h>
#include<string.h>

int isPalindrome(char *str,int i,int j)
{
	int k,l;
	for(k=i,l=j;k<=l;k++,l--)
	{
		if(str[k]!=str[l])
		{
			return 0;
			break;
		}
	}
	return 1;
}

int AllPalindromicSubstring(char *str,int n)
{
	int p[n][n];
	int boolean[n][n];
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			if(i==j)
			{
				boolean[i][j]=1;
			}
			else if(i<=j)
			{
				if(j-i==1)
				{
					if(str[i]!=str[j])
					{
						boolean[i][j]=0;
					}
					else
					{
						boolean[i][j]=1;
					}
				}
				else
				{
					if(isPalindrome(str,i,j))
					{
						boolean[i][j]=1;
					}
					else
					{
						boolean[i][j]=0;
					}
				}
			}
		}
	}
	int k,l;
	for(k=0;k<n;k++)
	{
		for(l=0;l<n;l++)
		{
			if(k==l)
			{
				p[k][l]=1;
			}
			else if(k<=l)
			{
				if(l-k==1)
				{
					if(str[k]!=str[l])
					{
						p[k][l]=2;
					}
					else
					{
						p[k][l]=3;
					}
				}
			}
			else
			{
				if(boolean[k][l]==1)
				{
					p[k][l]=1+p[k][l-1]+p[k+1][l]-p[k+1][l-1];
				}
				else
				{
					p[k][l]=p[k][l-1]+p[k+1][l]-p[k+1][l-1];
				}
			}
		}
	}
	return (p[0][n-1]);
}

int main()
{
	int t;
	printf("Enter the number of the test case #:\n");
	scanf("%d",&t);
	while(t--)
	{
		int n;
		scanf("%d",&n);
		char str[n];
		scanf("%s",str);
		printf("%d ",AllPalindromicSubstring(str,n));
	}
	return 0;
}
