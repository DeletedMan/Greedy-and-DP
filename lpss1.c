#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void printArr(char *str,int start,int max_len)
{
	for(int i=start;i<=max_len;i++)
	{
		printf("%c",*(str+i));
	}
	printf("\n");
	return;
}

int lpss(char *str)
{
	int low,high;
	int max_len=0,start=0;
	int n=strlen(str);
	for(int i=1;i<n;i++)
	{
		low=i-1;
		high=i;
		while(low>=0 && high<=n-1 && str[low]==str[high])
		{
			if(high-low+1>max_len)
			{
				max_len=high-low+1;
				start=low;
			}
			low--;
			high++;
		}
		low=i-1;
		high=i+1;
		while(low>=0 && high<=n-1 && str[low]==str[high])
		{
			if(high-low+1>max_len)
			{
				max_len=high-low+1;
				start=low;
			}
			low--;
			high++;
		}
	}
	printf("Longest Palindromic substring is:\n");
	printArr(str,start,max_len);
	//str[start+max_len]='\0';
	return max_len;
}

int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n;
		scanf("%d",&n);
		char *str=(char*)malloc(sizeof(char)*n);
		scanf("%s",str);
		printf("%d\n",lpss(str));
	}
	return 0;
}
