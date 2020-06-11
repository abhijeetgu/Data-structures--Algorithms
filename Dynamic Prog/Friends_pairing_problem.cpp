#include<bits/stdc++.h>
using namespace std;
int dp[100];
int ways(int n)
{
    if(n==0 || n==1)
    {
        dp[n] =1;
        return 1;
    }
    if(dp[n]!=-1) return dp[n];





    dp[n] =ways(n-1)+ (n-1)*ways(n-2);
    return dp[n];
}

int main()
{
    int n;
    cin>>n;
    memset(dp,-1,sizeof dp);
    cout<<ways(n)<<endl;
    return 0;
}


