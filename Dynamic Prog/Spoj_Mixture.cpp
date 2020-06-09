/* https://www.spoj.com/problems/MIXTURES/
-here we used matrix multiplication concept with some changes
*/
#include <bits/stdc++.h>
using namespace std;
#define ll long long 
ll dp[1001][1001];
ll matrices[1000];
ll sum(int s,int e)
{
    ll ans=0;
    for(int i=s;i<=e;i++)
    {
        ans+= matrices[i];
        ans%=100;
    }
    return ans;
}
ll SolveMixture(int i,int j)
{
    //base case
    if(i>=j)
    {
        //dp[i][j]=0;
        return 0;
    }
    //overlapping subproblem
    if(dp[i][j]!=-1) return dp[i][j];
     dp[i][j] = INT_MAX;
    for(int k=i;k<=j;k++)
    {
        dp[i][j] = min(dp[i][j],SolveMixture(i,k)+SolveMixture(k+1,j)+sum(i,k)*sum(k+1,j));
    }
   
    return dp[i][j];
}
int main() 
{
   int n;
   while((scanf("%d",&n))!=EOF)
   {
       for(int i=0;i<n;i++)
       {
          cin>>matrices[i];
       }
       memset(dp,-1,sizeof dp);
       cout<<SolveMixture(0,n-1)<<endl;
   }
   
   
   
   
   return 0;
}
