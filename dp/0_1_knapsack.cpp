#include<bits/stdc++.h>
using namespace std;

int main(){
    vector<int> weight={2,5,1};
    vector<int> val={4,2,7};
    int n=weight.size();
    int c=2;
    int dp[n+1][c+1];
    memset(dp, -1,sizeof(dp));
    for(int i=0;i<n+1;i++){
        for(int j=0;j<c+1;j++){
            if(i==0 || j==0) 
                dp[i][j] = 0;
        }
    }

    
    for(int i=1;i<n+1;i++){
        for(int j=1;j<c+1;j++){
            if(weight[i-1]<=j){
                dp[i][j]=max(val[i-1]+dp[i-1][j-weight[i-1]],dp[i-1][j]);
            }
            else{
                dp[i][j]=dp[i-1][j];
            }
        }
    }

    cout<<dp[n][c]<<endl;

}