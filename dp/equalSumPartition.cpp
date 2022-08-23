#include<bits/stdc++.h>
using namespace std;

bool subSetSum(vector<int> arr, int sum,int n){
    if(n ==0 && sum == 0) return true;
    if(sum == 0) return true;
    if(n == 0 ) return false;

    if(arr[n-1] <=  sum) {
        return (subSetSum(arr,sum-arr[n-1],n-1) || subSetSum(arr,sum,n-1)); 
    }
    else return subSetSum(arr,sum,n-1);
}

bool equalSumPartition(vector<int> arr){
int sum=0;
for(auto x : arr)
sum+=x;
if(sum % 2 != 0) return false;
return subSetSum(arr,sum/2,arr.size());
}

int main(){
    vector<int> arr = {1,5,11,5,1};
    cout<<equalSumPartition(arr)<<endl;
}