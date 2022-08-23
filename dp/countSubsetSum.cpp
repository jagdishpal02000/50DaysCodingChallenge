#include<bits/stdc++.h>

using namespace std;

int countSubsetSum(vector<int> arr,int target,int n){
    if(target == 0 & n ==0 ) return 1;
    if(target == 0) return 1;
    if(n == 0) return 0;

    if(arr[n-1] <= target){
        return (countSubsetSum(arr,target-arr[n-1],n-1) + countSubsetSum(arr,target,n-1));
    }
    else return countSubsetSum(arr,target,n-1);
}

int main(){
    vector<int> arr ={2,3,5,6,8,10};
    cout<<countSubsetSum(arr,10,arr.size());
}