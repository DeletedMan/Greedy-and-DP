#include<stdio.h>
#include<stdlib.h>
#define R 3
#define C 6

void spiral_print(int m,int n,int arr[R][C])
{
	int k=0;
	int l=0;
	int i;
	while(k<m && l<n)
	{
		for(i=0;i<n;i++)
		{
			printf("%d ",arr[k][i]);
		}
		k++;
		for(i=k;i<m;i++)
		{
			printf("%d ",arr[i][n-1]);
		}
		n--;
		if(k<m)
		{
			for(i=n-1;i>=l;--i)
			{
				printf("%d ",arr[m-1][i]);
			}
			m--;
		}
		if(l<n)
		{
			for(i=m-1;i>=k;--i)
			{
				printf("%d ",arr[i][l]);
			}
			l++;
		}
	}
}

int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int arr[R][C];
		for(int i=0;i<R;i++)
		{
			for(int k=0;k<C;k++)
			{
				scanf("%d",&arr[i][k]);
			}
		}
		spiral_print(R,C,arr);
	}
	return 0;
}
