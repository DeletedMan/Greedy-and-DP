#include<stdio.h>
#include<stdlib.h>

int found(int *arr,int r,int c,int x)
{
    int i=0,j=c-1;
    if(r==0 || c==0)
    {
		return 0;
	}
	if(x<*((arr+0)+0) || x>*((arr+r-1)+c-1))
	{
		return 0;
	}
    while(i<r && j>=0)
    {
        if(*((arr+i)+j)==x)
        {
            return 1;
            break;
        }
        if(*((arr+i)+j)>x)
        {
			j--;
		}
		else
		{
			i++;
		}
    }
    return 0;
}

int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int r,c;
        scanf("%d %d",&r,&c);
        int arr[r][c];
        for(int i=0;i<r;i++)
        {
            for(int j=0;j<c;j++)
            {
                scanf("%d",&arr[i][j]);
            }
        }
        int k;
        scanf("%d",&k);
        if(found(arr,r,c,k))
        {
            printf("1\n");
        }
        else
        {
            printf("0\n");
        }
    }
    return 0;
}
