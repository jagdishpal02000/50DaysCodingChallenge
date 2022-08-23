#include<bits/stdc++.h>
using namespace std;


vector<int> NearestRightSmallestElement(vector<int> arr){
    int n = arr.size();
    vector<int> ans;
    stack<int> stack;

    for(int i=n-1; i>=0; i--){

        if(!stack.size())
            ans.push_back(-1);
       else  if(stack.top() <= arr[i])
            ans.push_back(stack.top());
        else if(stack.top() > arr[i]){
            while(stack.size() && stack.top() > arr[i]){
                stack.pop();
            }
            if(stack.size()) ans.push_back(stack.top());
            else ans.push_back(-1);
        }
        stack.push(arr[i]);

    }

    reverse(ans.begin(),ans.end());

    return ans;
}

int main(){
vector<int> arr={4,5,2,10,8};
auto ans=NearestRightSmallestElement(arr);
for(auto a : ans)
    cout<<a<<" ";


}