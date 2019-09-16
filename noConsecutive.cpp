#include<iostream>
#include<bits/stdc++.h>
#include<stack>
#include<set>
#include<map>
#include<list>
#include<algorithm>

using namespace std;

int noconsecutive_1(int n)
{
    int fib[n+1];
    fib[0]=0;
    fib[1]=2;
    fib[2]=3;
    for(int i=3;i<=n;i++)
    {
        fib[i]=(fib[i-2]%1000000007+fib[i-1]%1000000007)%1000000007;
    }
    return fib[n];
}

int main()
{
    int test;
    std::cin>>test;
    while(test--)
    {
        int n;
        std::cin>>n;
        std::cout<<noconsecutive_1(n)<<endl;
    }
    return 0;
}
