#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int max(int a,int b)
{
	return(a>b?a:b);
}

int lps(char *str,int i,int j)
{
	if(i==j)
	{
		return 1;
	}
	if(str[i]==str[j] && i+1==j)
	{
		return 2;
	}
	if(str[i]==str[j])
	{
		return(2+lps(str,i+1,j-1));
	}
	else
	{
		return(max(lps(str,i,j-1),lps(str,i+1,j)));
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
		char* str=(char*)malloc(sizeof(char)*n);
		scanf("%s",str);
		int len=strlen(str);
		printf("%d\n",lps(str,0,len-1));
	}
	return 0;
}
