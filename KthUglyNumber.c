#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int min(int a,int b)
{
	return(a>b?b:a);
}

int minimum(int x,int y,int z)
{
	return(min(x,min(y,z)));
}

void printArr(int arr[])
{
	int i;
	for(i=0;i<150;i++)
	{
		printf("%d ",arr[i]);
	}
	printf("\n");
}

void UglyNumber(int n)
{
	int *arr=(int *)malloc(sizeof(int)*n);
	memset(arr,0,sizeof(arr));
	int i,j,k;
	unsigned next_multiple_of_2=2;
	unsigned next_multiple_of_3=3;
	unsigned next_multiple_of_5=5;
	unsigned next_ugly_no=1;
	i=j=k=1;
	while(i<n && j<n && k<n)
	{
		next_ugly_no=minimum(arr[i-1]*next_multiple_of_2,arr[j-1]*next_multiple_of_3,arr[k-1]*next_multiple_of_5);
		if(next_ugly_no==next_multiple_of_2*arr[i-1])
		{
			arr[i]=next_ugly_no;
			i++;
		}
		else if(next_ugly_no==next_multiple_of_3*arr[j-1])
		{
			arr[j]=next_ugly_no;
			j++;
		}
		else if(next_ugly_no==next_multiple_of_5*arr[k-1])
		{
			arr[k]=next_ugly_no;
			k++;
		}
	}
	printArr(arr);
	return;
}

int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n;
		printf("Enter the the number:\n");
		scanf("%d",&n);
		UglyNumber(n);
	}
	return 0;
}
