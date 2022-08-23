#include<bits/stdc++.h>
using namespace std;

int MaximumAreaHistogram(vector<int> arr){
    vector<int> ans;
    int n = arr.size();
    int maxArea=INT_MIN;
    vector<int> right;
    vector<int> left;
    stack<pair<int,int>> s;
    stack<pair<int,int>> stack;
    vector<int> width(n);

for(int i=0;i<n;i++){
    if(!stack.size()) left.push_back(-1);
    else if(stack.top().first < arr[i])
        left.push_back(stack.top().second);
    else if(stack.top().first > arr[i]){
        while(stack.size() && stack.top().first > arr[i]){
            stack.pop();
        }
        if(stack.size()) left.push_back(stack.top().second);
        else left.push_back(-1);
    }
    stack.push({arr[i],i});
    }

for(int i=n-1;i>=0;i--){
    if(!s.size()) right.push_back(n);
    else if(s.top().first < arr[i]){
        right.push_back(s.top().second);
    }
    else if(s.top().first > arr[i]){
        while(s.size() && s.top().first > arr[i]){
            s.pop();
        }
        if(s.size()) right.push_back(s.top().second);
        else right.push_back(n);
    }
    s.push({arr[i],i});
}

reverse(right.begin(), right.end());

for(int i=0;i<n;i++){
    width[i]=right[i]-left[i]-1;
}

for(int i=0;i<n;i++){
maxArea=max(width[i]*arr[i],maxArea);
}


return maxArea;

}


int main(){
vector<int> arr={6,2,5,4,5,1,6};
auto ans=MaximumAreaHistogram(arr);

    cout<<ans<<" ";


}