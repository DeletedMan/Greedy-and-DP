#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int min(int x,int y)
{
	return(x<y?x:y);
}
int minimum(int x,int y,int z)
{
	return(min(x,min(y,z)));
}
int EditWord(char *str1,char *str2,int n,int m)
{
	if(n==0)
	{
		return m;
	}
	if(m==0)
	{
		return n;
	}
	if(str1[n-1]==str2[m-1])
	{
		return(EditWord(str1,str2,n-1,m-1));
	}
	return(1+minimum(EditWord(str1,str2,n-1,m-1),EditWord(str1,str2,n-1,m),EditWord(str1,str2,n,m-1)));
}

int main()
{
	int n,m;
	scanf("%d %d",&n,&m);
	char str1[n],str2[m];
	scanf("%s",str1);
	scanf("%s",str2);
	printf("%d ",EditWord(str1,str2,n,m));
	return 0;
}
