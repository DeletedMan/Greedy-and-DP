#include<stdio.h>
#include<string.h>
#include<stdlib.h>


char *reverse(char* str,int m)
{
	char swap;
	int i;
	for(i=0;i<m/2;i++)
	{
		swap=*(str+i);
		*(str+i)=*(str+m-1-i);
		*(str+m-1-i)=swap;
	}
	return str;
}

int main()
{
    int n;
    scanf("%d",&n);
    char *str=(char*)malloc(sizeof(char)*n);
    scanf("%s",str);
    int len=strlen(str);
    char* str1=reverse(str,len);
    printf("%s",str1);
    return 0;
}
