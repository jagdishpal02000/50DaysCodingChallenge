#include<bits/stdc++.h>
using namespace std;

int sol(vector<int>arr,int k){
int maxSum=0;
int n = arr.size();
int currSum=0;
int i=0,j=0;
while(j<n){
    if(j-i+1 == k){
        currSum+=arr[j];
        maxSum=max(maxSum,currSum);
        currSum-=arr[i];
        i++;
        j++;
    }
    else {
        currSum+=arr[j];
        j++;
    }
}
return maxSum;
}

int main(){
vector<int>arr={3,2,4,5,1,1,1,1,2,3,3};
cout<<sol(arr,3)<<endl;
}