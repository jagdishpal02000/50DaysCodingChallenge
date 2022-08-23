#include<bits/stdc++.h>
using namespace std;

vector<int> StockSpan(vector<int> arr){
    vector<int> ans;
    int n = arr.size();
    stack<pair<int,int>> stack;

    for(int i = 0; i < n; i++){
        if(!stack.size()) ans.push_back(-1);

        else if(stack.top().first >= arr[i]){
            ans.push_back(stack.top().second);
        }
        else if(stack.top().first < arr[i]){
            while(stack.size() && stack.top().first < arr[i]){
                stack.pop();
            }
            if(stack.size()) ans.push_back(stack.top().second);
            else ans.push_back(-1);
        }

        stack.push({arr[i],i});
    }

for(int i=0;i<n;i++){
    ans[i]=i-ans[i];
}
return ans;

}


int main(){
vector<int> arr={100,80,60,70,60,75,85};
auto ans=StockSpan(arr);
for(auto a : ans)
    cout<<a<<" ";


}