#include<stdlib.h>
int main() {
	//code
	int test,n;
	scanf("%d",&test);
	while(test!=0)
	{
	    test--;
	    int i=0,count=0;
	    scanf("%d",&n);
	    int *a= (int *)malloc(sizeof(int)*(n));
	    for(i=0;i<n;i++)
	    {
	        scanf("%d",&(a[i]));
	    }
	    int l=a[n-1];
	     int *b= (int *)malloc(sizeof(int)*(n));
	     b[count++]=l;
	     for(i=n-2;i>=0;i--)
	     {
	         if(a[i]>=l)
	         {
	             l=a[i];
	             b[count++]=l;
	         }
	     }
	     for(i=count-1;i>=0;i--)
	     {
	         printf("%d ",b[i]);
	     }
	     printf("\n");
	}
	return 0;
}
