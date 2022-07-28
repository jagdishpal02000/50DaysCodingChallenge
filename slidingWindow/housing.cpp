// return all the subarray indecies whoese sum is exactly same as target
// first approch will be brootforce O(N^3).
// second approch will be using prefix sum with O(N^2).
// third approch will be using window with O(NlogN).
// fourth approch will be using sliding window witn O(N).


#include<bits/stdc++.h>

using namespace std;


//Brootforce Approch.
vector<vector<int>> possibleIndcies(vector<int>arr,int target){
vector<vector<int>> subArrays;
// first found all the possible subArray : 
for(int i=0;i<arr.size();i++){
    for(int j=i;j<arr.size();j++){
        int sum=0;
        for(int k=i;k<=j; k++){
            sum+=arr[k];
        }
            cout<<endl;
            if(sum == target) subArrays.push_back({i,j});
    }
}
return subArrays;
}


//prefix sum approch.
vector<vector<int>> possibleIndciesII(vector<int>arr,int target){
    vector<vector<int>> ans;
    vector<int> prefixSum;
    for(int i=0;i<arr.size();i++){
        if(i==0) prefixSum.push_back(arr[i]);
        else prefixSum.push_back(arr[i]+prefixSum[i-1]);
    }

    for(int i=0;i<prefixSum.size();i++){
        
    }
}

int main(){
vector<int> areas={1,3,2,1,4,1,3,2,1,1,2};
int target=8;
vector<vector<int>> ans= possibleIndcies(areas,target);



for(auto a :ans ){
    for(auto b : a){
        cout<<b<<" ";
    }
    cout<<endl;
}

}