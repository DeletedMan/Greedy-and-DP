#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>

void printArray(int arr[],int n)
{
	int i;
	for(i=0;i<n;i++)
	{
		printf("%d ",arr[i]);
	}
	printf("\n");
	return;
}

int compare (const void * a, const void * b)
{
  return ( *(int*)a - *(int*)b );
}

int FindPlateForm(int arr[],int dep[],int n)
{
	qsort(arr,n,sizeof(int),compare);
	qsort(dep,n,sizeof(int),compare);
	int plate_needed=1,result=1;
	int i=1,j=0;
	while(i<n && j<n)
	{
		if(arr[i]<=dep[j])
		{
			i++;
			plate_needed++;
			if(plate_needed>result)
			{
				result=plate_needed;
			}
		}
		else
		{
			plate_needed--;
			j++;
		}
	}
	return result;
}

int main()
{
	int n,m,i,j;
	scanf("%d %d",&n,&m);
	int arr[n],dep[n];
	for(i=0;i<n;i++)
	{
		scanf("%d",&arr[i]);
	}
	for(j=0;j<n;j++)
	{
		scanf("%d",&dep[j]);
	}
	printf("Arrival time of the train is:\n");
	printArray(arr,n);
	printf("Deparature time of the array is :\n");
	printArray(dep,n);
	printf("Number of the palteform is:\n");
	printf("%d ",FindPlateForm(arr,dep,n));
	return 0;
}
