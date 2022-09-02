#include<bits/stdc++.h>

using namespace std;

vector<int> sol(vector<int> arr, int k){
int i=0;
int j=0;
queue<int> q;
vector<int> ans;
while(j<arr.size()){
    if(j-i+1==k){
    if(arr[j]<0) q.push(arr[j]);
    if(q.size()==0) ans.push_back(0);
    else {
        ans.push_back(q.front());
    } 
    if(q.front() == arr[i]){
        q.pop();
    }
    i++;
    j++;
    }

    else{
        if(arr[j]<0) q.push(arr[j]);
        j++;
    }
}
return ans;
}

int main(){
vector<int> arr= {-8, 2, 3, -6, 10};
int k=2;
for(auto a:sol(arr, k)){
    cout<<a<<" ";
}
}