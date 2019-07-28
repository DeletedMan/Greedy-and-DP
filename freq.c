#include<stdio.h>
#include<stdlib.h>
#define freq 26

void printArray(int bucket[])
{
	int i;
	for(i=0;i<freq;i++)
	{
		printf("%d ",bucket[i]);
	}
	return;
}
void  buckets(char str[],int n)
{
	int i,k,j;
	int bucket[freq];
	for(j=0;j<freq;j++)
	{
		bucket[j]=0;
	}
	for(i=0;i<n;i++)
	{
		++bucket[str[i]];
	}
	printArray(bucket);
	return;
}

int main()
{
	int n;
	scanf("%d",&n);
	char str[n];
	printf("Enter the string:\n");
	scanf("%s",str);
	buckets(str,n);
	return 0;
}
