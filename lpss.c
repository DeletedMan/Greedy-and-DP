#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<stdbool.h>

/*void printstr(char *str,int start,int max_len)
{
	int i;
	for(i=start;i<=max_len;i++)
	{
		printf("%c",*(str+i));
	}
	printf("\n");
}
*/
int lpss(char str[])
{
	int n=strlen(str);
	int table[n][n];
	//memset(table,0,sizeof(table));
	for(int i=0;i<n;i++)
	{
		table[i][i]=true;
	}
	int max_len;
	int start=0;
	for(int i=0;i<n-1;i++)
	{
		if(str[i]==str[i+1])
		{
			table[i][i+1]=true;
			start=i;
			max_len=2;
		}
	}
	for(int k=3;k<=n;++k)
	{
		for(int i=0;i<n-k+1;++i)
		{
			int j=i+k-1;
			if(table[i+1][j-1] && str[i]==str[j])
			{
				table[i][j]=true;
				if(k>max_len)
				{
					start=i;
					max_len=k;
				}
			}
			else
			{
				table[i][j]=false;
			}
		}
	}
	str[start+max_len]='\0';
	//printstr(str,start,start+max_len-1);
	return str+start;
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
		printf("%s\n",lpss(str));
	}
	return 0;
}
