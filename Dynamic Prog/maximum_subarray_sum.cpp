#include<iostream>
using namespace std;

int maxsubarray(int *arr,int n)
{
    int dp[100]={0};
    dp[0] = arr[0]>0?arr[0]:0;
    int max_so_far=dp[0];
    for(int i=1;i<n;i++)
    {
        dp[i]=dp[i-1]+arr[i];
        if(dp[i]<0)
        {
            dp[i]=0;
        }
        max_so_far = max(max_so_far,dp[i]);
    }
    return max_so_far;
}
int kadane(int *arr,int n)
{
    int start;
    start = arr[0]>0?arr[0]:0;
    int max_so_far=start;
    for(int i=1;i<n;i++)
    {
        start += arr[i];
        if(start<0)
        {
            start = 0;
        }
        max_so_far = max(max_so_far,start);
    }
    return max_so_far;

}

int main()
{

    int arr[]={-3,2,5,-1,6,3,-2,7,-5,2};
    int n = sizeof(arr)/sizeof(int);
    cout<<maxsubarray(arr,n)<<endl;
    cout<<kadane(arr,n);
    return 0;
}
