#include<bits/stdc++.h>
using namespace std;

int lcs(char x[],char y[])
{
    int m = strlen(x);
    int n = strlen(y);
    int dp[100][100];

    for(int i=0;i<=m;i++) dp[i][0]=0;
    for(int j=0;j<=n;j++) dp[0][j]=0;

    for(int i=1;i<=m;i++)
    {
        for(int j=1;j<=n;j++)
        {
            int ans=0;
            if(x[i-1]==y[j-1])
            {
                 ans = 1+dp[i-1][j-1];
            }
            else
            {
                ans = max(dp[i-1][j],dp[i][j-1]);
            }
            dp[i][j]=ans;
        }
    }
    return dp[m][n];
}
int main()
{
    char str1[100],str2[100];
    cin>>str1>>str2;
    int ans = lcs(str1,str2);
    cout<<ans;

    return 0;
}
