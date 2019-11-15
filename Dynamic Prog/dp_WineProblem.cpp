// WineProblem
#include <iostream>
using namespace std;

int WineProblem(int *wine,int i,int j,int day,int dp[][10]){
	// Base case
	if(i>j){
		dp[i][j] = 0;
		return 0;
	}
	if(dp[i][j]!=-1){
		return dp[i][j];
	}
	// Recursive case
	int op1 = wine[i]*day + WineProblem(wine,i+1,j,day+1,dp);
	int op2 = wine[j]*day + WineProblem(wine,i,j-1,day+1,dp);
	dp[i][j] = max(op1,op2);
	return max(op1,op2);
}
int BottomUp(int *wine,int n)
{
    int dp[10][10]={0};
    int year=n;

    for(int i=0;i<n;i++)
    {
        dp[i][i]=wine[i]*year;
    }
    year--;
    for(int len =2;len<=n;len++)
    {
        int s=0;
        int en=n-len;
        while(s<=en)
        {
            int endwindow=s+len-1;
            dp[s][en]=max(wine[s]*year+dp[s+1][endwindow],wine[endwindow]*year+dp[s][endwindow-1]);
            s++;

        }
        year--;
    }
    for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cout<<dp[i][j]<<" ";
		}
		cout<<endl;
	}
    return dp[0][n-1];
}

int main(){
	int wine[]={2,3,5,1,4};
	int n = 5;

	int dp[10][10]={0};
	for(int i=0;i<10;i++){
		for(int j=0;j<10;j++){
			dp[i][j] = -1;
		}
	}

	cout<<WineProblem(wine,0,n-1,1,dp)<<endl;
	cout<<BottomUp(wine,n)<<endl;
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cout<<dp[i][j]<<" ";
		}
		cout<<endl;
	}
	cout<<endl;


	return 0;
}
