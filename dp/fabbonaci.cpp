#include<bits/stdc++.h>
using namespace std;

int fabs(int n,vector<int> &nums){
if(n == 0 || n ==1){
    nums.push_back(n);
    return n;
}
int temp=fabs(n-1,nums)+fabs(n-2,nums);
nums.push_back(temp);
return temp;
}


int main(){
    int n=5;
    vector<int> nums;
    auto a = fabs(n,nums);
    for(auto b:nums){
        cout<<b<<" ";
    }
}