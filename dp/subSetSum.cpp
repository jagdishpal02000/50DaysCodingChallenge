#include<bits/stdc++.h>

using namespace std;  

// recurtion solution :

bool isSubset(vector<int> arr, int target,int n){
    if(n == 0 && target == 0) return true;
    if(n == 0 ) return false;
    if(target == 0) return true;

    if(arr[n-1] <= target){
        return (isSubset(arr,target-arr[n-1],n-1) || isSubset(arr,target,n-1));
    } 
    else return isSubset(arr,target,n-1);
}


bool isSubsetTD(vector<int> arr, int target,int n){
    bool dp[n+1][target+1];
    for(int i=0;i<n+1;i++){
        for(int j=0;j<target+1;j++){
            if(i==0) dp[i][j] = false; 
            if(j==0) dp[i][j] = true; 
        }
    }

    for(int i=0;i<n+1;i++){
        for(int j=0;j<target+1;j++){
            if(arr[i-1] <=j){
                dp[i][j]= dp[i][j-arr[i-1]] || dp[i-1][j];
            }
            else {
                dp[i][j]=dp[i-1][j];
            }
        }
    }

    return dp[n][target];

}


int main(){

vector<int> arr={2,3,7,8,10};
int target=5;
cout<<isSubsetTD(arr,target,5)<<endl;

}