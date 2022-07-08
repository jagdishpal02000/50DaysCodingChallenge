// find the targeted sum in the given array.
// Assume that the array is containing only pair.
// 

#include<bits/stdc++.h>
using namespace std;  

vector<int> pairSum(vector<int> arr,int target){
unordered_set<int> s;
vector<int> result;
for(int i=0;i<arr.size();i++){
    int temp = target - arr[i];
    if(s.find(temp) != s.end()){
        result.push_back(temp);
        result.push_back(arr[i]);
        return result;
    }
    else s.insert(arr[i]);
}
return result;
}
int main(){
vector<int> testIn = {10,5,2,3,-6,9,11};
int target = 4;
auto res=pairSum(testIn,target);
if(res.size()==0){
    cout<<-1;
}
else {
    cout<<res[0]<<","<<res[1];
}

}