#include<bits/stdc++.h>

using namespace std;

int LCSRecursion(string x,string y,int n,int m){
    if( !n || !m) return 0;
    if(x[n-1] == y[m-1])
        return 1 + LCSRecursion(x,y,n-1,m-1);
    else  return max(LCSRecursion(x,y,n,m-1),LCSRecursion(x,y,n-1,m));
}

string LCSTopDown(string x,string y,int n,int m){
    int dp[n+1][m+1];
    for(int i=0;i<n+1;i++){
        for(int j=0;j<m+1;j++){
            if( !i || !j ) dp[i][j] = 0;
        }
    }
    
    for(int i=1;i<n+1;i++){
        for(int j=1;j<m+1;j++){
            if(x[i-1] == y[j-1]){
                dp[i][j] = 1 + dp[i-1][j-1];
            }
            else {
                dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
            }
        }
    }
    
    for(int i=0;i<n+1;i++){
        for(int j=0;j<m+1;j++){
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }


    string lcs="";
    for(int i=n;i>=1;){
        for(int j=m;j>=1;){
            if(x[i-1] == y[j-1]){
                    lcs+=x[i-1];
                    i--;
                    j--;
            }
            else{
                if(dp[i-1][j] > dp[i][j-1]){
                    i--;
                }
                else
                j--;
            }
        }
    }
    reverse(lcs.begin(), lcs.end());
    return lcs;
}

int main(){
    string  x="abac";
    string y="cab";
    cout<<LCSTopDown(x,y,x.size(),y.size())<<endl;
}
