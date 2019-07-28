#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int count(char *str1,char *str2)
{
	
}
int main()
{
	int n,m;
	//printf("Enter the first string:\n");
	scanf("%d %d",&n,&m);
	char str1[n],str2[m];
	printf("Enter the first string:\n");
	scanf("%s",str1);
	printf("Enter the second string:\n");
	scanf("%s",str2);
	printf("%d ",count(str1,str2));
	return 0;
}
