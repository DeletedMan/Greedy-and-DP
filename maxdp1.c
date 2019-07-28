#include<stdio.h>
#include<stdlib.h>

int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int m,n;
		scanf("%d %d",&m,&n);
		int len=m*n;
		int *arr=(int*)malloc(sizeof(int)*m*n);
		for(int i=0;i<len;i++)
		{
			scanf("%d",&arr[i]);
		}
		int k;
		scanf("%d",&k);
		int c=0;
		for(int i=0;i<len;i++)
		{
			if(arr[i]==k)
			{
				c++;
			}
		}
		if(c>=1)
		{
			printf("1");
		}
		else
		{
			printf("0");
		}
		printf("\n");
	}
	return 0;
}
