#include<iostream>
using namespace std;

int list(int arr[100], int n)
{
    int dp[100];

    //base case
    for(int i=0;i < n;++i) dp[i] = 1;

    int best = -1;

    for(int i = 1;i <n;++i)
    {
        for(int j = 0;j < i; j++)
        {
            if(arr[j] <= arr[i])
            {
                //jth element can be absorbed by i
                int curLen = 1+dp[j];
                dp[i] = max(curLen, dp[i]);
            }

        }
        best = max(best, dp[i]);
    }
    for(int i = 0;i < n; i++) cout<<dp[i]<<" ";

    cout<<endl;
    return best;
}

int main()
{
    int arr[100];
    int n;
    cin>>n;

    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }


    cout<< list(arr,n);
    return 0;
}
/*
input:
10
10 22 9 33 21 50 41 60 80 6

*/


