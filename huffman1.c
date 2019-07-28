#include<stdio.h>
#include<stdlib.h>
#define Min_Heap_Size 100

struct MinHeap
{
	unsigned size;
	unsigned capacity;
   struct MinHeapNode** array;
};

struct MinHeapNode
{
	char data;
	int freq;
	struct MinHeapNode* left,*right;
};

struct MinHeap* createMinHeap(unsigned size)
{
	struct MinHeap* minHeap=(struct MinHeap*)malloc(sizeof(struct MinHeap));
	minHeap->capacity=size;
	minHeap->size=0;
	minHeap->array=(struct MinHeapNode**)malloc(sizeof(struct MinHeapNode*));
	return minHeap;
}

struct MinHeapNode* newNode(int data,int freq)
{
	struct MinHeapNode* temp=(struct MinHeapNode*)malloc(sizeof(struct MinHeapNode));
	temp->data=data;
	temp->freq=freq;
	temp->left=NULL;
	temp->right=NULL;
	return temp;
}

void swap(struct MinHeapNode** a,struct MinHeapNode** b)
{
	struct MinHeapNode* temp=*a;
	*a=*b;
	*b=temp;
}

void MinHeapify(struct MinHeap* minHeap,int index)
{
	int left=2*index+1;
	int right=2*index+2;
	int smallest=index;
	if(left<minHeap->size && minHeap->array[left]->freq < minHeap->array[index]->freq)
	{
		smallest=left;
	}
	if(right<minHeap->size && minHeap->array[right]->freq < minHeap->array[smallest]->freq)
	{
		smallest=right;
	}
	if(right!=index)
	{
		swap(&minHeap->array[index],&minHeap->array[smallest]);
		MinHeapify(minHeap,smallest);
	}
}

void buildMinHeap(struct MinHeap* minHeap)
{
	int i=minHeap->size-1;
	for(int k=(i-1)/2;k>=0;k--)
	{
		MinHeapify(minHeap,k);
	}
	return;
}

struct MinHeap* createAndBuildMinHeap(int data[],int freq[],int size)
{
	 struct MinHeap* minHeap=createMinHeap(size);
	 for(int i=0;i<size;i++)
	 {
		 minHeap->array[i]=newNode(data[i],freq[i]);
	 }
	 minHeap->size=size;
	 buildMinHeap(minHeap);
	 return(minHeap);
}

int isSizeOne(struct MinHeap* minHeap)
{
	return(minHeap->size==1);
}

int extractMin(struct MinHeap* minHeap)
{
	struct MinHeapNode* temp=minHeap->array[0];
	minHeap->array[0]=minHeap->array[minHeap->size-1];
	--minHeap->size;
	MinHeapify(temp,0);
	return temp;
}

void insert(struct MinHeap* minHeap,struct MinHeapNode* top)
{
	int i=minHeap->size-1;
	while(i && top->freq < minHeap->array[(i-1)/2]->freq)
	{
		i=(i-1)/2;
	}
	minHeap->array[i]=top;
}

struct MinHeapNode* buildHuffmanTree(int data[],int freq[],int size)
{
	struct MinHeapNode* top,*right,*left;
	struct MinHeap* minHeap=createAndBuildMinHeap(data,freq,size);
	while(!isSizeOne(minHeap))
	{
		left=extractMin(minHeap);
		right=extractMin(minHeap);
		top=newNode('$',left->freq+right->freq);
		left=top->left;
		right=top->right;
		insert(minHeap,top);
	}
	return(extractMin(minHeap));
}

void printArray(int arr[],int n)
{
	int i;
	for(i=0;i<n;i++)
	{
		printf("%d ",arr[i]);
	}
	return;
}

int isLeaf(struct MinHeapNode* root)
{
	if(!root->left && !root->right)
	{
		return 0;
	}
	else
	{
		return 1;
	}
}

void printCodes(struct MinHeapNode* root,int data[],int top)
{
	if(!root)
	{
		return;
	}
	if(!isLeaf(root))
	{
		printArray(data,top);
	}
	if(root->left)
	{
		data[top]=0;
		printCodes(root->left,data,top+1);
	}
	if(root->right)
	{
		data[top]=1;
		printCodes(root->right,data,top+1);
	}
	return;
}

void HuffmanCodes(char data[],int freq[],int size)
{
	int top=0;
	int arr[Min_Heap_Size];
	struct MinHeapNode* root=buildHuffmanTree(data,freq,size);
	printCodes(root,data,top);
	return;
}

int main()
{
	char data[]={'a','b','c','d','e','f'};
	int freq[]={5,9,12,13,16,45};
	int size=sizeof(data)/sizeof(data[0]);
	HuffmanCodes(data,freq,size);
	return 0;
}
