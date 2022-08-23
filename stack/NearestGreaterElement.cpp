#include<bits/stdc++.h>

using namespace std;

vector<int> NearestGreaterElement(vector<int> arr){

stack<int> stack;
vector<int> ans;
int n=arr.size();

for(int i=n-1; i>=0; i--){
if(stack.size() == 0 ){
    ans.push_back(-1);
}
else if(stack.size() > 0 && stack.top() > arr[i] ){
    ans.push_back(stack.top());
}

else if(stack.size() > 0 && stack.top() < arr[i]){
    while(stack.size() != 0 && stack.top() >= arr[i]){
        stack.pop();
    }
    if(stack.size() == 0){ans.push_back(-1);}
    else ans.push_back(stack.top());
}
    stack.push(arr[i]);

}
reverse(ans.begin(), ans.end());
return ans;
}

int main(){
vector<int> arr={ 1,3,2,4};
auto ans=NearestGreaterElement(arr);
for(auto a : ans)
    cout<<a<<" ";


}