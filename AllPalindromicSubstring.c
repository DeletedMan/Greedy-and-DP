#include<stdio.h>
#include<string.h>

int isPalindrome(char *str)
{
	int i,j;
	for(i=0,j=strlen(str)-1;i<j;i++,j--)
	{
		if(str[i]!=str[j])
		{
			return 0;
			break;
		}
	}
	return 1;
}

int AllPalindromicSubstring(char *str,int i,int j)
{
	if(j==i+1)
	{
		return str[i]==str[j];
	}
	if(isPalindrome(str))
	{
		return(1+AllPalindromicSubstring(str,i,j-1)+AllPalindromicSubstring(str,i+1,j)-AllPalindromicSubstring(str,i+1,j-1));
	}
	else
	{
		return(AllPalindromicSubstring(str,i,j-1)+AllPalindromicSubstring(str,i+1,j)-AllPalindromicSubstring(str,i+1,j-1));
	}
}

int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n;
		scanf("%d",&n);
		char str[n];
		scanf("%s",str);
		int i=0,j=n-1;
		printf("%d ",AllPalindromicSubstring(str,i,j));
	}
	return 0;
}
