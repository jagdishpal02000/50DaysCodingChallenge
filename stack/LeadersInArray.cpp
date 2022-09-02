#include<bits/stdc++.h>
using namespace std;

vector<int> leaders(int arr[], int n){
        // Code here
        // let's find the nearest right greater elements index ?
        stack<int> stack;
        vector<int> ans;
        for(int i=n-1;i>=0;i--){
            cout<<i<<" ";
            if(!stack.size()){
                ans.push_back(arr[i]);
            }
            else if(stack.top() <= arr[i])
            {
                while(stack.size() && stack.top() < arr[i]){
                    stack.pop();
                }
                if(!stack.size()) ans.push_back(arr[i]);
            }
            stack.push(arr[i]);
        }
        reverse(ans.begin(),ans.end());
        return ans;
        
    }

int main(){
    int arr[]={16,17,4,3,5,2};
    int n=sizeof(arr)/sizeof(arr[0]);
    auto ans=leaders(arr,n);
    for(auto a:ans){
        cout<<a<<" ";
    }
}