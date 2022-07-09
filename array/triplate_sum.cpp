// given a array find all the triplates that contain the given
// sum
// time complexity : O(N^2).


// 1 2 3 4 5 6 7 8 9
#include<bits/stdc++.h>


using namespace std;

vector<vector<int>>  triplateSum (vector<int> arr, int target){
vector<vector<int>> result;
int n=arr.size();
sort(arr.begin(), arr.end());
for(int i=0; i<=n-3; i++){
int j=i+1;
int k=n-1;
while(j<k){
    int curr_sum = arr[i] + arr[j] +arr[k];
    if(curr_sum == target) {
        result.push_back({arr[i] ,arr[j] ,arr[k]});
        j++;
        k--;
    } 
    else if(curr_sum < target) {
        j++;
    }
    else k--;
}

}
return result;
}


int main(){
vector<int> arr{1,2,3,4,5,6,7,8,9,15};
int target = 18;
auto result = triplateSum(arr,target);
for(auto v : result){
    for(auto no : v){
        cout<<no<<',';
    }
    cout<<endl;
}
return 0;
}