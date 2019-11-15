///Bottom-UP
///Top-Down
#include<iostream>
using namespace std;

int fib(int n)
{
 int dp[1000]={};
  dp[0]=0;
  dp[1]=1;

  for(int cur_num=2;cur_num<=n;cur_num++)
  {
      dp[cur_num]=dp[cur_num-1]+dp[cur_num-2];
  }
  return dp[n];
}

int main()
{
    int n;
    cin>>n;

    cout<<n<<"th fib no is "<<fib(n);

    return 0;

}

