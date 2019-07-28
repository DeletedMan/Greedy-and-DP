#include<stdio.h>
#include<stdlib.h>

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

void swap(int *a,int *b)
{
	int temp=*a;
	*a=*b;
	*b=temp;
}

void MinHeapify(int arr[],int index,int n)
{
	int l=2*index+1;
	int r=2*index+2;
	int smallest=index;
	if(l<n && arr[l]<arr[index])
	{
		smallest=l;
	}
	if(r<n && arr[r]<arr[smallest])
	{
		smallest=r;
	}
	if(smallest!=index)
	{
		swap(&arr[index],&arr[smallest]);
		MinHeapify(arr,smallest,n);
	}
	return;
}

int extract_min(int arr[],int n)
{
	int temp=arr[0];
	arr[0]=arr[n-1];
	--n;
	MinHeapify(arr,0,n);
	return temp;
}

void insert(int arr[],int cost,int n)
{
	++n;
	int i=n-1;
	while(i && cost<arr[(i-1)/2])
	{
		arr[i]=arr[(i-1)/2];
		i=(i-1)/2;
	}
	arr[i]=cost;
}

int MinRopeCost(int arr[],int n)
{
	int i;
	for(i=(n/2)-1;i>=0;--i)
	{
		MinHeapify(arr,i,n);
	}
	int cost=0;
	while(n>1)
	{
		int first_min=extract_min(arr,n);
		int sec_min=extract_min(arr,n);
		cost+=(first_min+sec_min);
		insert(arr,first_min+sec_min,n);
	}
	return cost;
}

int main()
{
	int n,i;
	scanf("%d",&n);
	int arr[n];
	for(i=0;i<n;i++)
	{
		scanf("%d",&arr[i]);
	}
	printArray(arr,n);
	printf("Min Cost of the rope should be:\n");
	printf("%d ",MinRopeCost(arr,n));
	return 0;
}
