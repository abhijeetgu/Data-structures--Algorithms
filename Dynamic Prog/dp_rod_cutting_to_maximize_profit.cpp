#include<iostream>
using namespace std;

int memo[100];
///top-down
int maxProfit(int arr[], int totalLen)
{
    if(totalLen == 0) return 0;

    if(memo[totalLen] != -1)
    {
        return memo[totalLen];
    }

    int best = 0;
    for(int len = 1;len <= totalLen; len++)
    {
        int netProfit= arr[len] + maxProfit(arr, totalLen-len);
        best= max(best, netProfit);
    }
    memo[totalLen] = best;
    return best;
}
///bottom-up

int maxProfit_bu(int arr[], int totalLen)
{
    int dp[100] = {};

    for(int len = 1;len <= totalLen; len++)
    {
        int best =0;
        for(int cut =1;cut <= len; ++cut)
        {
            best = max(best, arr[cut] + dp[len - cut]);
        }
        dp[len] =best;
    }
    return dp[totalLen];
}

int main()
{
    int priceofEachLen[100];
    int totalLen;
    cin>>totalLen;

    for(int eachPiece = 1; eachPiece<=totalLen; eachPiece++)
    {
        cin>> priceofEachLen[eachPiece];
    }

    //reset memopad

    for(int i=0;i <= totalLen; ++i)
    {
        memo[i]= -1;
    }

    int ans = maxProfit(priceofEachLen, totalLen);
    cout<< ans<<endl;

    cout<<maxProfit_bu(priceofEachLen,totalLen);

    return 0;
}
