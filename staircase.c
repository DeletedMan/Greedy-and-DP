#include<stdio.h>
#include<stdlib.h>

int PossibleWay(int n)
{
	if(n==1 || n==2)
	{
		return n;
	}
	return(PossibleWay(n-1)+PossibleWay(n-2));
}

int main()
{
	int t,n;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		printf("%d \n",PossibleWay(n));
	}
	return 0;
}
