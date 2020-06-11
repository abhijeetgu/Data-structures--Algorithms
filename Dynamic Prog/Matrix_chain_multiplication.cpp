#include<bits/stdc++.h>
using namespace std;
//bottomup
int dp[100][100];
int MatrixChain(int m[],int i,int j)
{
    //base case
    if(i==j)
    {
        dp[i][j]=0;
        return 0;
    }
    //overlapping subproblem
    if(dp[i][j]!=-1) return dp[i][j];
    int ans = INT_MAX;
    for(int k=i;k<j;k++)
    {
        int temp = MatrixChain(m,i,k) + MatrixChain(m,k+1,j) + m[i-1]*m[k]*m[j];
        ans = min(ans,temp);
    }
    dp[i][j] = ans;
    return ans;
}
int MatrixBottomup(int m[],int n)
{

    int dp[100][100];


    //Make Diagonal Element zero
    for(int i=1;i<n;i++)
    {
        dp[i][i]=0;
    }

    for(int l =2;l<n;l++)
    {
        for(int i=1;i<=n-l;i++)
        {
            int j=i+l-1;
            dp[i][j]=INT_MAX;
            for(int k=i;k<j;k++)
            {
                dp[i][j] = min(dp[i][j],dp[i][k]+dp[k+1][j]+m[i-1]*m[k]*m[j]);
            }
        }
    }
    return dp[1][n-1];
}

int main()
{

    int matrices[] = {1,2,3,4};
    int n = sizeof(matrices)/sizeof(int);
    memset(dp,-1,sizeof dp);
    cout<<MatrixChain(matrices,1,n-1)<<endl;

    for(int i=1;i<n;i++)
    {

        for(int j=1;j<n;j++)
        {

            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<"Bottom up MatixChain Multiplication "<<MatrixBottomup(matrices,n);
    return 0;
}

